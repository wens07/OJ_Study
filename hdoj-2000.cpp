#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    ifstream cin("input.txt");

    string str;
    while(getline(cin, str))
    {
        sort(str.begin(), str.end());
        string::iterator iter = str.begin();
        for (; iter != str.end(); ++iter)
        {
            if (iter != str.begin())
                cout<<" ";
            cout<<*iter;
        }
        cout<<endl;
    }
    return 0;
}
