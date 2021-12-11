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

vector<int> convert(string x, int base) {
	reverse(all(x));
	int a = 0, p = 1;
	vector<int>v;
	for (char c : x) {
		if (c == '.') {
			v.pb(a);
			a = 0;
			p = 1;
			continue;
		}
		int temp = c - '0';
		a += (temp * p);
		p *= base;
	}
	v.pb(a);
	return v;
}

void solve(int t) {
	string dec, bin;
	cin >> dec >> bin;
	vector<int>dc, bn;
	dc = convert(dec, 10);
	bn = convert(bin, 2);
	if (dc == bn)cout << "Case " << t << ": Yes" << endl;
	else cout << "Case " << t << ": No" << endl;
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

