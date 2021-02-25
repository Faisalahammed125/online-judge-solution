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
int t,j,q,s,e,tt;
int matrix[21][21];
void floydwarshall()
{
    for(int k=1;k<=20;k++)
    {
        for(int i=1;i<=20;i++)
        {
            for(int j=1;j<=20;j++)
            {
                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }
}
int main()
{
    _ios;
    while(cin>>t)
    {
        for(int i=1;i<=20;i++)
        {
            for(int j=1;j<=20;j++)matrix[i][j]=10005;
        }
        w(t)
        {
            cin>>j;
            matrix[1][j]=1;
            matrix[j][1]=1;
        }
        for(int i=2;i<=19;i++)
        {
            cin>>t;
            w(t)
            {
                cin>>j;
                matrix[i][j]=1;
                matrix[j][i]=1;
            }
        }
        floydwarshall();
        printf("Test Set #%d\n",++tt);
        cin>>q;
        for(int i=1;i<=q;i++)
        {
            cin>>s>>e;
            printf("%2d to %2d: %d\n",s,e,matrix[s][e]);
        }
        printf("\n");
    }
    return 0;
}



