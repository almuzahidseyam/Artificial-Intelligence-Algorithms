#include <bits/stdc++.h>
using namespace std;

#define DISCONNECTED -1
int num_of_node, num_of_edge, graph[30][30], pathCost[30];
void init_Heuristic();

struct Node
{
    int from, to;
    int cost;
};
struct CompareNode
{
    bool operator()(Node &n1, Node &n2)
    {
        if (n1.cost > n2.cost)
            return true;
        return false;
    }
};
map<int, int> Heuristic;

priority_queue<Node, vector<Node>, CompareNode> PQ;

vector<Node> path;

void AStarSearch(char x, char y)
{

    int source = x - 64;
    int destination = y - 64;

    if(x == 'G'){
        source = 6;
    }

    if(y == 'G'){
        destination = 6;
    }


    init_Heuristic();
    for (int i = 1; i <= num_of_node; i++)
    {
        if (graph[source][i] != DISCONNECTED)
        {
            Node n;
            n.from = source;
            n.to = i;
            n.cost = graph[source][i] + Heuristic[i];
            pathCost[i] = graph[source][i];
            PQ.push(n);
        }
    }
    while (!PQ.empty())
    {
        Node tmp = PQ.top();
        path.push_back(tmp);
        if (tmp.to == destination)
            break;
        PQ.pop();
        for (int i = 1; i <= num_of_node; i++)
        {
            if (graph[tmp.to][i] != DISCONNECTED)
            {
                Node n;
                n.from = tmp.to;
                n.to = i;
                n.cost = pathCost[tmp.to] + graph[tmp.to][i] + Heuristic[i];
                pathCost[i] = pathCost[tmp.to] + graph[tmp.to][i];
                PQ.push(n);
            }
        }
    }
}
int main()
{

    int a, b;
    int c;
    char source, destination;

    cout << "Enter Node: " << endl;
    cin >> num_of_node;
    cout << "Enter Edge: " << endl;
    cin >> num_of_edge;
    for (int i = 1; i <= num_of_node; i++)
        for (int j = 1; j <= num_of_node; j++)
            graph[i][j] = DISCONNECTED;

    for (int i = 0; i < num_of_edge; i++)
    {
        char aa, bb;
        cin >> aa >> bb >> c;
        a = aa - 64;
        b = bb - 64;

        if(aa == 'G'){
            a = 6;
        }

        if(bb == 'G'){
            b = 6;
        }

        graph[a][b] = graph[b][a] = c;
    }
    cout << "Enter source: " << endl;
    cin >> source;
    cout << "Enter destination: " << endl;
    cin >> destination;
    AStarSearch(source, destination);
    //cout << "Our Output is = " << endl;

    vector <char> vv;
    int Cost = 0;
    for (int i = 0; i < path.size(); i++)
    {
        char aaa = char(path.at(i).from + 64);
        char bbb = char(path.at(i).to + 64);

        if(aaa == 'F')
            aaa = 'G';
        if(bbb == 'F')
            bbb = 'G';

        //cout << aaa;
        //cout << " -> ";
        //cout << bbb;
        //cout << " = " << path.at(i).cost << endl;
        vv.push_back(aaa);
        vv.push_back(bbb);
        Cost = path.at(i).cost;
    }

    vector <char> Ans;

    map <char, int> Map;

//    cout << "vvsize= " << vv.size() << endl;
//
//    for(auto x : vv)
//        cout << x << ' ';
//    cout << endl;

    for(int i = (int)vv.size() -1; i>=0; i--){

            if(vv[i] == 'A'){
                Ans.push_back('A');
                break;
            }
        if(Map[vv[i]] == 0){
            Map[vv[i]]++;
            Ans.push_back(vv[i]);
            //break;
        }else{
            continue;
        }
    }

    reverse(Ans.begin(), Ans.end());

    //cout << "Anssize= " << Ans.size() << endl;

    int nn = Ans.size();
    cout << endl;
    cout << "Shortest cost Route = ";
    for(int i = 0; i < nn; i++)
    {

        if(i < nn -1){cout << Ans[i] << " -> ";}
        else cout << Ans[i] << endl;
    }
    cout << "Cost = " << Cost << endl;
    return 0;
}
void init_Heuristic()
{

    Heuristic[1] = 11;
    Heuristic[2] = 6;
    Heuristic[3] = 99;
    Heuristic[4] = 1;
    Heuristic[5] = 7;
    Heuristic[6] = 0;

}

/*

6 6

A B 2
A E 3
B C 1
B G 9
E D 6
D G 1


6 6
1 2 2
1 5 3
2 3 1
2 6 9
5 4 6
4 6 1



*/
