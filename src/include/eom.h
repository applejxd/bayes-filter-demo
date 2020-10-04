/**
 * @file eom.h Define equations of motion
 * Copyright 2020 @applejxd
 */
#ifndef SRC_INCLUDE_EOM_H_
#define SRC_INCLUDE_EOM_H_

#include <array>
#include <vector>

#include "./types.h"

namespace eom {

using std::array;
using std::vector;
using types::CanonVar;

/**
 * Abstract class for Equations of Motion
 */
class EomBase {
 public:
  /** Hamilton equations */
  virtual CanonVar HamiltonEq(const CanonVar&) = 0;
  /** Getter for current state */
  inline const CanonVar& GetState() const { return this->var; }

 private:
  CanonVar var;
};

/**
 * Class for equations of motion of double pendulum
 */
class DoublePendulum : public EomBase {
 public:
  DoublePendulum(const array<double, 2>& m, const array<double, 2>& l);
  CanonVar HamiltonEq(const CanonVar& x);

 private:
  /** Gravitational accelaration constant */
  constexpr static double g{9.8};
  /** Masses of the double pendulum */
  const array<double, 2> m;
  /** Lengthes of the double pendulum */
  const array<double, 2> l;
};

}  // namespace eom

#endif  // SRC_INCLUDE_EOM_H_
