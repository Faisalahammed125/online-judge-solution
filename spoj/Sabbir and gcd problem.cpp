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
const int N = 1e7 + 5;

vector<int>spf(N, 0);
vector<int>prime;

void sieve() {
	for (int i = 2; i < N; i++)spf[i] = i;
	for (int i = 2; i < N; i++) {
		if (spf[i] == i) {
			prime.pb(i);
			for (int j = i * i; j < N; j += i) {
				if (spf[j] == j)spf[j] = i;
			}
		}
	}
}

void solve(int t) {
	int n; cin >> n;
	bool flag[N] = {0};
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		while (x > 1) {
			flag[spf[x]] = 1;
			x /= spf[x];
		}
	}
	for (int p : prime) {
		if (!flag[p]) {
			cout << p << endl;
			return;
		}
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