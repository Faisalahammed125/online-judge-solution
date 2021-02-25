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
vii adj[1000005];
vii readj[1000005];
int vis[1000005];
vii sc,order;

int ans[1000005];

void dfs1(int node)
{
    vis[node]=1;
    for(int child : adj[node])
    {
        if(!vis[child])
            dfs1(child);
    }
    order.pb(node);
}

void dfs2(int node)
{
    vis[node]=1;
    for(int child: readj[node])
    {
        if(!vis[child])
        {
            dfs2(child);
        }
    }
    sc.pb(node);
}

void update_ans()
{
    if(sc.size()<=1)
        return;
    for(int node : sc)
        ans[node]=1;
}
int main()
{
    _ios;
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        adj[i].clear();
        readj[i].clear();
        vis[i]=0;
    }
    for(int i=1; i<=m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        readj[v].pb(u);
    }
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
            dfs1(i);
    }
    for(int i=1; i<=n; i++)
        vis[i]=0;
    reverse(all(order));
    for(int node : order)
    {
        if(!vis[node])
        {
            sc.clear();
            dfs2(node);
            update_ans();
        }
    }
    order.clear();
    for(int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}




