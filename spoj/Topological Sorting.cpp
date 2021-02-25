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
set<int,greater<int>>adj[10005];
bool vis[10005];
vii sorted_node;
int state[10005];
sii s;

bool find_cycle(int node,int par)
{
    vis[node]=1;
    state[node]=1;
    for(int child : adj[node])
    {
        if(!vis[child])
        {
            if(find_cycle(child,node)==true)
                return  true;
        }
        else
        {
            if(state[child]==1)
            {
                //cout<<child<<" "<<par<<endl;
                return true;
            }
        }
    }
    state[node]=2;
    return false;
}

void topsort(int node)
{
    vis[node]=1;
    for(int child : adj[node])
    {
        if(!vis[child])
        {
            topsort(child);
        }
    }
    sorted_node.pb(node);
}

int main()
{
    _ios;
    int n,m;
    cin>>n>>m;
    w(m)
    {
        int u,v;
        cin>>u>>v;
        adj[u].insert(v);
    }
    bool cycle=false;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            s.clear();
            cycle=find_cycle(i,-1);
            if(cycle)
            {
                cout<<"Sandro fails."<<endl;
                return 0;
            }
        }
    }
    fill(vis,0);
    for(int i=n;i>=1;i--)
    {
        if(!vis[i])
            topsort(i);
    }
    reverse(all(sorted_node));
    for(int node : sorted_node)cout<<node<<" ";

    return 0;
}



