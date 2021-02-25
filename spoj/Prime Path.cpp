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
#define    N                9999
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
bool mark[N+5];
vii prime;
vii adj[N];
int vis[N+5];
int dis[N+5];

void sieve()
{
    for(int i=2;i*i<=N;i++)
    {
        for(int j=i*i;j<=N;j+=i)
        {
            mark[j]=1;
        }
    }
    for(int i=1000;i<=N;i++)if(!mark[i])prime.pb(i);
}
bool ifdiffer1(int p1,int p2)
{
    int dif=0;
    for(int i=0;i<4;i++)
    {
        int rem1=p1%10;
        int rem2=p2%10;
        p1/=10;
        p2/=10;
        if(rem1!=rem2)dif++;
    }
    if(dif==1)return true;
    else return false;
}
void makeadj_list()
{
    for(int i=0;i<prime.size();i++)
    {
        for(int j=i+1;j<prime.size();j++)
        {
            int p1=prime[i];
            int p2=prime[j];
            if(ifdiffer1(p1,p2))
            {
                adj[p1].pb(p2);
                adj[p2].pb(p1);
            }
        }
    }
}
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    vis[s]=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(int child : adj[node])
        {
            if(!vis[child])
            {
                vis[child]=1;
                dis[child]=dis[node]+1;
                q.push(child);
            }
        }
    }
}
void allclear()
{
    fill(vis,0);
    fill(dis,0);
}
int main()
{
    _ios;
    sieve();
    makeadj_list();
    cin>>t;
    w(t)
    {
        int u,v;
        cin>>u>>v;
        bfs(u);
        if(vis[v])cout<<dis[v]<<endl;
        else cout<<"Impossible"<<endl;
        allclear();
    }
    return 0;
}



