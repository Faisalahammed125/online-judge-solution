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
vector<string>word;
map<string,vector<string>>adj;
map<string,bool>vis;
map<string,int>dis;

bool one_dif(string s1,string s2)
{
    if(s1.size()!=s2.size())return false;
    int dif=0;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]!=s2[i])dif++;
    }
    if(dif==1)return true;
    else return false;
}

void createadj_list()
{
    for(int i=0;i<word.size();i++)
    {
        string node=word[i];
        for(int j=0;j<word.size();j++)
        {
            if(i!=j)
            {
                string child=word[j];
                if(one_dif(node,child))
                {
                    adj[node].pb(child);
                }
            }
        }
    }
}

void bfs(string s)
{
    queue<string>q;
    q.push(s);
    vis[s]=1;
    dis[s]=0;
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
                dis[child]=dis[node]+1;
            }
        }
    }
}

int main()
{
    _ios;
    cin>>t;
    w(t)
    {
        string s;
        while(cin>>s)
        {
            if(s=="*")break;
            word.pb(s);
        }
        createadj_list();
        string lin,s1,s2;
        cin.ignore();
        while (getline(cin,lin)&&lin != "")
        {
            stringstream ss(lin);
            ss>>s1>>s2;
            bfs(s1);
            int ans= dis[s2];
            cout<<s1<<" "<<s2<<" "<<ans<<endl;
            vis.clear();
            dis.clear();
        }
        adj.clear();
        if(t)cout<<endl;
    }
    return 0;
}



