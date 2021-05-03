#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;


struct info{
    char div[6];
    int q;
    float sales;
};


void getNum(info []);
void tf(fstream &, info []);

int main()
{
    fstream outputFile("sales.bin", ios::binary);
    
    info north[4] = {{"North"}, {"North"}, {"North"}, {"North"}};
    info east[4] = {{"East"}, {"East"}, {"East"}, {"East"}};
    info south[4] = {{"South"}, {"South"}, {"South"}, {"South"}};
    info west[4] = {{"West"}, {"West"}, {"West"}, {"West"}};
    
    getNum(east);
    getNum(west);
    getNum(north);
    getNum(south);

    outputFile.seekp(0L, ios::beg);

    tf(outputFile, north);
    tf(outputFile, east);
    tf(outputFile, south);
    tf(outputFile, west);

    outputFile.close();

    return 0;
}

void getNum(info d[])
{
    cout << "Enter sales for " << d[0].div << endl;
    for(int i = 0; i < 4; i++)
    {
        d[i].q = i + 1;
        cout << "Enter the sales for quarter " << d[i].q << endl;
        cin >> d[i].sales;

        while(d[i].sales < 0)
        {
            cout << "Positive numbers only" << endl;
            cin >> d[i].sales;
        }
    }
}

void tf(fstream &out, info d[]){
    for(int i = 0; i < 4; i++){
        out.write(reinterpret_cast<char *>(&d[i]), sizeof(d[i]));
    }
}