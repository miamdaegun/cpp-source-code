#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int dx[4]={0, 0, 1, -1};
const int dy[4]={1, -1, 0, 0};

void dfs(int &count, int x, int y, vector<vector<int>> house, vector<vector<bool>> &visit, int size)
{
    count++;
    int nx, ny;
    visit[x][y]=true;
    for(int i=0 ; i<4 ; i++)
    {
        nx=x+dx[i];
        ny=y+dy[i];
        if(nx>=0 && nx<size && ny>=0 && ny<size)
        {
            if(house[nx][ny] && !visit[nx][ny])
            {
                dfs(count, nx, ny, house, visit, size);
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

    int size, count, line;
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
                dfs(count, i, j, house, visit, size);
                dong.emplace_back(count);
            }
        }
    }
    
    sort(dong.begin(), dong.end());
    line=dong.size();
    cout<<line<<"\n";
    for(int i=0 ; i<line ; i++)
    {
        cout<<dong[i]<<"\n";
    }
    return 0;
}
