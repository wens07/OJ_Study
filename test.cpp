#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int main()
{
    fstream file("input.txt");
    cout<<file.rdbuf()<<endl;

    return 0;

}
