#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
vector<int> edges[MAX];


bool visited[MAX];
void bfs()
{
    queue<int>q;
    q.push(1);
    visited[1]=true;
    while(!q.empty() )
    {
    cout << q.front() << " ";
    for(auto it : edges[q.front()])
    {
        if(!visited[it])
        {
           q.push(it);
           visited[it] =1 ;
        }
    }
    q.pop();
   }

}

int main()
{
    edges[1].emplace_back(2);
    edges[2].emplace_back(1);
    edges[1].emplace_back(3);
    edges[3].emplace_back(1);
    edges[2].emplace_back(4);
    edges[4].emplace_back(2);
    edges[3].emplace_back(4);
    edges[4].emplace_back(3);
    bfs();

    return 0;
}
