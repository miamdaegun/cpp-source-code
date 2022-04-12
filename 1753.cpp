#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF=987654321;

vector<pair<int, int>> node[20001];

void bfs(int start, int V, int E, vector<int> &way)
{
    queue<int> q;
    int newnode, des, newwei;

    way[start]=0;
    q.push(start);

    while(!q.empty())
    {
        newnode=q.front();
        q.pop();
        for(int i=0 ; i<node[newnode].size() ; i++)
        {
            des=node[newnode][i].first;
            newwei=node[newnode][i].second;

            if(way[des]>way[newnode]+newwei)
            {
                way[des]=way[newnode]+newwei;
                q.push(des);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E, K, wei;
    int start, end;
    vector<int> way;

    cin>>V>>E;
    cin>>K;

    way.assign(V+1, INF);

    for(int i=0 ; i<E ; i++)
    {
        cin>>start>>end>>wei;
        node[start].emplace_back(make_pair(end, wei));
    }

    bfs(K, V, E, way);

    for(int i=1 ; i<=V ; i++)
    {
        if(way[i]==INF) cout<<"INF\n";
        else cout<<way[i]<<"\n";
    }
    return 0;
}