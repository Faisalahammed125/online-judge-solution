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
const int N = 2e5 + 5;
int spf[N];
vector<int>vec[2200];

void sieve() {
	for (int i = 2; i < N; i++)spf[i] = i;
	for (int i = 2; i * i < N; i++) {
		if (spf[i] == i) {
			for (int j = i * 2; j < N; j += i) {
				if (spf[j] == j)
					spf[j] = i;
			}
		}
	}
}

void fact() {
	for (int i = 2; i < N; i++) {
		int x = i;
		int divs = 1;
		while (x != 1) {
			int d = spf[x];
			int cnt = 0;
			while (x % d == 0) {
				x /= d;
				cnt++;
			}
			divs *= (cnt * 2 + 1);
		}
		vec[divs].pb(i * i);
	}
}

void solve(int t) {
	int k, low, high; cin >> k >> low >> high;
	if (k > 2200 || !vec[k].size()) {
		cout << 0 << endl;
		return;
	}
	int l = lower_bound(all(vec[k]), low) - vec[k].begin();
	int r = upper_bound(all(vec[k]), high) - vec[k].begin();
	cout << r - l << endl;
}

signed main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	sieve();
	fact();
	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

