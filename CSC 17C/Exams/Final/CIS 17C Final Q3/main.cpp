#include <iostream>
#include <queue>
using namespace std;


class Customer
{
public:
    int timeWaited = 0;
};


int main() 
{
    queue<Customer> line;
    int tp = 0;
    int numClerks = 3;
    vector<float> clerk;
    clerk.push_back(1);
    clerk.push_back(.5);
    clerk.push_back(.75);
    
    for(int i = 0; i < 100000; i++)
    {
        if(i % 15 == 0)
        {
            Customer c1;
            line.push(c1);
        }
        if(line.size() % 5 == 0 && line.size() != 0)
        {
            clerk.push_back(1);
            numClerks++;
        }
        
        line.front().timeWaited++;
    }
    
    return 0;
}

