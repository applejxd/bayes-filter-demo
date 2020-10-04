/**
 * Task runner
 * @file runner.h
 * Copyright 2020 @applejxd
 */
#ifndef SRC_INCLUDE_RUNNER_H_
#define SRC_INCLUDE_RUNNER_H_

#include <array>
#include "./eom.h"
#include "./ode_solver.h"

namespace runner {

using std::array;

class Runner {
 public:
  Runner(void);
  void RunPrinter();

 private:
  /** Masses of the double pendulum */
  const array<double, 2> m{1., 1.};
  /** Lengthes of the double pendulum */
  const array<double, 2> l{1., 1.};
  double dt{1./60.};
  double t_end{100};
  /** Equations of motion to be solved */
  eom::EomBase* eom_ins_ptr;
  /** ODE solver method */
  odesolver::OdeSolverBase* solver_ins_ptr;
};

}  // namespace runner

#endif  // SRC_INCLUDE_RUNNER_H_
