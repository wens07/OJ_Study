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
    int a[3000];
    bitset<3000> bset;

    while(cin>>n)
    {
        int num = n;
        bset.reset();
        
        while(n--)
        {
            cin>>a[num-n-1];
        }

        if (num == 1)
        {
            cout<<"Jolly"<<endl;
            continue;
        }
 
        for (int i = 1; i < num; ++i)
        {
            if (abs(a[i] - a[i - 1]) >= 1 && abs(a[i] - a[i - 1]) <= num -1)
                bset.set(abs(a[i] - a[i - 1]));
        }

        bool whetherjolly = true;
        for (int i = 1; i < num; ++i)
        {
            if (bset[i] == false)
                whetherjolly = false;
        }

        if (whetherjolly)
            cout<<"Jolly"<<endl;
        else
            cout<<"Not jolly"<<endl;

    }
    return 0;
}
