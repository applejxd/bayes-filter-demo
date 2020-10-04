/**
 * Define viewer by OpenCV
 * @file viewer.h
 * Copyright 2020 @applejxd
 */ 
#ifndef SRC_INCLUDE_VIEWER_H_
#define SRC_INCLUDE_VIEWER_H_

#include "opencv2/highgui.hpp"
#include "opencv2/video/tracking.hpp"

namespace viewer {

class Viewer {
 public:
  Viewer(void);

 private:
  cv::Mat canvas;
};

}  // namespace viewer

#endif  // SRC_INCLUDE_VIEWER_H_
