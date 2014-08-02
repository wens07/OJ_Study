//
//  pat-1009.cpp
//  acm_project
//
//  Created by wens on 7/21/14.
//  Copyright (c) 2014 wens07. All rights reserved.
//  Email:wens.wq@gmail.com
//

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cfloat>

using namespace std;

int main()
{
    freopen("/Users/wens/Desktop/code_study/acm_project/acm_project/input.txt", "r", stdin);
    
    //const float float_judge = 0.05;
    
    double polyn1[1001];
    double polyn2[1001];
    double polyn_product[2001];
    int length = 1001;
    int max_length = 2001;
    
    int num1, num2;
    int exponent;
    double coefficient;
    
    while (scanf("%d", &num1) != EOF)
    {
        memset(polyn1, 0, sizeof(polyn1));
        memset(polyn2, 0, sizeof(polyn2));
        memset(polyn_product, 0, sizeof(polyn_product));
        
        //scanf ployn1
        while (num1--)
        {
            scanf("%d %lf", &exponent, &coefficient);
            polyn1[exponent] = coefficient;
        }
        
        //scanf ployn2
        scanf("%d", &num2);
        
        while (num2--)
        {
            scanf("%d %lf", &exponent, &coefficient);
            polyn2[exponent] = coefficient;
        }
        
        for (int i = 0; i < length; ++i)
        {
            if (polyn1[i] != 0)
            {
                for (int j = 0; j < length; ++j)
                {
                    if (polyn2[j] != 0)
                        polyn_product[i + j] += polyn1[i] * polyn2[j];
                }
            }
            
        }
        
        int size = 0;
        for (int i = 0; i < max_length; ++i)
        {
            if (polyn_product[i] != 0)
                size++;
                
        }
      
        printf("%d ", size);
        
        int num = size;
        for (int i = max_length - 1; i >= 0; --i)
        {
            if (polyn_product[i] != 0)
            {
                if (--num)
                    printf("%d %.1lf ", i, polyn_product[i]);
                else
                    printf("%d %.1lf\n", i, polyn_product[i]);
            }
            
        }
    }
    
    return 0;
}