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
    int dataset;
    int n;
    int grade[1001];

    cin>>dataset;

    while(dataset--)
    {
        cin>>n;
        int num = n;
        double sum = 0;
        while(n--)
        {
            cin>>grade[num - n -1];
            sum += grade[num - n - 1];
        }

        double count = 0;
        for (int i = 0; i < num; ++i)
        {
            if (grade[i] > sum/num)
                count++;
        }

        printf("%.3lf%%\n", count/num * 100);


    }

    return 0;
}
