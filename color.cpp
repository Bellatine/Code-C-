#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
vector <int> a[maxn];
int n,m,c[maxn],cs[maxn],cl=0,mau[maxn];
bool kt[maxn];
void sortt(int l, int r)
{
    if(l<r)
    {
        int i=l,j=r;
        int m=c[(i+j)/2];
        while(c[i]<m) i++;
        while(c[j]>m) j--;
        if(i<=j)
        {
            int z1=c[i];
            c[i]=c[j];
            c[j]=z1;
            int z2=cs[i];
            cs[i]=cs[j];
            cs[j]=z2;
            i++;
            j--;
        }
        if(r>i) sortt(i,r);
        if(l<j) sortt(l,j);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        c[i]=a[i].size();
        cs[i]=i;
    }
    sortt(1,n);
    bool check=0;
    for(int i=1;i<=n;i++) mau[i]=-1;
    while(check==0)
    {
        cl++;
        for(int i=n;i>=1;i--)
        if(kt[cs[i]]==0)
        {
            kt[cs[i]]==1;
            for(int j=0;j<a[cs[i]].size();j++) kt[a[cs[i]][j]]=1;
            mau[cs[i]]=cl;
        }
        check=1;
        for(int i=1;i<=n;i++)
            if(mau[i]==-1) {kt[i]=0; check=0;}
    }
    for(int i=1;i<=n;i++)
        cout<<mau[i]<<" ";
}
