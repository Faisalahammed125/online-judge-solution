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
#define    mp               make_pair
#define    ff               first
#define    ss               second
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
int t,row,col,sx,sy;
char grid[205][205];
bool vis[205][205];
int firelevel[205][205];
int level[205][205];
queue<pii>q;
int ans;

bool isvalid(int x,int y)
{
    if(x>=0&&x<row&&y>=0&&y<col&&!vis[x][y]&&grid[x][y]!='#')return true;
    else return false;
}
void bfs()
{
    while(!q.empty())
    {
        int x=q.front().ff;
        int y=q.front().ss;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(isvalid(xx,yy))
            {
                vis[xx][yy]=1;
                firelevel[xx][yy]=firelevel[x][y]+1;
                q.push(mp(xx,yy));
            }
        }
    }
}
bool isvalid1(int x,int y,int lvl)
{
    if(x>=0&&x<row&&y>=0&&y<col&&!vis[x][y]&&grid[x][y]!='#'&&grid[x][y]!='F'&&lvl+1<firelevel[x][y])return true;
    else return false;
}
bool bfs1()
{
    while(!q.empty())
    {
        int x=q.front().ff;
        int y=q.front().ss;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            int lvl=level[x][y];
            if(isvalid1(xx,yy,lvl))
            {
                vis[xx][yy]=1;
                level[xx][yy]=lvl+1;
                q.push(mp(xx,yy));
                if(xx==row-1||xx==0||yy==0||yy==col-1){
                        ans=lvl+2;
                        return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    _ios;
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        cin>>row>>col;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cin>>grid[i][j];
                if(grid[i][j]=='J')
                {
                    sx=i;
                    sy=j;
                }
                else if(grid[i][j]=='F')
                {
                    q.push(mp(i,j));
                    vis[i][j]=1;
                }
            }
        }
        bfs();
        fill(vis,0);
        while(!q.empty())q.pop();
        q.push(mp(sx,sy));
        bool ok=bfs1();
        if(ok)cout<<"Case "<<tt<<": "<<ans<<endl;
        else cout<<"Case "<<tt<<": IMPOSSIBLE"<<endl;
        while(!q.empty())q.pop();
        fill(vis,0);
        fill(firelevel,0);
        fill(level,0);
        ans=0;
    }
    return 0;
}



