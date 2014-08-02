//
//  hero_stringtoint.cpp
//  acm_project
//
//  Created by wens07 on 29/5/13.
//  Copyright (c) 2013 wens07. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <iostream>


using namespace std;

int main(int argc, const char* argv[])
{
    freopen("/Users/wens07/Documents/codes/c++/acm_test/input.txt", "r", stdin);
    
    char *str = "-01234000";
   
    
    
        int index = 0;
        while (str[index] == ' ') index++;
        
        while (str[index] == '0') index++;
        
        cout<<atoi(str)<<endl;
    
    
    return 0;
}