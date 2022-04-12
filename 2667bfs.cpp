//bfs 연습
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int dx[4]={0, 0, 1, -1};
const int dy[4]={1, -1, 0, 0};

void bfs(int i, int j, int &count, vector<vector<int>> house, vector<vector<bool>> &visit, int size)
{
    int nx, ny, popx, popy;
    queue<pair<int, int>> q;
    count++;
    q.push({i, j});
    visit[i][j]=true;

    while(!q.empty())
    {
        popx=q.front().first;
        popy=q.front().second;
        q.pop();
        for(int i=0 ; i<4 ; i++)
        {
            nx=popx+dx[i];
            ny=popy+dy[i];

            if(nx>=0 && nx<size && ny>=0 && ny<size)
            {
                if(house[nx][ny] && !visit[nx][ny])
                {
                    visit[nx][ny]=true;
                    q.push({nx, ny});
                    count++;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> house;
    vector<vector<bool>> visit;
    vector<int> dong;

    int size, count;
    string col;

    cin>>size;

    house.assign(size, vector<int> (size));
    visit.assign(size, vector<bool> (size, false));

    for(int i=0 ; i<size ; i++)
    {
        cin>>col;
        for(int j=0 ; j<size ; j++)
        {
            house[i][j]=(int)col[j]-48;
        }
    }
    for(int i=0 ; i<size ; i++)
    {
        for(int j=0 ; j<size ; j++)
        {
            if(house[i][j] && !visit[i][j])
            {
                count=0;
                bfs(i, j, count, house, visit, size);
                dong.emplace_back(count);
            }
        }
    }
    sort(dong.begin(), dong.end());
    cout<<dong.size()<<"\n";
    for(int i=0 ; i<dong.size() ; i++)
    {
        cout<<dong[i]<<"\n";
    }
    return 0;
}