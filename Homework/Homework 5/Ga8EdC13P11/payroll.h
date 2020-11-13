#ifndef PAYROLL_H
#define PAYROLL_H

class PayRoll
{
private:
    float rate;
    int hours;
    float total;
public:
    void getRate(float);
    void getHours(int);
    float calcTotal();
};

#endif /* PAYROLL_H */

