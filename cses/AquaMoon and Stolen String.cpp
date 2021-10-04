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
map<char,int>mp[N];

void solve(int t){
    for (char ch = 'a'; ch <= 'z'; ch++) mp[ch].clear();
    int n,m;
    cin>>n>>m;
    string s[n+2];
    for(int i=0;i<n;i++){
        cin>>s[i];
        for(int j=0;j<s[i].size();j++)mp[s[i][j]][j]++;
    }
    for(int i=0;i<n-1;i++){
        string ss;
        cin>>ss;
        for(int j=0;j<ss.size();j++)mp[ss[j]][j]--;
    }
    for(int i=0;i<n;i++){
        bool ok=1;
        for(int j=0;j<s[i].size();j++){
            if(!mp[s[i][j]][j])ok=0;
        }
        if(ok){
            cout<<s[i]<<endl;
            return;
        }
    }
}

signed main()
{
   //ios::sync_with_stdio(0);
   //cin.tie(0);
   //cout.tie(0);
   int T=1;
   cin>>T;
   for(int t=1;t<=T;t++){
        solve(t);
   }

   return 0;
}

