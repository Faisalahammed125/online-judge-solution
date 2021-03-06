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
//--------------Graph Moves--------------------------------------
const int dx[] = {+1,-1,+0,+0};
const int dy[] = {+0,+0,+1,-1};
//const int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
//const int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
//const int dx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
//const int dy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
//---------------------------------------------------------------
int t;
string s;
vii adj[500005];
int in[500005];
int low[500005];
int des[500005];
int vis[500005];
ll timer,cnt,ans,n,m;

void bridge(int node,int par)
{
    vis[node]=1;
    in[node]=low[node]=timer++;
    for(int child : adj[node])
    {
        if(child==par)continue;
        if(vis[child])
        {
            low[node]=min(low[node],in[child]);
        }
        else
        {
            bridge(child,node);
            low[node]=min(low[child],low[node]);
            if(in[node]<low[child])
            {
                ll temp=des[child]+1;
                n-=temp;
                ans+=(n*temp);
            }
            else des[node]=des[node]+des[child]+1;
            //cout<<node<<" "<<cnt<<" "<<des[node]<<endl;
        }
    }
}
int main()
{
    _ios;
    cin>>n>>m;
    w(m)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll p=(n*(n-1))/2;
    bridge(1,-1);
    //for(int i=1;i<=n;i++)cout<<des[i]<<" ";
    double a=(double)ans/(1.000*p);
    cout<<a<<endl;
    return 0;
}



