#ifndef CUSTOMER_H
#define CUSTOMER_H

struct customer
{
    std::string name;
    std::string address;
    char account[5];
    float stotal;
    float wtotal = 0;
    float dtotal = 0;
    float balance;
};

#endif /* CUSTOMER_H */

