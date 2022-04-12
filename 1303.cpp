#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;

const int dx[4]={0, 0, 1, -1};
const int dy[4]={1, -1, 0, 0};

void bfs(int i, int j, vvi human, vvb &visit, int N, int M, int &pw, int color)
{
    queue<pair<int, int>> q;
    int nx, ny, popx, popy;
    int people=1;

    visit[i][j]=true;
    q.push({i, j});

    while(!q.empty())
    {
        popx=q.front().first;
        popy=q.front().second;
        q.pop();
        
        for(int i=0 ; i<4 ; i++)
        {
            nx=popx+dx[i];
            ny=popy+dy[i];

            if(nx>=0 && nx<N && ny>=0 && ny<M)
            {
                if(human[nx][ny]==color && !visit[nx][ny])
                {
                    q.push({nx, ny});
                    visit[nx][ny]=true;
                    people++;
                }
            }
        }
    }
    pw+=(int)pow(people, 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vvi human;
    vvb visit;

    int N,M;
    int wpw=0, bpw=0;
    string col;

    cin>>M>>N;

    human.assign(N, vector<int> (M));
    visit.assign(N, vector<bool> (M, false));

    for(int i=0 ; i<N ; i++)
    {
        cin>>col;
        for(int j=0 ; j<M ; j++)
        {
            if(col[j]=='W')
            {
                human[i][j]=0;
            }
            else
            {
                human[i][j]=1;
            }
        }
    }

    for(int i=0 ; i<N ; i++)
    {
        for(int j=0 ; j<M ; j++)
        {
            if(human[i][j]==0 && !visit[i][j])
            {
                bfs(i, j, human, visit, N, M, wpw, 0);
            }
            else if(human[i][j]==1 && !visit[i][j])
            {
                bfs(i, j, human, visit, N, M, bpw, 1);
            }
        }
    }

    cout<<wpw<<" "<<bpw<<"\n";
    return 0;
}