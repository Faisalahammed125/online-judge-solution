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
map<string,string>path;
void bfs()
{
    queue<string>q;
    q.push("Rome");
    vis["Rome"]=1;
    path["Rome"]="#";
    while(!q.empty())
    {
        string a=q.front();
        q.pop();
        for(int i=0;i<adj[a].size();i++)
        {
            string b=adj[a][i];
            if(!vis[b])
            {
                vis[b]=1;
                q.push(b);
                path[b]=a;
            }
        }
    }
}
int main()
{
    _ios;
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
       adj.clear();
       vis.clear();
       path.clear();
       int m,n;
       cin>>m>>n;
       for(int i=1;i<=m;i++)
       {
           cin>>s>>s1;
           adj[s].pb(s1);
           adj[s1].pb(s);
       }
       bfs();
       w(n)
       {
           vis.clear();
           cin>>s>>s1;
           string path1,path2,path3,temp;
           temp=s;
           vis[temp]=1;
           path1+=temp[0];
           while(path[temp]!="#")
           {
               temp=path[temp];
               path1+=temp[0];
               vis[temp]=1;
           }
           //cout<<path1<<endl;
           temp=s1;
           char c;
           if(!vis[temp])
           {
               path2+=temp[0];
               while(path[temp]!="#")
               {
                   temp=path[temp];
                   if(!vis[temp])
                   {
                       path2+=temp[0];
                   }
                   else
                   {
                       c=temp[0];
                       break;
                   }
               }
           }
           else c=temp[0];
           for(int i=0;i<path1.size();i++)
           {
               if(path1[i]!=c)path3+=path1[i];
               else
               {
                   path3+=path1[i];
                   break;
               }
           }
           //cout<<path1<<" "<<path2<<" "<<path3<<endl;
           reverse(path2.begin(),path2.end());
           cout<<path3<<path2<<endl;
       }
       if(tt!=t)cout<<endl;
    }
    return 0;
}



