//BISMILLAHIR RAHMANIR RAHEEM
#include<bits/stdc++.h>
#define int long long
using namespace std;

int fact(int n, int p) {
	int cnt = 0;
	while (n) {
		cnt += n / p;
		n /= p;
	}
	return cnt;
}

void solve(int t) {
	int n, k; cin >> n >> k;
	int ans = 1e9 + 7;
	for (int i = 2; i * i <= k; i++) {
		if (i > k)break;
		int cnt = 0;
		while (k % i == 0) {
			cnt++;
			k /= i;
		}
		if (cnt) {
			ans = min(ans, fact(n, i) / cnt);
		}
	}
	if (k > 1)ans = min(ans, fact(n, k));
	cout << ans << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}