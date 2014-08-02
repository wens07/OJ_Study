//
//  uva_10151.cpp
//  code_study
//
//  Created by wens07 on 17/5/13.
//  Copyright (c) 2013 wens07. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_SIZE 5700

struct turtle
{
    int weight;
    int carriage;
};

bool sort_turle(turtle a, turtle b)
{
    if (a.carriage != b.carriage)
        return  a.carriage < b.carriage;
    else
        return a.weight < b.weight;
}


const int INF = 0x7f7f7f7f;
int dp[MAX_SIZE][MAX_SIZE];
turtle arr_turte[MAX_SIZE];

int main(int argc, const char* argv[])
{
    freopen("/Users/wens07/Desktop/code_study/test.txt", "r", stdin);
    
    
    memset(dp, 0x7f, sizeof(dp));
    
    int index = 0;
    
    while (scanf("%d %d", &arr_turte[index].weight, &arr_turte[index].carriage) != EOF) index++;
    
    sort(arr_turte, arr_turte + index, sort_turle);
    
    int max = 0;
    
    for (int i = 0; i < MAX_SIZE; ++i)
        dp[i][0] = 0;
    
    
    dp[0][1] = arr_turte[0].weight;
    
    for (int i = 1; i < index; ++i)
    {
        for (int j = 1; j <= i + 1; ++j)
        {
            if ( dp[i - 1][j - 1] + arr_turte[i].weight <= arr_turte[i].carriage)
                dp[i][j] = std::min(dp[i - 1][j], dp[i - 1][j - 1] + arr_turte[i].weight);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    
    
    for (int i = index; i >=0 ; --i)
        if (dp[index - 1][i] != INF)
        {
            max = i;
            break;
        }
        
    printf("%d\n", max);
    
    return 0;
}