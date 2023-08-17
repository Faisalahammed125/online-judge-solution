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
const int N = 2e6 + 5;
int fact[N];

int power(int n, int k) {
	int ans = 1;
	while (k) {
		if (k & 1)ans = (ans * n) % mod;
		n = (n * n) % mod;
		k >>= 1;
	}
	return ans % mod;
}

void solve(int t) {
	///the number of ways in which k identical balls can be distributed into N unique boxes
	///is equals to Number of non-negative integral solutions of equation
	///x1 + x2 + …… + xn = k is given by (n+k-1)! / (n-1)!*k!
	fact[0] = 1; fact[1] = 1;
	for (int i = 2; i < N; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
	}
	int n, m; cin >> n >> m;
	int ans = fact[n + m - 1];
	int inv = power(fact[n - 1], mod - 2);
	ans = (ans * inv) % mod;
	inv = power(fact[m], mod - 2);
	ans = (ans * inv) % mod;
	cout << ans << endl;
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

