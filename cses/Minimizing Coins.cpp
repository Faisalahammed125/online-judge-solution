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
	int n, target;
	cin >> n >> target;
	vector<int> coin(n);
	for (int &x : coin)cin >> x;
	vector<int> dp(target + 1, 1e9);
	dp[0] = 0;
	for (int i = 1; i <= target; i++) {
		for (int val : coin) {
			if (i - val >= 0) {
				dp[i] = min(dp[i], dp[i - val] + 1);
			}
		}
	}
	cout << (dp[target] == 1e9 ? -1 : dp[target]) << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	//cin>>T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

