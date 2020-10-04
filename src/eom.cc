// Copyright 2020 @applejxd
#include "include/eom.h"

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

namespace eom {

using std::cout;

/**
 * Set system parameters
 * @param m Mass parameters of the double pendulum
 * @param l Length of the double pendulum
 */
DoublePendulum::DoublePendulum(const array<double, 2> &m,
                               const array<double, 2> &l)
    : m(m), l(l) {
  if (m[0] == 0 || m[1] == 0 || l[0] == 0 || l[1] == 0) {
    throw std::runtime_error("Error: Null parameter(s) exist.");
  }
}

/**
 * Hamilton equations of double pendulum
 * @param x Phase space variables
 * @return Renewed phase space variables
 */
CanonVar DoublePendulum::HamiltonEq(const CanonVar &var) {
  if (var.data.size() != 4) {
    throw std::runtime_error("Error: The phase sp. dim. doesn't match.");
  }

  CanonVar dxdt;

  // for dqdt
  double offdiag = m[1] * l[0] * l[1] * cos(var.theta1 - var.theta2);
  double det = (m[0] + m[1]) * m[1] * pow(l[0] * l[1], 2.) - pow(offdiag, 2.);

  dxdt.theta1 = (m[1] * l[1] * l[1] * var.omega1 - offdiag * var.omega2) / det;
  dxdt.theta2 =
      (-offdiag * var.omega1 + (m[0] * m[1]) * l[0] * l[0] * var.omega2) / det;

  // for dpdt
  double c = m[1] * l[0] * l[1] * sin(var.theta1 - var.theta2) * dxdt.theta1 *
             dxdt.theta2;

  dxdt.omega1 = -c - (m[0] + m[1]) * g * l[0] * sin(var.theta1);
  dxdt.omega2 = c - m[1] * g * l[1] * cos(var.theta2);

  return dxdt;
}

}  // namespace eom
