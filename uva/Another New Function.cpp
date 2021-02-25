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
string s;
int N=2000005;
ll phi[2000005];
ll depth[2000005];

void phi_function()
{
    for(int i=0;i<=N;i++)phi[i]=i;
    for(int i=2;i<=N;i++)
    {
        if(i==phi[i])
        {
            for(int j=i;j<=N;j+=i)
            {
                phi[j]-=(phi[j]/i);
            }
        }
    }
}

void depthphi()
{
    depth[1]=depth[2]=1;
    for(int i=3;i<=N;i++)
    {
        depth[i]=depth[phi[i]]+1;
    }
}

void sum_of_depthphi()
{
    for(int i=2;i<=N;i++)
    {
        depth[i]+=depth[i-1];
    }
}
int main()
{
    _ios;
    cin>>t;
    phi_function();
    depthphi();
    sum_of_depthphi();
    w(t)
    {
        int m,n;
        cin>>m>>n;
        cout<<depth[n]-depth[m-1]<<endl;
    }
    return 0;
}



