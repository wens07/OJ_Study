#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    ifstream cin("input.txt");

    int a[51];
    int n, result;
    int sum;
    int numofset = 0;
    while(cin>>n && n!=0)
    {
        numofset++;
        int num = n;//record the stack number
        sum = result = 0;
        memset(a, 0, sizeof(a));

        while(n--)
        {
            cin>>a[n];

            sum += a[n];
        }

        for (int i = 0; i < num; ++i)
        {
            if (a[i] > sum/num)
                result += a[i] - sum/num;
        }
        cout<<"Set #"<<numofset<<endl;
        cout<<"The minimum number of moves is "<<result<<"."<<endl;
        cout<<endl;
    }
    return 0;
}
