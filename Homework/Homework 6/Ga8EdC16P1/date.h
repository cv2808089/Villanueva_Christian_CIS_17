#ifndef DATE_H
#define DATE_H

class Date
{
private:
    int month;
    int day;
    int year;
public:
    void setValues(int, int, int);
    class invalidDay
    {};
    class invalidMonth
    {};
    void form1();
    void form2();
    void form3();
};


#endif /* DATE_H */

