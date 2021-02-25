#include<bits/stdc++.h>
using namespace std;

#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define unq(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end())
#define ll long
#define ull unsigned long long
#define pb push_back
#define fill(arr) memset(arr,0,sizeof(arr))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define pi acos(-1.00)
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    _ios;
    ll n,d,t;
    cin>>t;
    for(ll i=1;i<=t;i++)
    {
        cin>>n>>d;
        ll t=0,k=0;
        for( ; ;k++)
        {
            t=(d+t*10)%n;
            if(t==0)break;
        }
        cout<<"Case "<<i<<": "<<k+1<<endl;
    }
    return 0;
}

