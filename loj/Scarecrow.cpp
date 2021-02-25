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
    int t,i;
    ll mark[1005];
    cin>>t;
    rep(i,1,t)
    {
        fill(mark);
        string s;
        int  n;
        cin>>n;
        cin>>s;
        int cnt=0;
        for(ll j=0;j<s.size();j++)
        {
            if(s[j]=='.'&&!mark[j])
            {
                if(j+1<n)mark[j+1]=1;
                if(j+2<n)mark[j+2]=1;
                cnt++;
            }

        }
        cout<<"Case "<<i<<": "<<cnt<<endl;
    }
    return 0;
}

