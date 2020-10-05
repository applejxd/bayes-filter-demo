/**
 * Define viewer by OpenCV
 * @file viewer.h
 * Copyright 2020 @applejxd
 */
#ifndef SRC_INCLUDE_VIEWER_H_
#define SRC_INCLUDE_VIEWER_H_

#include <array>
#include "./types.h"
#include "opencv2/highgui.hpp"
#include "opencv2/video/tracking.hpp"

namespace viewer {

using std::array;
using cv::Point;
using cv::Scalar;
using types::CanonVar;

class Viewer {
 public:
  Viewer();
  inline void Clear() { this->canvas = Scalar::all(0); }
  void DrawCross(const Point&, const Scalar&, double);
  void DrawLine(const Point&, const Point&, const Scalar&, double);
  void DrawPendulum(const CanonVar&, const array<double, 2>&);

 private:
  /** window size */
  const int window_size{500};
  /** Viewer window */
  cv::Mat canvas;
};

}  // namespace viewer

#endif  // SRC_INCLUDE_VIEWER_H_
