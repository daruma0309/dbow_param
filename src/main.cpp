#include "myUtil.h"

void run_dbow(string filename, int image_num) {
  Vocabulary voc("./orbvoc.dbow3");
  Database db(voc, false, 0);

  cv::Ptr<cv::Feature2D> fdetector = ORB::create();

  int no_matching_image_num = 200;

  map<size_t, size_t> retHistory;

  // ループが発生しない最初の画像を数枚追加
  cout << "adding initial images" << endl;
  for (int i=1; i<no_matching_image_num; i++) {
    std::vector<cv::KeyPoint> keypoints;
    cv::Mat descriptors;
    Mat image = read_image(filename, i);
    fdetector->detectAndCompute(image, cv::Mat(), keypoints, descriptors);
    db.add(descriptors);
  }

  // 類似画像を
  for (int i=no_matching_image_num; i<=image_num; i++) {
    std::vector<cv::KeyPoint> keypoints;
    cv::Mat descriptors;
    Mat image = read_image(filename, i);
    fdetector->detectAndCompute(image, cv::Mat(), keypoints, descriptors);

    QueryResults ret;
    db.query(descriptors, ret, 0, -1);
    //cout << "[DEBUG] i = " << i << ", ret.size() = " << ret.size() << endl;

    //cout << "image" << i << ".jpg :" << endl;
    //cout << ret << endl;

    db.normalizeScore(ret, ret.size()-1); // スコアの正規化

    // best_idx：ret.Idの値
    size_t best_idx_vector; // スコア最大のretのindex
    size_t best_idx = db.searchBest(ret, i-no_matching_image_num, best_idx_vector);
    if(ret[best_idx_vector].Score_normalized >= 0.2) // alpha=0.2
      // 正規化したスコアがalpha以上なら
    {
      // GroupScoreを計算 中央のidx(retのindex)を保存
      retHistory[i] = db.matchGrouping(ret, best_idx_vector);

      if(true == db.temporalConsistency(retHistory, i, 1, 10, 3))
        // 過去k=3枚の画像でマッチングがされていて、id_centerの距離が10以下
      {
        size_t loop_image_idx = retHistory[i];
        //flag = true;

        cout << i  << "passed." << endl;
        cout << i  << ":" << best_idx << endl;

      /*
        if(true == db.geometricalConsistency(ret))
          // 基礎行列が計算できるなら
        {
          cout << "detected loop!" << endl;
        }
        */
      }
    }

    db.add(descriptors);
  }

  return;
}

int main( int argc, char** argv )	{
  if (argc != 3) {
    cout << "[Usage] ./dbow3_param [filename] [image_num]" << endl;
    return 0;
  }
  string filename = argv[1];
  int image_num = atoi(argv[2]);

  run_dbow(filename, image_num);

  cout << "End." << endl;
  return 0;
}
