/**
 * @file types.h Define original data types
 * Copyright 2020 @applejxd
 */
#ifndef SRC_INCLUDE_TYPES_H_
#define SRC_INCLUDE_TYPES_H_

#include <array>

namespace types {

/** Canonical variables of the phase space */
struct CanonVar {
  union {
    std::array<double, 4> data;
    struct {
      // Genenalized coordinates
      double theta1;
      double theta2;
      // Genenalized momentums
      double omega1;
      double omega2;
    };
  };
  /** Set canonical variables to null */
  CanonVar(void) {
    theta1 = 0.;
    theta2 = 0.;
    omega1 = 0.;
    omega2 = 0.;
  }
  /** Initialize canonical variables */
  CanonVar(double a, double b, double c, double d) {
    theta1 = a;
    theta2 = b;
    omega1 = c;
    omega2 = d;
  }
};

/** Error of the state */
struct CanonErr {
  union {
    std::array<double, 4> data;
    struct {
      // Errors of the genenalized coordinates
      double theta1;
      double theta2;
      // Genenalized momentums
      double omega1;
      double omega2;
    };
  };
};

}  // namespace types

#endif  // SRC_INCLUDE_TYPES_H_
