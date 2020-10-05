// Copyright 2020 @applejxd
#include "./include/viewer.h"

#include <array>

namespace viewer {

using std::array;

Viewer::Viewer() : canvas(window_size, window_size, CV_8UC3) {}

/** Draw a point by a small cross mark
 * @param center Position of the poin
 * @param color Color of the cross mark
 * @param d Size of cross mark
 */
void Viewer::DrawCross(const Point& center, const Scalar& color, double d) {
  cv::line(this->canvas, Point(center.x - d, center.y - d),
           Point(center.x + d, center.y + d), color, 1, cv::LINE_AA, 0);
  cv::line(this->canvas, Point(center.x + d, center.y - d),
           Point(center.x - d, center.y + d), color, 1, cv::LINE_AA, 0);
}

/** Draw a line.
 * @param start_pt Start point of the line
 * @param end_pt End point of the line
 * @param color Color of the line
 * @param d Thickness of the line
 */
void Viewer::DrawLine(const Point& start_pt, const Point& end_pt,
                      const Scalar& color, double d) {
  cv::line(this->canvas, start_pt, end_pt, color, d, cv::LINE_AA, 0);
}

/** Draw double pendulum
 * @param var State of double pendulum
 * @param length Total length of strings of double pendulum
 */
void Viewer::DrawPendulum(const CanonVar& var, const array<double, 2>& length) {
  double scale = 0.8 * 0.5 * this->window_size / (length[0] + length[1]);

  // 左上が本来の原点
  Point origin(this->window_size * 0.5, this->window_size * 0.5);
  // 下方向に y 軸, 右方向に x 軸
  Point weight1(origin.x + scale * length[0] * sin(var.theta1),
                origin.y + scale * length[0] * cos(var.theta1));
  Point weight2(weight1.x + scale * length[1] * sin(var.theta2),
                weight1.y + scale * length[1] * cos(var.theta2));

  this->Clear();

  this->DrawCross(weight1, Scalar(0, 255, 0), 3);
  this->DrawCross(weight2, Scalar(0, 0, 255), 3);

  this->DrawLine(origin, weight1, Scalar(255, 255, 255), 3);
  this->DrawLine(weight1, weight2, Scalar(255, 255, 255), 3);

  cv::imshow("pendulum", this->canvas);
}

}  // namespace viewer
