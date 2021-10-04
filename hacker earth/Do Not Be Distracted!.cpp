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

map<char,bool>check;

signed main()
{
   //ios::sync_with_stdio(0);
   //cin.tie(0);
   //cout.tie(0);
   int t;
   cin>>t;
   while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        check[s[0]]=1;
        bool ok=true;
        for(int i=1;i<n&&ok;i++){
            if(s[i]!=s[i-1]&&check[s[i]])ok=false;
            check[s[i]]=1;
        }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        check.clear();
   }

   return 0;
}
