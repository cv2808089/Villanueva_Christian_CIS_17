/* 
 * File: A2 More Test Output Format
 * Author: Christian Villanueva
 * Date: 09/06/2020
 * Purpose: Test Output
 * Version: 1.0
 */

//System Libraries - Post Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    //7 characters or less
    
    //Initialize or input data here
    int n1, n2, n3, n4;
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    cin >> n1;
    cin >> n2;
    cin >> n3;
    cin >> n4;
    //Format and display outputs here
    cout <<  setw(9) << n1;
    float nf1 = float(n1);
    cout << setw(10) << showpoint << fixed << setprecision(1) << nf1 << showpoint << fixed << setprecision(2) << setw(10) << nf1 << endl;
    cout <<  setw(9) << n2;
    float nf2 = float(n2);
    cout << setw(10) << showpoint << fixed << setprecision(1) << nf2 << showpoint << fixed << setprecision(2) << setw(10) << nf2 << endl;
    cout <<  setw(9) << n3;
    float nf3 = float(n3);
    cout << setw(10) << showpoint << fixed << setprecision(1) << nf3 << showpoint << fixed << setprecision(2) << setw(10) << nf3 << endl;
    cout <<  setw(9) << n4;
    float nf4 = float(n4);
    cout << setw(10) << showpoint << fixed << setprecision(1) << nf4 << showpoint << fixed << setprecision(2) << setw(10) << nf4;
    
    //Exit stage left
    return 0;
}