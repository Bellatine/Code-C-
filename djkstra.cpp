#include<bits/stdc++.h>
#define maxn 10004
#define maxa 1000006
using namespace std;
vector <int> b[maxn];
queue <int> q;
int a[maxn],f[maxn],trc[maxn],v[maxn][maxn],m,n,z;
bool kt[maxn];
void input()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("dijkstra.inp","r",stdin);
    //freopen("dijkstra.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        cin>>v[x][y];
        b[x].push_back(y);
    }
    for(int i=1;i<=n;i++)
    {
        a[i]=maxa;
        trc[i]=maxa;
    }
}
void upheap(int p) // thêm một giá trị vào heap
{
    int j=p/2;
    if(p>1&& a[j]>a[p])
    {
        swap(a[j],a[p]);
        swap(f[j],f[p]);
        upheap(j);
    }
}
void downheap(int p) // bỏ một giá trị khỏi heap
{
    int i=p*2;
    int j=p*2+1;
    if(i<=z)
    {
        if(a[i]>a[j]) i=j;
        if(a[p]>a[i])
        {
            swap(a[p],a[j]);
            swap(f[p],f[j]);
            downheap(i);
        }
    }
}
void dijkstra(int u)
{
    int t=0;
    z++;
    a[z]=0;
    f[z]=u;
    trc[u]=0;
    while (z>0)
    {
        int t=f[1];
        a[1]=a[z];
        f[1]=f[z];
        a[z]=maxa;
        z--;
        downheap(1);
        for(int i=0;i<b[t].size();i++)
            if(trc[b[t][i]]>trc[t]+v[t][b[t][i]])
            {
                trc[b[t][i]]=trc[t]+v[t][b[t][i]];
                z++;
                a[z]=trc[b[t][i]];
                f[z]=b[t][i];
                upheap(z);

            }

    }
}
void output()
{
    for(int i=1;i<=n;i++)
        cout<<trc[i]<<" ";
}
int main()
{
    input();
    dijkstra(1);
    output();

}
