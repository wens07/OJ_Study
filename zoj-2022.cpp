#include<iostream>
#include<fstream>
#include<cstdio>
#include<bitset>
#include<cstdlib>
#include<string>
#include<algorithm>

using namespace std;



int main()
{
    int n;
    cin>>n;
    
    while(n--)
    {
        int integer;
        int count = 0;
        cin>>integer;

        for (int i = 5; i <= integer; i *= 5)
        {
           count += integer/i;
        }

        cout<<count<<endl;
    }
    return 0;
}
