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
int t,red,green;
vii adj[20005];
int color[20005];

int bfs(int s)
{
    red=0,green=0;
    queue<int>q;
    q.push(s);
    color[s]=1;   ///1 for red 2 for green
    red++;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(int child : adj[node])
        {
            int checkcolor=color[node];
            if(!color[child])
            {
                q.push(child);
                if(checkcolor==2)
                {
                    color[child]=1;
                    red++;
                }
                else
                {
                    color[child]=2;
                    green++;
                }
            }
        }
    }
    return max(red,green);
}
int main()
{
    _ios;
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        int n,st,ans=0;
        cin>>n;
        w(n)
        {
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        for(int i=1;i<20005;i++)
        {
            if(!color[i]&&!adj[i].empty())
                ans+=bfs(i);
        }
        cout<<"Case "<<tt<<": "<<ans<<endl;
        fill(color,0);
        for(int i=0;i<20005;i++)adj[i].clear();
    }
    return 0;
}



