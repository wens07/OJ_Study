#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<string>


using namespace std;


int main()
{
    ifstream cin("input.txt");
    int m, n;
    cin>>n>>m;

    map<string, vector<string> > treemap;
    string id;
    int k;

    while(m--)
    {
        vector<string> strvec;

        cin>>id>>k;
        string node;
        while(k--)
        {
            cin>>node;
            strvec.push_back(node);
        }

        treemap[id] = strvec;
    }

    vector<string> queue;
    vector<string> temp;

    if (treemap["01"].size() == 0)
    {
        cout<<'1'<<endl;
        return 0;
    }
    else
    {
        cout<<'0';
        queue.swap(treemap["01"]);
        int size, index;
        
        while (true)
        {
            size = queue.size();
            index = 0;

            while(!queue.empty())
            {

               if (treemap.find(queue.back()) != treemap.end())
               {
                   index ++;
                   for (int i = 0; i < treemap[queue.back()].size(); ++i)
                       temp.push_back(treemap[queue.back()][i]);
               }
               queue.pop_back();
            }

            cout<<" "<<size-index;
            queue.swap(temp);

            if (queue.size() == 0)
                break;
        }

        cout<<endl;
        
        
    }


    return 0;
}
