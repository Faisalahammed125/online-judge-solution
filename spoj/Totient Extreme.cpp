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
#define    fill(arr,x)      memset(arr,x,sizeof(arr))
#define    gcd(a,b)         __gcd(a,b)
#define    lcm(a,b)        (a*(b/gcd(a,b)))
#define    srtc(a,b)        sort(a,a+b,greater<int>())
#define    pi               acos(-1.00)
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N=10001;
int t,i;
string s;
int phi[N],pre[N];

void toitent()
{
    rep(i,1,N-1)phi[i]=i;
    rep(i,2,N-1)if(phi[i]==i)for(int j=i;j<N;j+=i)phi[j]-=phi[j]/i;
    rep(i,1,N-1)pre[i]=pre[i-1]+phi[i];
}
int main()
{
    _ios;
    toitent();
    cin>>t;
    w(t)
    {
        int n;
        cin>>n;
        ll res=0,tp=pre[n];
        rep(i,1,n)res+=(tp*phi[i]);
        cout<<res<<endl;
    }
    return 0;
}



