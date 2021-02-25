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
vii adj[100001];
int vis[100001];
int in[100001];
int low[100001];
int timer=0;
vector<pii>dedge;

void allclear()
{
    for(int i=0;i<10005;i++)adj[i].clear();
    dedge.clear();
    fill(vis,0);
    fill(in,0);
    fill(low,0);
    timer=0;
}

void findbridge(int node,int par)
{
    vis[node]=1;
    in[node]=low[node]=timer++;
    for(int child : adj[node])
    {
        //cout<<node<<" "<<child<<endl;
        if(child==par)
            continue;
        if(in[child]>in[node])
            continue;
        if(vis[child])
        {
            ///back edge
            low[node]=min(in[child],low[node]);
            dedge.pb(make_pair(node,child));
        }
        else
        {
            ///tree edge
            ///counted for bridge
            findbridge(child,node);
            low[node]=min(low[node],low[child]);
            dedge.pb(make_pair(node,child));
            if(in[node]<low[child])
            {
                dedge.pb(make_pair(child,node));
            }
        }
    }
}
int main()
{
    _ios;
    int n,m,tcase=0;
    while(cin>>n>>m)
    {
        allclear();
        tcase++;
        if(!n&&!m)
            break;
        w(m)
        {
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        //cout<<"output"<<endl;
        findbridge(1,-1);
        cout<<tcase<<endl<<endl;
        for(auto ans : dedge)
        {
            cout<<ans.first<<" "<<ans.second<<endl;
        }
        cout<<"#"<<endl;
    }
    return 0;
}



