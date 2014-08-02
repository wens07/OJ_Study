#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

int lcd(int m, int n)
{
    if (m < n)
        return lcd(n, m);


    if (n == 0)
        return m;

    return lcd(n, m%n);
}

int main()
{
    ifstream cin("input.txt");
    int N;
    int a[51];

    while(cin>>N && N!=0)
    {
        int num = N;
        int allpairs = N * (N - 1)/2;
        int no_common_pairs = 0;
        memset(a, 0, sizeof(a));

        while(N--)
            cin>>a[N];
        
        for (int i = 0; i < num; ++i)
        {
            for (int j = i + 1; j < num; ++j)
                if (lcd(a[i], a[j]) == 1)
                    no_common_pairs++;
        }

        if (no_common_pairs != 0)
        {
            double factor = (double)no_common_pairs/allpairs;
            printf("%.6lf\n", sqrt(6/factor));

        }   
        else
            printf("No estimate for this data set.\n");
    }

    return 0;
}
