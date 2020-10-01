#include "./include/ode_solver.h"

#include <array>

namespace odesolver {

using std::array;

OdeSolverBase::OdeSolverBase(eom::EomBase* eom, double dt)
    : eom_ins(eom), dt(dt) {}

eom::EomBase* OdeSolverBase::GetEom(void) { return this->eom_ins; }

double OdeSolverBase::GetDt(void) { return this->dt; }

/**
 * The 4th-order Runge-Kutta method
 * @param var Variables in current step
 * @return Variables in next step
 */
CanonVar RK4::SolveOde(const CanonVar& var) {
  array<CanonVar, 4> k;
  CanonVar var_shift;

  k[0] = this->GetEom()->HamiltonEq(var);

  for (int i = 0; i < var.data.size(); i++) {
    var_shift.data[i] = var.data[i] + (this->GetDt()) / 2.0 * k[0].data[i];
  }
  k[1] = this->GetEom()->HamiltonEq(var_shift);

  for (int i = 0; i < var.data.size(); i++) {
    var_shift.data[i] = var.data[i] + (this->GetDt()) / 2.0 * k[1].data[i];
  }
  k[2] = this->GetEom()->HamiltonEq(var_shift);

  for (int i = 0; i < var.data.size(); i++) {
    var_shift.data[i] = var.data[i] + (this->GetDt()) * k[2].data[i];
  }
  k[3] = this->GetEom()->HamiltonEq(var_shift);

  CanonVar var_next;
  for (int i = 0; i < var.data.size(); i++) {
    var_next.data[i] = var.data[i] + (k[0].data[i] + 2 * k[1].data[i] +
                                      2 * k[2].data[i] + k[3].data[i]) /
                                         6.0 * this->GetDt();
  }

  return var_next;
}

}  // namespace odesolver
