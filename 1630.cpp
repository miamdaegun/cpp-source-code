#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
    vector<string> v;
    map<string, int> mp;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin>>N>>M;
    for(int i=0 ; i<N ; i++)
    {
        string A;
        cin>>A;
        v.push_back(A);
        mp[A]=i+1;
    }
    for(int i=0 ; i<M ; i++)
    {
        string b;
        cin>>b;
        char a=b.front();
        if('A'<=a && 'Z'>=a)
        {
            cout<<mp[b]<<"\n";
        }
        else
        {
            int c=stoi(b);
            cout<<v[c-1]<<"\n";
        }
    }
    return 0;
}
