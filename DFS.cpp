#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
vector <int> a[maxn];
int n,k,trc[maxn],sa[maxn],tt=1;
bool f[maxn];
void truoc(int v)
{
    trc[v]=tt;
    tt++;
}
void sau(int v)
{
    sa[v]=tt;
    tt++;
}
void tham(int v)
{
    f[v]=1;
    truoc(v);
    for(int i=0;i<a[v].size();i++)
        if(f[a[v][i]]==0)
            tham(a[v][i]);
    sau(v);
}
void dfs()
{
    for(int i=0;i<n;i++)
        if(f[i]==0) tham(i);
}
//enum canh{"TOI","NGUOC","NGANG"};
string ktra(int u, int v)
{
    if(trc[u]<trc[v]&&sa[v]<sa[u]) return "TOI";
    else if(trc[v]<trc[u]&&sa[u]<sa[v]) return "NGUOC";
    else if(trc[v]<trc[u]&&sa[v]<sa[u]) return "NGANG";
}
void phanloai()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<a[i].size();j++)
            cout<<i<<"->"<<a[i][j]<<":"<<(string)ktra(i,a[i][j])<<endl;
}
int main()
{
    freopen("dfs.inp","r",stdin);
    //freopen("dfs.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        //a[y].push_back(x);
    }
    dfs();
    for(int i=0;i<=n;i++)
        cout<<trc[i]<<" ";
    cout<<endl;
    for(int i=0;i<=n;i++)
        cout<<sa[i]<<" ";
    cout<<endl;
    phanloai();
}
