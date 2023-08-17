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
const int N = 2e6 + 5;
double mem[N];

void memo() {
	for (int i = 1; i < N; i++)mem[i] = mem[i - 1] + log(i);
}

void solve(int t) {
	int num, base;
	cin >> num >> base;
	int ans = mem[num] / log(base);
	cout << "Case " << t << ": " << ans + 1 << endl;
}

signed main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	int T = 1;
	memo();
	cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

