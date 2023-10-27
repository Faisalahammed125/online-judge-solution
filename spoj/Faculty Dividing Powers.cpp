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
			prime.pb(i);
			for (int j = i * i; j < N; j += i)
				ok[j] = 1;
		}
	}
}

void solve(int t) {
	int n, k; cin >> n >> k;
	map<int, int>fact;
	for (int p : prime) {
		if (p * p > k)break;
		while (k % p == 0) {
			fact[p]++;
			k /= p;
		}
	}
	if (k > 1)fact[k]++;
	int ans = 1e18 + 7;
	for (auto it : fact) {
		int tmp = n, cnt = 0;
		while (tmp) {
			cnt += tmp / it.ff;
			tmp /= it.ff;
		}
		ans = min(ans, cnt / it.ss);
	}
	cout << ans << endl;
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