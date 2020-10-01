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
