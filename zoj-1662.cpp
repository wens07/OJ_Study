#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

/*
 * first of all, start from the first light, do the turn on/off
 * let the lights on and off alternatively
 *
 * get the min of (all light - the number of turned light, the number of turned l   ight )
 *
 */

int main()
{
    ifstream cin("input.txt");
     
    int n;
    int lights[10001];
    while(cin>>n)
    {
        int num = n;
        while(n--)
            cin>>lights[n];
        
        int times = 0;
        for (int i = 1; i < num; ++i)
        {
            if (lights[i] == lights[i - 1])
            {
                times++;
                lights[i] = 1 ^ lights[i];
            }
        }

        cout<<min(num - times, times)<<endl;

    }
    return 0;
}
