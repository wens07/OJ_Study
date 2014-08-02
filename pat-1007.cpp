//
//  pat-1007.cpp
//  acm_project
//
//  Created by wens on 7/19/14.
//  Copyright (c) 2014 wens07. All rights reserved.
//

#include <stdio.h>
#include <memory>
#include <cstring>
#include <limits>
#include <string>
using namespace std;

const int MAX_LENGTH = 10000;

long long integer_array[MAX_LENGTH];

int main()
{
    freopen("/Users/wens/Desktop/code_study/acm_project/acm_project/input.txt", "r", stdin);
    
    int length;
    while (scanf("%d", &length) != EOF)
    {
        memset(integer_array, 0, sizeof(integer_array) / sizeof (int));
        for (int i = 0; i < length; ++i) {
            scanf("%lld", &integer_array[i] );
        }
        
        long long max_sum = numeric_limits<long long>::min();

       // printf("%lld", max_sum);
        int max_sum_start = 0;
        int max_sum_end = 0;
        
        int tempstart = 0;
        long long sum = 0;
        
        for (int i = 0; i < length; ++i)
        {
            sum = sum + integer_array[i];
            
            
            if (sum > max_sum)
            {
                max_sum = sum;
                max_sum_start = tempstart;
                max_sum_end = i;
            }
            

            
            if (sum <= 0) //subsequence can proceed
            {
                tempstart = i + 1;
                sum = 0;
            }
        }
        
        if (max_sum < 0)
        {
            printf("0 %lld %lld\n", integer_array[0], integer_array[length - 1]);
        }
        else
            printf("%lld %lld %lld\n", max_sum, integer_array[max_sum_start], integer_array[max_sum_end]);
    }
    return 0;
}