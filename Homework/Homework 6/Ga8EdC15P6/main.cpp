#include <iostream>
#include "gradedactivity.h"
#include "essay.h"
using namespace std;

int main()
{
    float g;
    float s;
    float l;
    float c;
    string len;
    
    cout << "Enter the grammar score" << endl;
    cin >> g;
    while(g < 0 || g > 30)
    {
        cout << "Error, invalid input" << endl;
        cin.clear();
        cin >> g;
    }
    
    cout << "Enter the spelling score" << endl;
    cin >> s;
    while(s < 0 || s > 20)
    {
        cout << "Error, invalid input" << endl;
        cin.clear();
        cin >> s;
    }
    
    cout << "Was the essay the correct length?" << endl;
    cin >> len;
    if(len == "yes")
        l = 20;
    else
        l = 0;
    
    cout << "Enter the content score" << endl;
    cin >> c;
    while(c < 0 || c > 30)
    {
        cout << "Error, invalid input" << endl;
        cin.clear();
        cin >> c;
    }
    
    Essay e1(g, s, l, c);
    
    cout << "The essay score is: " << e1.getLetterGrade() << ' ' << e1.getScore() << '%' << endl;
    
    return 0;
}

void Essay::setGrade(float g, float s, float l, float c)
{
    grammar = g;
    spelling = s;
    length = l;
    content = c;
}

char GradedActivity::getLetterGrade() const
{
    char letterGrade;
    if(score >= 0 && score <= 59)
        letterGrade = 'F';
    if(score >= 60 && score <= 69)
        letterGrade = 'D';
    if(score >= 70 && score <= 79)
        letterGrade = 'C';
    if(score >= 80 && score <= 89)
        letterGrade = 'B';
    if(score >= 90)
        letterGrade = 'A';
    return letterGrade;
}