//
//  pat-1008.cpp
//  acm_project
//
//  Created by wens on 7/21/14.
//  Copyright (c) 2014 wens07. All rights reserved.
//  Email:wens.wq@gmail.com
//

#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
    freopen("/Users/wens/Desktop/code_study/acm_project/acm_project/input.txt", "r", stdin);
    
    int numbers;
    int floors[101];
    
    while (scanf("%d", &numbers) != EOF)
    {
        memset(floors, 0, sizeof(floors));
        
        for (int i = 0; i < numbers; ++i)
        {
            scanf("%d", &floors[i]);
        }
        
        int current_floor = 0;
        int sum = 0; //total time
        
        for (int i = 0; i < numbers; ++i)
        {
            int tmpfloors = floors[i] - current_floor;
            current_floor = floors[i];
            
            if (tmpfloors >= 0)
            {
                sum += tmpfloors * 6;
            }
            else
                sum += abs(tmpfloors) * 4;
            
            sum += 5;
        }
        
        printf("%d\n", sum);
    }
    
    return 0;
}