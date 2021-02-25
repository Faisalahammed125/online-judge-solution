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
int t,mx=0;
string s;
vii adj[105];
int vis[105];
int dis1[105];
int dis2[105];


void bfs(int s,int *dis)
{
    queue<int>q;
    q.push(s);
    vis[s]=1;
    dis[s]=0;
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(auto b:adj[a])
        {
            if(vis[b]==0)
            {
                vis[b]=1;
                dis[b]=dis[a]+1;
                q.push(b);
            }
        }
    }
    //cout<<mx<<endl;
}
int main()
{
    _ios;
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        int n,r,s,e;
        cin>>n>>r;
        for(int i = 0; i < n; i++)
			adj[i].clear();
        for(int i=1;i<=r;i++)
        {
           int x,y;
           cin>>x>>y;
           adj[x].pb(y);
           adj[y].pb(x);
        }
        cin>>s>>e;
        fill(dis1,0);
        fill(vis,0);
        bfs(s,dis1);
        fill(dis2,0);
        fill(vis,0);
        bfs(e,dis2);
        mx=0;
        for(int i=0;i<n;i++)
            mx=max(mx,dis1[i]+dis2[i]);
        cout<<"Case "<<tt<<": "<<mx<<endl;
    }
    return 0;
}



