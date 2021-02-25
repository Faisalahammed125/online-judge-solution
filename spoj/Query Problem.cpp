#include<bits/stdc++.h>
using namespace std;
#define    bit(a)          __builtin_popcount(a)
#define    all(x)           x.begin(), x.end()
#define    minv(v)         *min_element(all(v))
#define    maxv(v)         *max_element(all(v))
#define    unq(v)           sort(all(v)),v.erase(unique(all(v)),v.end())
#define    w(x)             while(x--)
#define    rep(i,a,b)       for(i=a;i<=b;i++)
#define    ll               long long
#define    pb               push_back
#define    vii              vector<int>
#define    vll              vector<ll>
#define    vcc              vector<char>
#define    sii              set<int>
#define    sll              set<ll>
#define    scc              set<char>
#define    li               list<int>
#define    pii              pair<int,int>
#define    pll              pair<ll,ll>
#define    mii              map<int,int>
#define    mll              map<ll,ll>
#define    fill(arr,x)      memset(arr,x,sizeof(arr))
#define    gcd(a,b)         __gcd(a,b)
#define    lcm(a,b)        (a*(b/gcd(a,b)))
#define    srtc(a,b)        sort(a,a+b,greater<int>())
#define    pi               acos(-1.00)
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
/*
//find the position of 0 or 1 in binary representation
int zero(int n)
{
    int i=1,pos=0;
    while(n)
    {
        if(n%2==0)pos=i;
        n/=2;
        i++;
    }
    return pos;
}
*/
int t;
string s;
vll z_algo()
{
    ll left=0,right=0;
    ll sz=s.length();
    vll z(sz);
    z[0]=sz;
    for(ll k=1;k<sz;k++)
    {
        if(k>right)
        {
            left=right=k;
            while(right<sz&&s[right]==s[right-left])
                right++;
            z[k]=right-left;
            right--;
        }
        else
        {
            ll k1=k-left;
            if(z[k1]<right-k+1)
                z[k]=z[k1];
            else
            {
                left=k;
                while(right<sz&&s[right]==s[right-left])
                    right++;
                z[k]=right-left;
                right--;
            }
        }
    }
    reverse(all(z));
    return z;
}
int main()
{
    _ios;
    cin>>t;
    w(t)
    {
        ll n;
        cin>>s;
        cin>>n;
        reverse(all(s));
        vll v=z_algo();
        for(int i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            cout<<v[x-1]<<endl;
        }
    }
    return 0;
}



