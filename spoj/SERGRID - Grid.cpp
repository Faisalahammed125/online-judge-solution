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
char s[600][600];
int vis[600][600];
int dis[600][600];
int row,col;

bool isvalid(int x,int y)
{
    if(vis[x][y]==0 && x>=0&&x<row && y>=0&&y<col)
        return true;
    else
        return false;
}

void bfs(int x,int y)
{
    queue<pii>q;
    q.push(make_pair(x,y));
    vis[x][y]=1;
    while(!q.empty())
    {
        int a=q.front().first;
        int b=q.front().second;
        int d=s[a][b]-'0';
        q.pop();
        for(int i=0; i<4; i++)
        {
            int xx=a+dx[i]*d;
            int yy=b+dy[i]*d;
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

    cin>>row>>col;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cin>>s[i][j];
        }
    }
    bfs(0,0);
    if(dis[row-1][col-1])cout<<dis[row-1][col-1]<<endl;
    else cout<<-1<<endl;
    //cout<<dis[x1][y1]<<" "<<dis[x2][y2]<<" "<<dis[x3][y3]<<endl;
return 0;
}
