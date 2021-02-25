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
    ll n,b,h,w,x,p;
    vector<ll>v;
    while(cin>>n>>b>>h>>w)
    {
        for(ll i=1; i<=h; i++)
        {
            cin>>x;
            for(ll j=1; j<=w; j++)
            {
                cin>>p;
                if(n<=p)
                    v.pb(x);
            }
        }
        if(!v.size()||n*minv(v)>=b)
            cout<<"stay home"<<endl;
        else
            cout<<n*minv(v)<<endl;
            v.clear();
    }
    return 0;
}

