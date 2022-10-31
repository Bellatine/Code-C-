#include <bits/stdc++.h>
using namespace std;

int n;
void chuyen(int x,int a, int b,int c)
{
	if(x==1) cout<<char(a+64)<<"----"<<char(b+64)<<endl;
	else{
		chuyen(x-1,a,c,b);
		chuyen(1,a,b,c);
		chuyen(x-1,c,b,a);
	}
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("thapHN.inp","r",stdin);
    //freopen("thapHN.out","w",stdout);
	cin>>n;
	chuyen(n,1,3,2);
}
