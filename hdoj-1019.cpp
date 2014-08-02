#include<iostream>
#include<fstream>
#include<cstdio>

using namespace std;

int gcd(int m, int n)
{
    if (m < n)
        gcd(n, m);

    if (n == 0) return m;
    return gcd(n, m%n);
}

int main()
{
    ifstream cin("input.txt");

    int n;
    long long int  origin, tmp;
    cin>>n;

    while(n--)
    {
        int k;
        cin>>k;

        for (int i = 0; i < k; ++i)
        {
            cin>>origin;
            if (i == 0)
                tmp = origin;
            else
                tmp = origin/gcd(origin, tmp)*tmp;
        }
         
        cout<<tmp<<endl;
    }
    return 0;
}
