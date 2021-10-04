#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int  mod=1e9+7;

ll power(ll a,ll b,ll m){
	ll res=1;
	while(b){
		if(b%2)res=((res%m)*(a%m))%m;
		b/=2;
        a=((a%m)*(a%m))%m;
	}
	return res;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		ll a,b,c;
		cin>>a>>b>>c;
		ll x=power(b,c,mod-1);
		cout<<power(a,x,mod)<<endl;
	}
	return 0;
}
