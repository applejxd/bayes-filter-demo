#ifndef EOM_H_
#define EOM_H_

#include <vector>

namespace eom{

using std::vector;

/**
 * Abstract class for Equations of Motion
 */
class EomBase{
    public:
        virtual vector<double> HamiltonEq(const vector<double> &x) = 0;
    private:
        vector<double> x;
};

/**
 * Class for equations of motion of double pendulum
 */ 
class DoublePendulum : public EomBase {
    public:
        DoublePendulum(const double (&m)[2] , const double (&l)[2]);
        vector<double> HamiltonEq(const vector<double> &x);
    private:
        constexpr static double g = 9.8;
        const double m[2];
        const double l[2];
};

}	// namespace eom

#endif // EOM_H_