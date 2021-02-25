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

const int N=100005;
const int logN=20;

int t,n,q;
int arr[N],logs[N];
int table[logN][N];
string s;

void computelogs()
{
    for(int i=2;i<=n;i++)
    {
        logs[i]=logs[i/2]+1;
    }
}

void sparsetable()
{
    for(int i=0;i<=logs[n];i++)
    {
        int curlen=1<<i;
        for(int j=0;j+curlen<=n;j++)
        {
            if(curlen==1)table[i][j]=arr[j];
            else
                table[i][j]=min(table[i-1][j],table[i-1][j+curlen/2]);
        }
    }
}
int getmin(int l,int r)
{
    int p=logs[r-l+1];
    int plen=1<<p;
    return min(table[p][l],table[p][r-plen+1]);
}
int main()
{
    _ios;
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    computelogs();
    sparsetable();
    cin>>q;
    w(q)
    {
        int l,r;
        cin>>l>>r;
        cout<<getmin(l,r)<<endl;
    }
    return 0;
}



