#include<bits/stdc++.h>
#define maxn 10005
using  namespace std;
vector <int> a[maxn];
string st[maxn],st1,st2;
int n,kc[maxn],trc[maxn],x,y,d,dau[maxn];
queue <int> q;
void input()
{
    freopen("sgb.inp","r",stdin);
    cin>>n;
    cin>>st1>>st2;
    for(int i=1;i<=n;i++)
    {
        cin>>st[i];
        kc[i]=maxn;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int dem=0;
            for(int z=0;z<5;z++)
                if(st[i][z]!=st[j][z]) dem++;
            if (dem==1) {a[i].push_back(j); a[j].push_back(i);}
        }
    }

}
//void bfs(int s)
void bfs(int s)
{
    trc[s]=-1;
    kc[s]=0;
    q.push(s);
    while(q.size()!=0)
    {
        int u=q.front(); q.pop();
        for(int i=0;i<a[u].size();i++)
            if(kc[a[u][i]]==maxn)
        {
            //dau[a[u][i]]=d;
            q.push(a[u][i]);
            kc[a[u][i]]=kc[u]+1;
            trc[a[u][i]]=u;
        }
    }
}
void dfs(int u)
{
    dau[u]=d;
    for(int j=0;j<a[u].size();j++)
        if(dau[a[u][j]]==0)
        {
            dfs(a[u][j]);
        }
}
void xuli()
{
    for(int i=1;i<=n;i++) dau[i]=0;
    for(int i=1;i<=n;i++)
    if(dau[i]==0)
    {
        //cout<<i<<" ";
        d++;
        dfs(i);
    }
    cout<<d<<endl;
}
void xuli1()
{
    for(int i=1;i<=n;i++)  kc[i]=maxn;
    for(int i=1;i<=n;i++)
    {
        if(st[i]==st1) x=i;
        if(st[i]==st2) y=i;
    }
    bfs(y);
    //cout<<dau[x]<<" "<<dau[y];
    if(dau[x]==dau[y])
    {
        while(x!=y)
        {
            cout<<st[x]<<" ";
            x=trc[x];
        }
        cout<<st[y];
    }
    else cout<<"ko co duong di";
}
int main()
{
    input();
    xuli();
    xuli1();
    //cout<<x<< " "<<y;
}
