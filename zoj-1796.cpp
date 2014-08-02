#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

/*
 * two equation:
 *    total loss == total win ---- (1)
 *    win(i) + loss(i) == win(j) + loss(j) ---- (2) 
 */ 

int main()
{
    ifstream cin("input.txt");
   
    int a[3][2];
    memset(a, 0, sizeof(a));

    while(cin>>a[0][0]>>a[0][1]\
             >>a[1][0]>>a[1][1]\
             >>a[2][0]>>a[2][1])
    {
        if (a[0][0] == 0 && a[0][1] == 0 && 
            a[1][0] == 0 && a[1][1] == 0 &&
            a[2][0] == 0 && a[2][1] == 0) break;
        int win, loss;

        loss = (2*a[0][0] + a[1][0] + a[2][0] - a[1][1] - a[2][1])/2;
        win = a[0][0] + a[0][1] - loss;

        cout<<"Anna's won-loss record is "<<win<<"-"<<loss<<"."<<endl;
    }
   
   
    return 0;
}
