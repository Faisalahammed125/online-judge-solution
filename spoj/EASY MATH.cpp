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
	int n, m, a, d; cin >> n >> m >> a >> d;
	int arr[] = {a, a + d, a + 2 * d, a + 3 * d, a + 4 * d};
	int k = 5;
	int ans = 0;
	for (int i = 1; i < (1 << k); i++) {
		int lcm = 1;
		int bit = __builtin_popcount(i);
		for (int mask = 0; mask < k; mask++) {
			if (i & (1 << mask))
				lcm = (lcm * arr[mask]) / __gcd(lcm, arr[mask]);
		}
		if (bit & 1) {
			ans += (m / lcm);
			ans -= ((n - 1) / lcm);
		}
		else {
			ans -= (m / lcm);
			ans += ((n - 1) / lcm);
		}
		// cout << ans << " " << lcm << endl;
	}
	cout << m - n + 1 - ans << endl;
}

signed main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

