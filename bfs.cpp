#include<bits/stdc++.h>
#define maxn 10004
using namespace std;
queue <int> q;
int m,n,kc[maxn];
vector <int> a[maxn];
void input()
{
    freopen("bfs.inp","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
    }
    for(int i=1;i<=n;i++) kc[i]=maxn;
}
void bfs(int s)
{
    kc[s]=0;
    q.push(s);
    while(q.size()!=0)
    {
        int u=q.front(); q.pop();
        for(int i=0;i<a[u].size();i++)
            if(kc[a[u][i]]==maxn)
        {
            q.push(a[u][i]);
            kc[a[u][i]]=kc[u]+1;
        }
    }
}
int main()
{
    input();
    bfs(1);
    for(int i=1;i<=n;i++) cout<<kc[i]<<" ";
}
