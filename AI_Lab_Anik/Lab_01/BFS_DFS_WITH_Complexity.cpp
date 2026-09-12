#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
vector<int> edges[MAX];
int bfs_count=0;
int dfs_count=0;


bool visited[MAX];
void bfs()
{
    queue<int>q;
    q.push(1);
    visited[1]=true;
    while(!q.empty() )
    {

    if(q.front()==1)
        cout << "A " ;

        if(q.front()==2)
        cout << "B " ;

        if(q.front()==3)
        {
            cout << "C " ;
        }
        if(q.front()==4)
        cout << "D " ;

        if(q.front()==5)
        cout << "E " ;

        if(q.front()==6)
        cout << "F " ;


    for(auto it : edges[q.front()])
    {
        if(!visited[it])
        {
           q.push(it);
           visited[it] =1 ;
        }
        bfs_count=bfs_count+1;
    }
    q.pop();
   }


}


bool vis[MAX];
void dfs(int node)
{
    vis[node]=true ;
    if(node==1)
        cout << "A " ;

        if(node==2)
        cout << "B " ;

        if(node==3)
        {
            cout << "C " ;
        }


        if(node==4)
        cout << "D " ;

        if(node==5)
        cout << "E " ;

        if(node==6)
        cout << "F " ;



    for(auto it : edges[node])
    {
        if(!vis[it])
        {
            dfs(it);

        }
        dfs_count=dfs_count+1;
    }

}

int main()
{
    edges[1].emplace_back(2);
    edges[1].emplace_back(3);


    edges[2].emplace_back(4);
    edges[2].emplace_back(5);

    edges[3].emplace_back(1);
    edges[3].emplace_back(6);

    edges[4].emplace_back(2);

    edges[5].emplace_back(2);
    edges[5].emplace_back(6);


    edges[6].emplace_back(5);
    edges[6].emplace_back(3);



    cout <<"BFS"<<endl;
    bfs();
    cout <<""<<endl;
    cout <<"DFS"<<endl;
    dfs(1);



    return 0;
}

