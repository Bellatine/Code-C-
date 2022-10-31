#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
vector <int> a[maxn];
vector <int> b[maxn];
vector <int> c[maxn];
int m,n,vt=1,sau[maxn],dem=0,f1[maxn];
bool f[maxn];
void sauu(int v)
{
    sau[vt]=v;
    //s[v]=vt;
    vt++;
}
void lienthong(int v)
{
    f[v]=1;
    for(int i=0;i<b[v].size();i++)
        if(f[b[v][i]]==0)
            lienthong(b[v][i]);
    sauu(v);
}
void dfs()
{
    for(int i=0;i<n;i++)
        if(f[i]==0) lienthong(i);
}
void input()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        b[y].push_back(x);
    }
}
void lienthongmanh(int v)
{
    f1[v]=dem;
    c[dem].push_back(v);
    for(int i=0;i<a[v].size();i++)
        if(f1[a[v][i]]==0)
            lienthongmanh(a[v][i]);
}
void kiemtra()
{
    for(int i=n;i>=1;i--)
        if(f1[sau[i]]==0)
        {
            dem++;
            lienthongmanh(sau[i]);
        }
}
void output()
{
    cout<<dem<<endl;
    for(int i=0;i<n;i++)
        if(c[i].size()>0)
    {
        for(int j=0;j<c[i].size();j++)
            cout<<c[i][j]<<" ";
        cout<<endl;
        //for(int i=1;i<=n;i++) cout<<sau[i]<< " ";
    }
     //for(int i=1;i<=n;i++) cout<<sau[i]<< " ";
     for(int i=0;i<n;i++) cout<<f1[i]<<" ";
}
int main()
{
    freopen("dtltmanh.inp","r",stdin);
    //freopen("dtltmanh.out","w",stdout);
    input();
    dfs();
    for(int i=0;i<n;i++) f1[i]=0;
    kiemtra();
    output();
}
