#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    double d,v,u;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>d>>v>>u;
        double t1=d/u;
        double t2=d/sqrt(u*u-v*v);
        if(v>=u||t1==t2)
             printf("Case %d: can't determine\n", i);
        else
            printf("Case %d: %.3lf\n", i, t2-t1);
    }
}
