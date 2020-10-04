/**
 * @file ode_solver.h Define ODE solvers
 * Copyright 2020 @applejxd
 */
#ifndef SRC_INCLUDE_ODE_SOLVER_H_
#define SRC_INCLUDE_ODE_SOLVER_H_

#include <vector>
#include "./eom.h"
#include "./types.h"

namespace odesolver {

using std::vector;
using types::CanonVar;

/**
 * Define ODE solver of EoM by the delegation pattern
 */
class OdeSolverBase {
 public:
  /** set solver parameters */
  OdeSolverBase(eom::EomBase* eom, double dt, double t_end);
  // Getter
  inline const double GetDt(void) const { return this->dt; }
  inline const int GetTimes(void) const { return this->times; }
  inline eom::EomBase* GetEom(void) const { return this->eom_ins; }
  /** Solve ODE */
  virtual void SolveOde(const CanonVar&) = 0;
  inline void PushAnsBack(const CanonVar& var) {
    this->answer.push_back(var);
  }
  /** Get the answer */
  inline const vector<CanonVar>& GetAnswer(void) const { return this->answer; }

 private:
  /** time step */
  const double dt;
  const int times;
  /** Equations of motion */
  eom::EomBase* eom_ins;
  /** Solutions of the ODE */
  vector<CanonVar> answer;
};

/**
 * Solve ODE by the Runge-Kutta method (4th order)
 */
class RK4 : public OdeSolverBase {
 public:
  using OdeSolverBase::OdeSolverBase;
  void SolveOde(const CanonVar& var);

 private:
  CanonVar Renew(const CanonVar& var);
};

}  // namespace odesolver

#endif  // SRC_INCLUDE_ODE_SOLVER_H_
