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
	int a, b;
	cin >> a >> b;
	int ans, st, ed;
	ans = 0;
	st = (a / 3) * 3;
	ed = (b / 3) * 3;
	ans += (ed - st) / 3;
	ans *= 2;
	if (st == a)ans++;
	if (b - ed == 2)ans++;
	cout << "Case " << t << ": " << ans << endl;
}

signed main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

