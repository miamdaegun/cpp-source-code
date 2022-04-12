#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int f, int s, int g, int u, int d)
{
    int news, newb;
    int flag = 0;
    queue<pair<int, int>> q;
    vector<bool> visit;
    visit.assign(f+1, false);

    q.push({ s, 0 });
    visit[s] = true;
    while (!q.empty())
    {
        news = q.front().first;
        newb = q.front().second;
        q.pop();
        if (news == g)
        {
            cout << newb;
            flag = 1;
            break;
        }

        if (news + u <= f && news + u >= 1 && !visit[news + u])
        {
            if (news+u == g)
            {
                cout << newb+1;
                flag = 1;
                break;
            }
            visit[news + u] = true;
            q.push({ news + u, newb + 1 });
        }
        if (news - d <= f && news - d >= 1 && !visit[news - d])
        {
            if (news-d == g)
            {
                cout << newb+1;
                flag = 1;
                break;
            }
            visit[news - d] = true;
            q.push({ news - d, newb + 1 });
        }
    }
    if (flag == 0)
    {
        cout << "use the stairs\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    bfs(F, S, G, U, D);
    return 0;
}