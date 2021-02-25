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

void kmp(string s)
{
    bool flag=true;
    ll len=s.length();
    ll i,j;
    for( i=1;i<=len;i++)
    {
        if(len%i!=0)continue;
        for( j=i;j<len;j++)
        {
            if(s[j]!=s[j%i])
            {
                flag=false;
                break;
            }
        }
        if(flag)break;
        flag=true;
    }
    cout<<i;
}
int main()
{
    _ios;
    ll n,i;
    cin>>n;
    rep(i,1,n)
    {
        string s;
        cin>>s;
        kmp(s);
        if(i==n)cout<<endl;
        else cout<<endl<<endl;
    }
    return 0;
}

