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
vector<int>dig;

int bin(int n) {
	if (n > 1) bin(n >> 1);
	dig.pb(n & 1);
}
int rev() {
	int val = 0;
	for (int i = 0; i < dig.size(); i++) {
		val += (dig[i] * pow(2, i));
	}
	return val;
}

void solve(int t) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		bin(x);
		if (x & 1)cout << x << endl;
		else cout << rev() << endl;
		dig.clear();
	}
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

