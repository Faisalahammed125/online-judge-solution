#include<bits/stdc++.h>
using namespace std;

#define   minv(v)    *min_element(v.begin(),v.end())
#define   maxv(v)    *max_element(v.begin(),v.end())
#define   unq(v)     sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end())
#define   tt(x)      scanf("%d",&x);while(x--)
#define   rep(i,a,b) for(i=a;i<=b;i++)
#define   ll         long long
#define   pb         push_back
#define   fill(arr)  memset(arr,0,sizeof(arr))
#define   gcd(a,b)   __gcd(a,b)
#define   lcm(a,b)  (a*(b/gcd(a,b)))
#define   pi         acos(-1.00)
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
vector<ll>v[30];
ll arr[100][100];
int main()
{
    _ios;
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        v[i].pb(i);
        arr[i][i]=1;
    }
    cout<<1<<endl;
    for( ; ;)
    {
        cout<<1<<endl;
        string s;
        cin>>s;
        ll x=s[5]-'0';
        ll y=s[12]-'0';
        cout<<x<<" "<<y;
    }
    return 0;
}

