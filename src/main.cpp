#include "myUtil.h"

/*
std::map<size_t, size_t> retHistory;
cv::Ptr<cv::Feature2D> fdetector;
std::vector<cv::Mat> features;
*/
void run_dbow(string filename, int image_num) {
  Vocabulary voc("./orbvoc.dbow3");
  Database db(voc, false, 0);

  for (int i=1; i<=image_num; i++) {
    Mat image = read_image(filename, i);
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
