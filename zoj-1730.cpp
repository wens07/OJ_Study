#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

/*
 * the rule: num = (n - 1)/2 {n >= 3}
 * 1+2+...+num+num+...+2+1 ----- n is even
 * 1+2+...+num+...+2+1 ----- n is odd
 */ 

int main()
{
    ifstream cin("input.txt");
    
    int d;
    cin>>d;

    while(d--)
    {
        int n;
        cin>>n;
        if (n == 1 || n == 2)
        {
            cout<<0<<endl; continue;
        }
        int num = (n - 1)/2;
        if (n%2 == 0)//n is even
            cout<<(1 + num)*num<<endl;
        else
            cout<<(1 + num - 1) * (num - 1) + num <<endl;
    }

   
    return 0;
}
