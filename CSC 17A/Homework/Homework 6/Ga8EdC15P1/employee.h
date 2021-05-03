#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
private: 
    std::string name;
    int number;
    std::string date;
public:
    Employee(std::string, int, std::string);
    
    void setName(std::string);
    void setNum(int);
    void setDate(std::string);
    
    std::string getName()
        { return name; }
    int getNum()
        { return number; }
    std::string getDate()
        { return date; }
};
    


#endif /* EMPLOYEE_H */

