#include <opencv2/opencv.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/core.hpp>

#include <iostream>
#include <ctype.h>
#include <algorithm> // for copy
#include <iterator> // for ostream_iterator
#include <vector>
#include <ctime>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>

using namespace cv;
using namespace std;

Mat read_image(string filename_dir, int index) {
  // 画像を読み込む
  string filename;
  ostringstream oss;
  oss << index;
  filename = filename_dir + oss.str() + ".jpg";
  image = cv::imread(filename, cv::IMREAD_UNCHANGED);

  if (image.empty() == true) { // 画像が読み込めなくなったら
    cout << "no image." << endl;
  }

  return image;
}
