//
//  hero_报数游戏2.cpp
//  acm_project
//
//  Created by wens on 1/11/14.
//  Copyright (c) 2014 wens07. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <list>


using namespace std;



bool is_remove(char value)
{
    return value == 0;
}

int getNumber(int   n)
{
    int sum = 1;
    
    if (n <= 3)
    {
        return sum;
    }
    else
    {
        for (int size = 4; size <= n; ++size)
        {
            list<char> peple(n, 1);
            
            while (peple.size() > 3)
            {
                
                for (int i = 0; i < peple.size(); ++i)
                {
                    if (i % 2 == 1)
                    {
                        peple.assign(i, 0);
                    }
                    
                }
                
                remove_if(peple.begin(), peple.end(), is_remove);
                
            }
            
            if (peple.size() == 3)
                sum ++;
        }
        
        return sum;
    }
    
    
}

int main()
{
    cout<<getNumber(10)<<endl;
    return 0;
}