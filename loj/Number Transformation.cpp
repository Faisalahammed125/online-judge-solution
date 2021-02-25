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
bool mark[10005];
vii prime;
vii adj[1005];
int vis[1005];
int dis[1005];
void sieve()
{
    for(int i=2;i*i<=1005;i++)
    {
        if(!mark[i])
        {
            for(int j=i*i;j<1005;j+=i)mark[j]=1;
        }
    }
    prime.pb(2);
    for(int i=3;i<1005;i+=2)
    {
        if(!mark[i])
        {
            prime.pb(i);
        }
    }
}
void adj_list()
{
    for(int i=1;i<=1000;i++)
    {
        //cout<<i<<":";
        for(int j=0;j<prime.size();j++)
        {
            if(i%prime[j]==0&&prime[j]!=i)
                {
                    adj[i].pb(i+prime[j]);
                    //cout<<" "<<prime[j]+i;
                }
        }
        //cout<<endl;
    }
}
void bfs(int src,int e){
    queue<int>q;
    q.push(src);
    vis[src] = 1;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        if(a==e)return;
        for(int i=0; i<adj[a].size(); i++){
            int p = adj[a][i];
            if(vis[p] == 0&&p<=e){
                dis[p] = dis[a] + 1;
                vis[p] = 1;
                q.push(p);
            }
            //cout<<p<<" "<<vis[p]<<" "<<dis[p]<<endl;
        }
    }
}
int main()
{
    _ios;
    sieve();
    adj_list();
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        fill(vis,0);
        fill(dis,0);
        int s,e;
        cin>>s>>e;
        if(s==e)
        {
            cout<<"Case "<<tt<<": "<<0<<endl;
            continue;
        }
        bfs(s,e);
        if(!dis[e])cout<<"Case "<<tt<<": "<<-1<<endl;
        else cout<<"Case "<<tt<<": "<<dis[e]<<endl;
    }
    return 0;
}



