#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int  MOD=1e9+7;

ll power(ll a,ll b){
	ll res=1;
	while(b){
		if(b%2){
			res=((res%MOD)*(a%MOD))%MOD;
			b--;
		}
		else{
			a=((a%MOD)*(a%MOD))%MOD;
			b/=2;
		}
	}
	return res;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		cout<<power(a,b)<<endl;
	}
	return 0;
}
