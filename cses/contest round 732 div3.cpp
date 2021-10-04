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

void solve(int t){
    int n;
    cin>>n;
    int arr[n+2];
    map<int,int>odd,even;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(i&1)odd[arr[i]]++;
        else even[arr[i]]++;
    }
    sort(arr+1,arr+n+1);
    bool ok=1;
    for(int i=1;i<=n;i++){
        int x=arr[i];
        if(i&1){
            if(odd[x])odd[x]--;
            else ok=0;
        }
        else{
            if(even[x])even[x]--;
            else ok=0;
        }
    }
    if(ok)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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

