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
int t,row,col,sx,sy,ex,ey;
int vis[1005][1005];
int dis[1005][1005];
string s;
void allclear()
{
    fill(vis,0);
    fill(dis,0);
}
bool isvalid(int x,int y)
{
    if(x>=0&&x<row&&y>=0&&y<col&&!vis[x][y])return true;
    else return false;
}
void bfs()
{
    queue<pii>q;
    q.push(make_pair(sx,sy));
    vis[sx][sy]=1;
    while(!q.empty())
    {
        int a=q.front().first;
        int b=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=a+dx[i];
            int yy=b+dy[i];
            if(isvalid(xx,yy))
            {
                vis[xx][yy]=1;
                dis[xx][yy]=dis[a][b]+1;
                q.push(make_pair(xx,yy));
            }
        }
    }
}
int main()
{
    _ios;
    while(1)
    {
        cin>>row>>col;
        if(row==0&&col==0)return 0;
        allclear();
        int bomb;
        cin>>bomb;
        w(bomb)
        {
            int r,c,n;
            cin>>r>>n;
            for(int i=0;i<n;i++)
            {
                cin>>c;
                vis[r][c]=1;
            }
        }
        cin>>sx>>sy>>ex>>ey;
        bfs();
        cout<<dis[ex][ey]<<endl;
    }
    return 0;
}



