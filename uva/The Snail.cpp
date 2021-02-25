#include<bits/stdc++.h>
using namespace std;

#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define unq(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end())
#define ll long long
#define pb push_back
#define fill(arr) memset(arr,0,sizeof(arr))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    _ios;
    double h,u,d,f;
    while(cin>>h>>u>>d>>f)
    {
        if(h==0)break;
        double x=(f*u)/100;
        double l=0;
        for(ll i=1; ;i++)
        {
            l+=u;
            if(l>h)
            {
                cout<<"success on day "<<i<<endl;
                break;
            }
            u-=x;
            if(u<=0)u=0;
            l-=d;
            if(l<0)
            {
                cout<<"failure on day "<<i<<endl;
                break;
            }
        }
    }
    return 0;
}

