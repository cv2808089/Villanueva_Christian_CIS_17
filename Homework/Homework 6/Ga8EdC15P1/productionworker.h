#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

#include "employee.h"

class productionWorker : public Employee
{
    private:
        int shift;
        float rate;
    public: 
        productionWorker(std::string n, int num, std::string d, int sh, float r) : Employee(n, num, d)
        {
            setShift(sh);
            setRate(r);
        }
        
        void setShift(int);
        void setRate(float);
        
        int getShift()
            { return shift; }
        float getRate()
            { return rate; }
              
};

#endif /* PRODUCTIONWORKER_H */

