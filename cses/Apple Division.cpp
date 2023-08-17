#include<bits/stdc++.h>
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
#define  pi      acos(-1)
#define  mod     1000000007
using namespace std;
const int N = 5e5 + 5;

void solve(int t) {
	int n, s1 = 0, s2 = 0, ans = INT_MAX;
	cin >> n;
	int arr[n];
	for (int &x : arr)cin >> x;
	for (int mask = 0; mask < (1 << n); mask++) {
		s1 = s2 = 0;
		for (int i = 0; i < n; i++) {
			if (mask & (1 << i))s1 += arr[i];
			else s2 += arr[i];
		}
		ans = min(ans, abs(s1 - s2));
	}
	cout << ans << endl;
}

signed main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	int T = 1;
	//cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

