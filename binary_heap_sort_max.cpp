#include<bits/stdc++.h>
#define maxn 10004
using namespace std;
int a[maxn],n;
void upheap(int i)
{
    int j=i/2;
    if(i>1&&a[j]<a[i])
    {
        swap(a[i],a[j]);
        upheap(j);
    }
}
void downheap(int i)
{
    int x=i*2,y=i*2+1;
    if(x<=n)
    {
        if(a[x]<a[y]) x=y;
        if(a[i]<a[x])
        {
            swap(a[i],a[x]);
            downheap(x);
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) a[i]=maxn;
    for(int i=1;i<=n;i++)
    {
        int u;
        cin>>u;
        a[i]=u;
        upheap(i);
    }
    int m=n;
    for(int i=1;i<=m;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    for(int i=1;i<=m;i++)
    {
        //a[n+1]=maxn;
        cout<<a[1]<<" ";
        a[1]=a[n];
        downheap(1);
        n--;
    }
}
