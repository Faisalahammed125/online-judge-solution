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
//const int dx[] = {+1,-1,+0,+0};
//const int dy[] = {+0,+0,+1,-1};
const int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
const int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
//const int dx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
//const int dy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
//---------------------------------------------------------------
int t,row,col;
string s;
char in[105][105];
vector<pii>v;
bool vis[105][105];
bool isvalid(int x,int y)
{
    if(!vis[x][y] && x>=0&&x<row && y>=0&&y<col)
        return true;
    else
        return false;
}
void dfs(int sx , int sy)
{
    vis[sx][sy] = 1;
    for(int i = 0 ; i<8 ; i++){
        int x = sx + dx[i], y = sy + dy[i];
        if(isvalid(x,y))
            dfs(x,y);
    }
}
int main()
{
    _ios;
    while(1)
    {
        cin>>row>>col;
        if(row==0)return 0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cin>>in[i][j];
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(in[i][j]=='*')vis[i][j]=1;
                else
                {
                    v.pb(make_pair(i,j));
                }
            }
        }
        int ans=0;
        for(int i=0;i<v.size();i++)
        {
            int a=v[i].first;
            int b=v[i].second;
            if(!vis[a][b])
            {
                ans++;
                dfs(a,b);
            }
        }
        cout<<ans<<endl;
        fill(vis,0);
        v.clear();
    }
    return 0;
}



