#ifndef ODE_SOLVER_H_
#define ODE_SOLVER_H_

#include <vector>

#include <eom.h>

namespace odesolver{

using std::vector;

class OdeSolverBase{
    /**
     * @brief define ODE solver of EoM by the delegation pattern
     */
    public:
        double dt = 0;
        // the delegation pattern
        eom::EomBase *eom_impl;

        OdeSolverBase() : eom_impl(){}
        void SetEom (eom::EomBase *eom){
            eom_impl = eom;
        }
        virtual vector<double> SolveOde(const vector<double> &x) = 0;
};

class RK4 : public OdeSolverBase{
    /**
     * @brief solve ODE by the Runge-Kutta method (4th order)
     */
    private:
        vector<double> SolveOde(const vector<double> &x) = 0;
};

}	// namespace odesolver

#endif // ODE_SOLVER_H_