#ifndef INFO_H
#define INFO_H

class info
{
private:
    std::string name;
    std::string address;
    int age;
    std::string pnumber;
public:
    void getInfo(std::string, std::string, int, std::string);
    void output();
};

#endif /* INFO_H */

