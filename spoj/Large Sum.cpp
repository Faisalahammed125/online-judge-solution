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
const int N = 1e6 + 5;

int l, r, m;

int inv(int  a, int b) {
	int res = 1;
	while (b > 0) {
		if (b & 1)
			res = (res % mod * a % mod ) % mod;
		a = (a % mod * a % mod) % mod;
		b >>= 1;
	}
	return res;
}

int cal(int n) {
	return (((n  % mod) * ((n + 1)  % mod)) % mod * inv(2LL, mod - 2) % mod)  % mod;
}

void solve(int t) {
	cin >> l >> r >> m;
	int a = l, b = r;
	int ans = 0;
	if (r < m) {
		ans += cal(b);
		ans -= cal(a - 1);
	}
	else if (l < m) {
		ans += cal(m - 1);
		ans -= cal(a - 1);
		ans += cal(b % m);
		int tmp = b / m;
		if (tmp > 1)ans += (((tmp - 1) % mod) * cal(m - 1)) % mod;
	}
	else {
		int tmp = b / m - a / m;
		if (tmp) {
			ans += cal(m - 1);
			if (a % m)ans -= cal((a - 1) % m);
			ans += cal(b % m);
			ans += (((tmp - 1) % mod) * cal(m - 1) % mod) % mod;
		}
		else {
			ans += cal(b % m);
			ans -= cal((a - 1) % m);
		}
	}
	ans += mod;
	ans %= mod;
	cout << ans << endl;
}

signed main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	int T = 1;
	// cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}
