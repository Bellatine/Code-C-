bai2
#include<stdio>
#define maxn 10004
int a[maxn],n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;;i++)
        scanf("%d",&a[i]);
    int l=1,r=n;
    while(l<r)
    {
        int z=a[l];
        a[l]=a[r];
        a[r]=z;
        l++;
        r--;
    }
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
}