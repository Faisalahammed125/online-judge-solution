//BISMILLAHIR RAHMANIR RAHEEM
#include<bits/stdc++.h>
#define  MX           100005
#define  ff           first
#define  ss           second
#define  pb           push_back
// #define  int          long long
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
	int n, target; cin >> n >> target;
	vector<int>coins(n);
	for (int &x : coins)cin >> x;
	///dp[i][x]=number of possible ways finding sum x with first i coins
	vector<vector<int>>dp(n + 1, vector<int>(target + 1, 0));
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= target; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - coins[i - 1] >= 0) {
				(dp[i][j] += dp[i][j - coins[i - 1]]) %= mod;
			}
		}
	}
	cout << dp[n][target] << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	// cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}
