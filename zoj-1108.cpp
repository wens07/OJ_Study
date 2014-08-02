//
//  zoj-1108.cpp
//  acm_project
//
//  Created by wens07 on 26/5/13.
//  Copyright (c) 2013 wens07. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <algorithm>


#define MOUSE 1000

struct mouse
{
    int weight;
    int speed;
    int se;
};


bool micebyweight(mouse i, mouse j)
{
    return i.weight < j.weight;
}

mouse mice[MOUSE];
int dp[MOUSE];
int path[MOUSE];

int main(int argc, const char* argv[])
{
    freopen("/Users/wens07/Documents/codes/c++/acm_test/input.txt", "r", stdin);
    
    int index = 0;
    
    while(scanf("%d %d", &mice[index].weight, &mice[index].speed) != EOF)
    {
        mice[index].se = index;
        index ++;
    }
    
    std::fill_n(dp, MOUSE, 0x1);
    memset(path, 0xff, sizeof(path));
    
    std::sort(mice, mice + index, micebyweight);
    
    
    
    
    
    for (int j = index - 2; j >= 0; --j)
    {
        for (int i = j + 1; i < index; ++i)
        {
            if (mice[j].speed > mice[i].speed && mice[j].weight < mice[i].weight)
            {
                if (dp[j] < dp[i] + 1)
                {
                    dp[j] = dp[i] + 1;
                    path[j] = i; //record the path
                }
            }
        }
    }
    
    int ans = 0;
    int start = -1;
    for (int i = 0; i < index; ++i)
    {
        if (dp[i] > ans)
        {
            ans = dp[i];
            start = i;
        }
    }
    
    printf("%d\n", ans);
    printf("%d\n", mice[start].se + 1);
    
    for (int i = start; i < index;)
    {
        if (path[i] != -1)
        {
            printf("%d\n", mice[path[i]].se + 1);
            i = path[i];
        }
        else
            break;
    }
    
    
    return 0;
}