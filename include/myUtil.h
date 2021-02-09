#ifndef MY_UTIL_H_
#define MY_UTIL_H_

#include <opencv2/opencv.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/core.hpp>

#include <DBoW3/DBoW3.h>

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
using namespace DBoW3;

Mat read_image(string filename_dir, int index) {
  // 画像を読み込む
  ostringstream oss;
  oss << index;
  string filename = filename_dir + oss.str() + ".jpg";
  Mat image = cv::imread(filename, cv::IMREAD_UNCHANGED);

  if (image.empty() == true) { // 画像が読み込めなくなったら
    cout << "no image." << endl;
  }

  return image;
}

#endif
