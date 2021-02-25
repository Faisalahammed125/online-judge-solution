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
char inp[15][15];
vector<pii>v[30];
int vis[15][15];
int dis[15][15];
int sts[15][15];
void bfs(int sx,int sy,int ex,int ey)
{
    fill(vis,0);
    fill(dis,0);
    queue<pii>q;
    q.push(make_pair(sx,sy));
    vis[sx][sy]=1;
    dis[sx][sy]=0;
    inp[sx][sy]='.';
    while(!q.empty())
    {
        int a=q.front().first;
        int b=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=a+dx[i];
            int yy=b+dy[i];
            if(xx==ex&&yy==ey)
            {
                dis[xx][yy]=dis[a][b]+1;
                return;
            }
           else if(xx>=0&&xx<n&&yy>=0&&yy<n&&!vis[xx][yy]&&inp[xx][yy]=='.')
           {
               dis[xx][yy]=dis[a][b]+1;
               vis[xx][yy]=1;
               inp[xx][yy]='.';
               q.push(make_pair(xx,yy));
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
        cin>>n;
        int idx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>inp[i][j];
                if(inp[i][j]!='#'&&inp[i][j]!='.')
                {
                    v[inp[i][j]-'A'].pb(make_pair(i,j));
                    idx++;
                }
            }
        }
        int mx=0;
        int ok=true;
        for(int i=0;i<idx-1;i++)
        {
            int x1,y1,x2,y2;
            x1=v[i][0].first;
            y1=v[i][0].second;
            x2=v[i+1][0].first;
            y2=v[i+1][0].second;
            bfs(x1,y1,x2,y2);
            if(dis[x2][y2]==0)
            {
                ok=false;
                break;
            }
            else mx+=dis[x2][y2];
        }
        if(ok)cout<<"Case "<<tt<<": "<<mx<<endl;
        else cout<<"Case "<<tt<<": Impossible"<<endl;
        for(int i=0;i<30;i++)v[i].clear();
    }
    return 0;
}



