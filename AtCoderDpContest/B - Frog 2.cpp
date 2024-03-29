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
	int n, k; cin >> n >> k;
	vector<int>ar(n), dp(n);
	rep(i, 0, n - 1) {
		cin >> ar[i];
		dp[i] = 1e9 + 7;
	}
	dp[0] = 0;
	rep(i, 0, n - 1) {
		rep(j, 1, k) {
			if (i + j < n)dp[i + j] = min(dp[i + j], dp[i] + abs(ar[i] - ar[i + j]));
		}
	}
	cout << dp[n - 1] << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	// cin>>T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

