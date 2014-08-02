//
//  yong_triangle.cpp
//  code_study
//
//  Created by wens07 on 8/5/13.
//  Copyright (c) 2013 wens07. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

#define MAXCOL 20
#define MAXROW 20
int arr[MAXCOL][MAXROW];

int main(int argc, const char* argv[])
{
    int row, col, search;
    int r, c;

    while (scanf("%d %d %d", &row, &col, &search) != EOF)
    {
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                scanf("%d", &arr[i][j]);
            }
        }
        
        r = 0;
        c = col - 1;
        int val = arr[r][c];
        
        while (r < row && c >= 0)
        {
            if (val == search)
            {
                printf("find %d : true", val);
                return 0;
            }
            else if (val > search)
            {
                val = arr[r][--c];
            }
            else if (val < search)
            {
                val = arr[++r][c];
            }
            
            
        }
        
        printf("find %d : false", val);
    }
    return 0;
}
