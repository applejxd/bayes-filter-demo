/**
 * @file ode_solver.h Define ODE solvers
 * Copyright 2020 @applejxd
 */
#ifndef SRC_INCLUDE_ODE_SOLVER_H_
#define SRC_INCLUDE_ODE_SOLVER_H_

#include "./eom.h"
#include "./types.h"

namespace odesolver {

using types::CanonVar;

/**
 * Define ODE solver of EoM by the delegation pattern
 */
class OdeSolverBase {
 public:
  OdeSolverBase(eom::EomBase* eom, double dt);
  double GetDt(void);
  eom::EomBase* GetEom(void);
  virtual CanonVar SolveOde(const CanonVar&) = 0;

 private:
  /** time step */
  const double dt = 0;
  eom::EomBase* eom_ins;
};

/**
 * Solve ODE by the Runge-Kutta method (4th order)
 */
class RK4 : public OdeSolverBase {
 public:
  using OdeSolverBase::OdeSolverBase;
  CanonVar SolveOde(const CanonVar&);
};

}  // namespace odesolver

#endif  // SRC_INCLUDE_ODE_SOLVER_H_
