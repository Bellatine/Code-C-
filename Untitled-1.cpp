#include<bits/stdc++.h>
#define maxn 10004
using namespace std;
int a[maxn][maxn],n,m,k;
int main()
{
    cin>>m>>n;                                //nhập m,n
    for(int i=1;i<=m;i++)                       //nhập ma trận a có m hàng n cột
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    cin>>k;                                     //nhập só k
    for(int i=1;i<n;i++)                        //kiểm trả tại phần tử thứ i ở dòng k
        for(int j=i+1;j<=n;j++)                                                     //có ptu nào sau nó mà nhỏ hơn nó không
            if(a[k][i]>a[k][j])                    //nếu có
            {
                int z=a[k][i];        // đổi chỗ 2 ptu sai vị trí vì dòng k không giảm nên nếu số đứng sau nhỏ hơn số đứng trc thì đổi chỗ 2 số
                a[k][i]=a[k][j];
                a[k][j]=z;
            }
                for(int i=1;i<=m;i++)           //in lại mảng A
    {
        for(int j=1;j<=n;j++)
         cout<<a[i][j]<<" ";
         cout<<endl;
    }
    int maxx=m;
    if(m<n) maxx=n;
    for(int i=1;i<maxx;i++)
        for(int j=i+1;j<=maxx;j++)
            {
                int z=a[i][j];
                a[i][j]=a[j][i];
                a[j][i]=z;
            }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m ;j++)
         cout<<a[i][j]<<" ";
         cout<<endl;
    }
}
