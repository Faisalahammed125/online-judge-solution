#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,m,n;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>m>>n;
        int ans;
        if(m==1||n==1)ans=m*n;
        else if(m==2||n==2)
        {
            int mx=max(m,n);
            int temp=mx%4;
            if(temp!=0)mx+=(temp&1)?1:2;
            ans=mx;
        }
        else ans=ceil(1.0*m*n/2);
        printf("Case %d: %d\n",i,ans);
    }
}
