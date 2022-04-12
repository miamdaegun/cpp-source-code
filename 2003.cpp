#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;

    int front=0, rear=0;
    int N,M;
    int num, count=0, temp=0;

    cin>>N>>M;

    for(int i=0 ; i<N ; i++)
    {
        cin>>num;
        v.emplace_back(num);
    }

    while(rear<=N)
    {
        if(temp>M)
        {
            temp-=v[front];
            front++;
        }
        else if(temp<M)
        {
            temp+=v[rear];
            rear++;
        }

        else
        {
            count++;
            temp+=v[rear];
            rear++;
        }
    }

    cout<<count;
    return 0;
}