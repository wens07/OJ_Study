//
//  uva_116.cpp
//  acm_project
//
//  Created by wens07 on 23/5/13.
//  Copyright (c) 2013 wens07. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <limits>
#include <algorithm>

using namespace std;


#define ROW 10
#define COLUMN 100


struct pos
{
    int r;
    int c;
};

int matrix[ROW][COLUMN];
long long int dp[ROW][COLUMN];
int path[ROW][COLUMN];
int m, n;

int minest(int j, int i)
{
    if (dp[(j - 1 + m)%m][i + 1] < dp[j][i + 1])
    {
        if ( dp[j][i + 1] <= dp[(j + 1) % m][i + 1])
            return  (j - 1 + m)%m;
        else
        {
            if (dp[(j - 1 + m)%m][i + 1] < dp[(j + 1) % m][i + 1])
                return (j - 1 + m)%m;
            else if(dp[(j - 1 + m)%m][i + 1] == dp[(j + 1) % m][i + 1])
                return min((j - 1 + m)%m, (j + 1) % m);
            else
                return (j + 1) % m;
        }
    }
    else if ( dp[(j - 1 + m)%m][i + 1] == dp[j][i + 1])
    {
        int tmp = min((j - 1 + m)%m, j);
        if (dp[j][i + 1] == dp[(j + 1) % m][i + 1])
            return min(tmp, (j + 1) % m);
        else if (dp[j][i + 1] > dp[(j + 1) % m][i + 1])
            return (j + 1) % m;
        else
            return tmp;
            
    }
    else//j < i
    {
        if (dp[j][i + 1] < dp[(j + 1) % m][i + 1])
            return j;
        else if (dp[j][i + 1] == dp[(j + 1) % m][i + 1])
            return min(j, (j + 1)%m);
        else
            return (j + 1)%m;
            
    }
        
}

int main(int argc, const char* argv[])
{
    freopen("/Users/wens07/Desktop/code_study/test.txt", "r", stdin);

    while (scanf("%d %d", &m, &n) != EOF)
    {
        memset(dp, 0x0, sizeof(dp));
        memset(path, 0x0, sizeof(path));
        memset(matrix, 0x0, sizeof(matrix));
        
        int row = m;
        while (row--)
        {
            for (int i = 0; i < n; ++i)
                scanf("%d", &matrix[m - row - 1][i]);
        }
        
        //ininitalization
        for (int i = 0; i < m; ++i)
        {
            path[i][n - 1] = -1;
            dp[i][n - 1] = matrix[i][n - 1];

        }
                    
        for (int i = n - 2; i >= 0; --i)
        {

            for (int j = 0; j < m; ++j) 
            {
//                if (m == 2)
//                {
//                    if (dp[j][i + 1] == dp[(j + 1)%m][i + 1])
//                    {
//                        dp[j][i] = dp[j][i + 1] + matrix[j][i];
//                        path[j][i] = min(j, (j + 1)%m);
//                    }
//                    else if (dp[j][i + 1] < dp[(j + 1)%m][i + 1])
//                    {
//                        
//                        dp[j][i] = dp[j][i + 1] + matrix[j][i];
//                        path[j][i] = j;
//
//                    }
//                    else
//                    {
//                        
//                        dp[j][i] = dp[(j + 1)%m][i + 1] + matrix[j][i];
//                        path[j][i] = (j + 1)%m;
//                    }
//                }
//                else
//                {
                    int tmp = minest(j, i);

                    dp[j][i] = dp[tmp][i + 1] + matrix[j][i];
                    
                    path[j][i] = tmp;
                    
//                    
//                }
            }
            
        }
        
        long long int min = numeric_limits<long long>::max();
        int index = 0;
        for (int i = 0; i < m; ++i)
            if (dp[i][0] < min)
            {
                min = dp[i][0];
                index = i;
            }
        
        printf("%d", index + 1);
        for (int i = 0; i < n; ++i)
        {
            if (path[index][i] != -1)
            {
                printf(" %d",  path[index][i] + 1);
                index = path[index][i];
            }
        }
        
        printf("\n");
        printf("%lld\n", min);
        
    }
    
    return 0;
}
