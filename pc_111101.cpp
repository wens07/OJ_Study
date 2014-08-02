//
//  pc_111101.cpp
//  code_study
//
//  Created by wens07 on 16/5/13.
//  Copyright (c) 2013 wens07. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;


#define MAX_SIZE 1001

int result[MAX_SIZE];
int ans_index[MAX_SIZE];

struct elephant
{
    int w;
    int iq;
    int index;
};

bool sort_predicate(elephant pa, elephant pb)
{
    if (pa.iq > pb.iq)
        return true;
    else if (pa.iq == pb.iq)
    {
        if (pa.w < pb.w)
            return true;
        else
            return false;
    }
    else
        return false;
}

void print_ans(int index, vector<elephant> const &vc)
{
    if (ans_index[index] > -1)
        print_ans(ans_index[index], vc);
    
    cout<<vc[index].index<<endl;
}



int main(int argc, const char* argv[])
{
    fstream cin("/Users/wens07/Desktop/code_study/test.txt");
    
    elephant elep;
    int num = 0;
    vector<elephant> vc;
    fill_n(result, sizeof(result)/sizeof(int), 1);
    fill_n(ans_index, sizeof(ans_index)/sizeof(int), -1);

    
    while (cin>>elep.w>>elep.iq)
    {
        elep.index = ++num;
        vc.push_back(elep);
        
    }
    
    sort(vc.begin(), vc.end(), sort_predicate);
    
    int max = 0, max_index = 0;
    int tmp;
    for (int i = 1; i < num; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            tmp = 0;
            
            if (vc[i].w > vc[j].w && vc[i].iq < vc[j].iq)
            {
                tmp = result[j] + 1;
            }
            
            if (tmp >= result[i])
            {
                result[i] = tmp;
                ans_index[i] = j;
            }
            
            if (result[i] > max)
            {
                max = result[i];
                max_index = i;
            }

        }

    }
    
    cout<<max<<endl;
  
    print_ans(max_index, vc);
    
    
    
    return 0;
}