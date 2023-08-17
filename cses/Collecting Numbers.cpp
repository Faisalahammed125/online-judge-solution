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
	int n, x;
	cin >> n;
	int idx[n]={0};
	for (int i = 1; i <= n; i++) {
		cin >> x;
		idx[x] = i;
	}
	int ans = 1;
	for (int i = 2; i <= n; i++) {
		if (idx[i] < idx[i - 1])ans++;
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

