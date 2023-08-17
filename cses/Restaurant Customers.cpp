//BISMILLAHIR RAHMANIR RAHEEM
#include<bits/stdc++.h>
#define  MX           100005
#define  ff           first
#define  ss           second
#define  pb           push_back
#define  int          long long
#define  endl         "\n"
#define  PII          pair<int,int>
#define  all(v)       v.begin(),v.end()
#define  pi           acos(-1)
#define  mod          1000000007
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;
const int N = 5e5 + 5;

void solve(int t) {
	int n;
	cin >> n;
	vector <int> ari, dep;
	rep(i, 1, n) {
		int x, y;
		cin >> x >> y;
		ari.pb(x);
		dep.pb(y);
	}
	sort(all(ari));
	sort(all(dep));
	int ans = 0;
	rep(i, 0, n - 1) {
		int idx = lower_bound(all(ari), dep[i]) - ari.begin();
		ans = max(ans, (idx - i));
	}
	cout << ans << endl;
}

signed main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	int T = 1;
	// cin>>T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

