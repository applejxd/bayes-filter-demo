#ifndef EOM_H_
#define EOM_H_

#include <vector>

namespace eom{

using std::vector;

class EomBase{
    /**
     * @brief Abstract class for Equations of Motion
     */
    public:
        virtual vector<double> HamiltonEq(const vector<double> &x) = 0;
};

class DoublePendulum : public EomBase {
    /**
     * @brief class for equations of motion of double pendulum
     */ 
    public:
        DoublePendulum(const double (&m)[2], const double (&l)[2]);
    private:
        const double g = 9.8;
        double m[2]={};
        double l[2]={};

        vector<double> x;
        vector<double> HamiltonEq(const vector<double> &x);
};

}	// namespace eom

#endif // EOM_H_