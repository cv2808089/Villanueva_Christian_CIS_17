#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
struct div
{
    float rf;
    float high;
    float low;
    string month;
};

//Function Prototypes
void getDat(struct div&, float&); //Gets info and outputs reults

//Execution Begins Here
int main(int argc, char** argv) 
{
    //Declare Variable Data Types and Constants
    struct div mon[12];
    float totalr = 0;
    float totalt = 0;
    float averaget;
    float averager;
    float max = 0;
    float min = 999;
    string lm;
    string hm;
    
    //Initialize Variables
    for(int i = 0; i < 12; i++)
    {
        getDat(mon[i], totalt);
        if(mon[i].low < min)
        {
            min = mon[i].low;
            lm = mon[i].month;
        }
        if(mon[i].high > max)
        {
            max = mon[i].high;
            hm = mon[i].month;
        }
        totalr += mon[i].rf;
    }
    
    averaget = totalt/24;
    averager = totalr/12;
    cout << showpoint << fixed << setprecision(1);
    cout << "Average Rainfall " << averager << " inches/month" << endl;
    cout << "Lowest  Temperature "<< lm << "  " << static_cast<int>(min) << " Degrees Fahrenheit" << endl;
    cout << "Highest Temperature " << hm << "  " << static_cast<int>(max) << " Degrees Fahrenheit" << endl;
    cout << "Average Temperature for the year " << static_cast<int>(averaget) + 1 << " Degrees Fahrenheit" << endl;

    //Exit stage right!
    return 0;
}

//Promts input and calculates/outputs results
void getDat(struct div &d, float &total)
{
    cin >> d.month;
    cin >> d.rf;
    cin >> d.low;
    total += d.low;
    cin >> d.high;
    total += d.high;

}
