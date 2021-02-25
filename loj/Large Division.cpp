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

int main()
{
    _ios;
    ll t,i;
    cin>>t;
    rep(i,1,t)
    {
        string s;
        ll n;
        cin>>s;
        cin>>n;
        ll j=0,t=0;
        if(s[0]=='-')j=1;
        for( ; j<s.size();j++)
        {
            t=((s[j]-'0')+t*10)%n;
            //cout<<t<<" ";
        }
        //cout<<endl;
        //cout<<s<<endl;
        if(t==0)cout<<"Case "<<i<<": divisible"<<endl;
        else cout<<"Case "<<i<<": not divisible"<<endl;
    }
    return 0;
}

