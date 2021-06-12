/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on June 2nd, 2021, 8:11 AM
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

stack<float> ash;
stack<float> asg;
float h(float);
float g(float);

int main(int argc, char** argv) {
    //Testing out recursive trig functions
    
    float angRad=1;
    //cout<<"Angle = "<<angRad<<" sinh = "<<sinh(angRad)<<
     //       " our h = "<<h(angRad)<<endl;
    cout<<"Angle = "<<angRad<<" cosh = "<<cosh(angRad)<<
            " our g = "<<g(angRad)<<endl;
    //Exit stage right
    
    cout << endl << "number of times called(sin): " << ash.size() << endl;

    cout << endl;
    cout << endl << "number of times called(cos): " << asg.size() << endl;

    return 0;
}

float h(float angR){
    float tol=1e-6;
    if(angR>-tol&&angR<tol)return angR+angR*angR*angR/6;
    ash.push(2*h(angR/2)*g(angR/2));
    return 2*h(angR/2)*g(angR/2);
}
float g(float angR){
    float tol=1e-6;
    if(angR>-tol&&angR<tol)return 1+angR*angR/2;
    float b=h(angR/2);
    asg.push(1+2*b*b);
    return 1+2*b*b;
}
