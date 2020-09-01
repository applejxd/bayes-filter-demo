#ifndef ODE_SOLVER_H_
#define ODE_SOLVER_H_

#include <vector>

#include <eom.h>

namespace odesolver{

using std::vector;

/**
 * Define ODE solver of EoM by the delegation pattern
 */
class OdeSolverBase{
    public:
        OdeSolverBase(eom::EomBase* eom, double dt);
        double GetDt(void);
        eom::EomBase* GetEom(void);
        virtual vector<double> SolveOde(const vector<double> &x) = 0;
    private:
        eom::EomBase* eom_ins;
        const double dt = 0;
};

/**
 * Solve ODE by the Runge-Kutta method (4th order)
 */
class RK4 : public OdeSolverBase{
    public:
        using OdeSolverBase::OdeSolverBase;
        vector<double> SolveOde(const vector<double> &x) = 0;
};

}	// namespace odesolver

#endif // ODE_SOLVER_H_