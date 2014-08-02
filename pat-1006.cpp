//
//  pat-1006.cpp
//  acm_project
//
//  Created by wens on 7/19/14.
//  Copyright (c) 2014 wens07. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>


class person
{
public:
    char id[16];
    char signin_time[10];
    char signout_time[10];
};


bool sort_signin_time(person p1, person p2)
{
    if (strcmp(p1.signin_time, p2.signin_time) >= 0) {
        return false;
    }
    else
        return true;
}

bool sort_signout_time(person p1, person p2)
{
    if (strcmp(p1.signout_time, p2.signout_time) > 0) {
        return true;
    }
    else
        return false;
    
}



int main()
{
    freopen("/Users/wens/Desktop/code_study/acm_project/acm_project/input.txt", "r", stdin);
    int num;
    while (scanf("%d", &num) != EOF)
    {
        std::vector<person> vec;
        
        for (int i = 0; i < num; ++i)
        {
            person temp;
            scanf("%s %s %s", temp.id, temp.signin_time, temp.signout_time);
            
            vec.push_back(temp);
        }
        
        std::sort(vec.begin(), vec.end(), sort_signin_time);
        printf("%s ", (*vec.begin()).id);
        std::sort(vec.begin(), vec.end(), sort_signout_time);
        printf("%s\n", (*vec.begin()).id);
        
    
    }
    
    fclose(stdin);
   
}