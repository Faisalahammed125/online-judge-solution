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
string s,s1;
map<string,vector<string>>adj;
map<string,bool>vis;
map<string,int>state;
set<string>allnode;
bool cycle=false;

void allclear()
{
    for(auto it : allnode)
    {
        adj[it].clear();
        vis[it]=0;
        state[it]=0;
    }
    allnode.clear();
    cycle=false;
}
void find_cycle(string node)
{
    vis[node]=1;
    state[node]=1;
    for(string child : adj[node])
    {
        if(!vis[child])
        {
            find_cycle(child);
        }
        else
        {
            if(state[child]==1)
            {
                cycle= true;
            }
        }
    }
    state[node]=2;
}
int main()
{
    _ios;
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        int n;
        allclear();
        cin>>n;
        w(n)
        {
           cin>>s>>s1;
           adj[s].pb(s1);
           allnode.insert(s);
           allnode.insert(s1);
        }
        for(auto it : allnode)
        {
            if(!vis[it])
            {
                find_cycle(it);
            }
        }
        if(cycle)cout<<"Case "<<tt<<": No"<<endl;
        else cout<<"Case "<<tt<<": Yes"<<endl;
    }
    return 0;
}



