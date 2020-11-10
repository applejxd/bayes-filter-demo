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
#include "./viewer.h"

namespace runner {

using std::array;

/** Task Runner Class */
class Runner {
 public:
  Runner(void);
  void RunPrinter();
  void RunViewer();

 private:
  /** Masses of the double pendulum */
  const array<double, 2> m{2., 1.};
  /** Lengthes of the double pendulum */
  const array<double, 2> l{1., 1.};
  /** time step */
  double dt{1./100.};
  /** time range */
  double t_end{100.};
  /** Equations of motion to be solved */
  eom::EomBase* eom_ins_ptr;
  /** ODE solver method */
  odesolver::OdeSolverBase* solver_ins_ptr;
  /** Viewer */
  viewer::Viewer viewer_ins;
};

}  // namespace runner

#endif  // SRC_INCLUDE_RUNNER_H_
