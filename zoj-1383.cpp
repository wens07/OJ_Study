#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;


int main()
{
    ifstream cin("input.txt");
    int d;
    int position[21];

    while(cin>>d)
    {
        while(d--)
        {
            memset(position, 0, sizeof(position));
            int n;
            int i = 0;
            bool isoutbank = false;

            cin>>n;
            while(n != 0)
            {
                position[i++] = n%2;
                n /= 2;
            }

            for (int i = 0; i < 21; ++i)
            {
                if (position[i] == 1)
                {
                    if (isoutbank)
                        cout<<" ";
                    isoutbank = true;
                    cout<<i;
                }
            }
            cout<<endl;
        }
    }

    return 0;
}
