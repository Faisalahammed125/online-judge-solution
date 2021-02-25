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
int t,n;
string s;
vii adj[105];
bool vis[105];
int  dis[105];

void print()
{
    vii res;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            res.pb(i);
        }
    }
    if(res.size())
    {
        cout<<res.size();
        for(auto it:res)cout<<" "<<it;
        cout<<endl;
    }
    else cout<<0<<endl;
}
void bfs(int src)
{
    fill(vis,0);
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int child : adj[node]){
            if(!vis[child]){
                vis[child]=true;
                q.push(child);
            }
        }
    }
}
int main()
{
    _ios;
    while(cin>>n)
       {
           if(n==0)break;
        int x,y;
        while(cin>>x)
        {
            if(x==0)break;
            while(cin>>y)
            {
                if(y==0)
                    break;
                adj[x].pb(y);
            }
        }
        int q;
        cin>>q;
        for(int i=0;i<q;i++)
        {
            int s;
            cin>>s;
            bfs(s);
            print();
            for(int i=0; i<105; i++)adj[i].clear();
        }

    }
    return 0;
}




