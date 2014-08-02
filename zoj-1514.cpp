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
    
    int ti[10001];
    int people;
  
    int n, m;
    while(cin>>n>>m && m!=0 && n!=0)
    {
        int result = 0;
        memset(ti, 0, sizeof(ti));
        
        while(m--)
        {
            cin>>people;
            ti[people]++;

        }

        for (int i = 1; i <= n; ++i)
            if (ti[i] >= 2)
                result++;
        cout<<result<<endl;
    }

    return 0;
}
