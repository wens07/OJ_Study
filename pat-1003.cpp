#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

const int MAXNUM = 501;

struct node
{
    short int id;
    short int cost;
};

short int teamnum[MAXNUM];
short int con[MAXNUM][MAXNUM];


int main()
{
    short int N, M, C1, C2;

    while(scanf("%hd %hd %hd %hd", &N, &M, &C1, &C2) != EOF)
    {
        memset(teamnum, 0, sizeof(teamnum));
        memset(con, 0, sizeof(con));
        short int citynum = N;
        short int roadnum = M;
        while(N--)
        {
            scanf("%hd", &teamnum[citynum - N - 1]);

        }

        while(M--)
        {
            short int t1, t2, len;
            scanf("%hd %hd %hd", &t1, &t2, &len);

            con[t1][t2] = len;
        }

        node start;
        start.id = C1;
        start.cost = 0;

        vector<node> a;

        a.push_back(start);

    }
    return 0;
}
