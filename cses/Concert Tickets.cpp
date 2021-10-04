#include<bits/stdc++.h>
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
#define  pi      acos(-1)
#define  mod     1000000007
using namespace std;
const int N=5e5+5;

multiset<int>ticket;

void solve(int t){
    int n,m,x;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x;
        ticket.insert(x);
    }
    for(int i=0;i<m;i++){
        cin>>x;
        auto it=ticket.upper_bound(x);
        if(it==ticket.begin()){
            cout<<-1<<endl;
        }
        else{
            cout<<*(--it)<<endl;
            ticket.erase(it);
        }
    }
}

signed main()
{
   //ios::sync_with_stdio(0);
   //cin.tie(0);
   //cout.tie(0);
   int T=1;
   //cin>>T;
   for(int t=1;t<=T;t++){
        solve(t);
   }

   return 0;
}

