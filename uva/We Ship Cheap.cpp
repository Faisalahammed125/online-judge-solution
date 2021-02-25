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
string edge1,edge2;
map<string,vector<string>>adj;
map<string,bool>vis;
map<string,string>path;

void bfs(string s)
{
    queue<string>q;
    q.push(s);
    vis[s]=1;
    path[s]="$";
    while(!q.empty())
    {
        string node=q.front();
        q.pop();
        for(string child : adj[node])
        {
            if(!vis[child])
            {
                vis[child]=1;
                q.push(child);
                path[child]=node;
            }
        }
    }
}

void print_path(string s1,string s2)
{
    if(s1==s2) return;
    print_path(path[s1],s2);
    cout<<path[s1]<<" "<<s1<<endl;
}

int main()
{
    _ios;
    bool ok=false;
    while(cin>>n)
    {
        adj.clear();
        vis.clear();
        path.clear();
        for(int i=0;i<n;i++)
        {
            cin>>edge1>>edge2;
            adj[edge1].pb(edge2);
            adj[edge2].pb(edge1);
        }
        cin>>edge1>>edge2;
        if(ok)cout<<endl;
        ok=true;
        bfs(edge1);
        if(!vis[edge2])cout<<"No route"<<endl;
        else
        {
            print_path(edge2,edge1);
        }
    }
    return 0;
}



