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

bool ok[N];
vector<int>prime;

void sieve() {
	for (int i = 2; i < N; i++) {
		if (!ok[i]) {
			for (int j = i * i; j < N; j += i)
				ok[j] = 1;
		}
	}
	for (int i = 2; i < N; i++) {
		if (!ok[i])prime.pb(i);
	}
}

void solve(int t) {
	int n; cin >> n;
	set<int>pd;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		for (int p : prime) {
			if (p * p > x)break;
			if (x % p == 0) {
				while (x % p == 0)x /= p;
				pd.insert(p);
			}
		}
		if (x > 1)pd.insert(x);
	}
	cout << "Case #" << t << ": " << pd.size() << endl;
	for (auto it : pd) {
		cout << it << endl;
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	sieve();
	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}