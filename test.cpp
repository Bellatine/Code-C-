#include<bits/stdc++.h>
#include<cstring>
#define maxn 10004
using namespace std;
vector<int> a[maxn];
vector<int> b[9600000];
vector<int> q[maxn];
queue <int> p;
int n,f[maxn],dem=0,cs[maxn],vt=0,f1[maxn],dem1=0,kc[maxn],trc[maxn];
string s[maxn],st1,st2;
bool kq;
string sort(string st)
{
    for(int i=0;i<5;i++)
        for(int j=i+1;j<5;j++)
            if(st[i]>st[j]) swap(st[i],st[j]);
    return st;
}
void sau(int v)
{
    vt++;
    cs[vt]=v;
}
void lt(int v)
{
    f[v]=dem;
    for(int i=0;i<q[v].size();i++)
        if(f[q[v][i]]==0)
            lt(q[v][i]);
    sau(v);

}
void dfs()
{
    dem++;
    for(int i=1;i<=n;i++)
        if(f[i]==0) lt(i);
}
void lienthong(int v)
{
    f1[v]=dem1;
    for(int i=0;i<a[v].size();i++)
        if(f1[a[v][i]]==0)
         lienthong(a[v][i]);
}
void lienthongmanh()
{
    for(int i=n;i>=1;i--)
        if(f1[cs[i]]==0)
    {
        dem1++;
        lienthong(cs[i]);
    }
}
void bfs(int s)
{
    kc[s]=0;
    p.push(s);
    while(p.size()!=0)
    {
        int u=p.front(); p.pop();
        for(int i=0;i<a[u].size();i++)
            if(kc[a[u][i]]==maxn)
        {
            p.push(a[u][i]);
            kc[a[u][i]]=kc[u]+1;
            trc[a[u][i]]=u;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("sgb.inp","r",stdin);
    cin>>n;
    cin>>st1>>st2;
    int s1,s2;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        if(s[i]==st1) s1=i;
        if(s[i]==st2) s2=i;
    }
    int maxs=1;
    for(int i=1;i<=n;i++)
    {
        int z=0;
        string c=sort(s[i]);
        for(int j=0;j<5;j++)
            z=z*26+(c[j]-'a');
        b[z].push_back(i);
    }
    int dem2=0;
    for(int i=1;i<=n;i++)
    {
        for(int j='a';j<='z';j++)
        {
            string c;
            for(int t=1;t<5;t++) c=c+s[i][t];
            int z=0;
            c=c+char(j);
            c=sort(c);
            for(int j=0;j<5;j++)
            z=z*26+(c[j]-'a');
            if(b[z].size()!=0)
                for(int j=0;j<b[z].size();j++)
                    if(i!=b[z][j])
                    {
                        dem2++;
                        a[i].push_back(b[z][j]);
                        q[b[z][j]].push_back(i);
                    }
        }
    }
    //cout<<mins;
    for(int i=1;i<=n;i++) kc[i]=maxn;
    for(int i=1;i<=n;i++)
        f[i]=0;
    for(int i=1;i<=n;i++)
        f1[i]=0;
    dfs();
    lienthongmanh();
    cout<<"so tpltm la: "<<dem1<<endl;
    cout<<"cac dinh cung tpltm voi "<<st1<<" la: ";
    for(int i=1;i<=n;i++)
        if(f1[i]==f1[s1]&&i!=s1) cout<<s[i]<<" ";
    cout<<endl;
    bfs(s1);
    while(s2!=s1)
    {
        cout<<s[s2]<<"<--";
        s2=trc[s2];
    }
    cout<<s[s1];

}
