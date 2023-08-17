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
const int N = 5e6 + 5;

int spf[N]; int cnt[N];

void sieve() {
	for (int i = 2; i < N; i++)spf[i] = i;
	for (int i = 2; i < N; i++) {
		if (spf[i] == i) {
			for (int j = i * i; j < N; j += i) {
				if (spf[j] == j)spf[j] = i;
			}
		}
	}
}

void solve(int t) {
	int n; cin >> n;
	int arr[n];
	int ans = 0, d1 = 0, d2 = 0, mx = 0, p = 0, val = 0;
	for (int &x : arr) {
		cin >> x;
		if (x % 2)d1++;
		if (x % 3)d2++;
		mx = max(x, mx);
		int tmp = x;
		while (tmp > 1) {
			int d = spf[tmp];
			cnt[d]++;
			if (cnt[d] > val) {
				val = cnt[d];
				p = d;
			}
			else if (cnt[d] == val)p = min(p, d);
			while (tmp % d == 0)tmp /= d;
		}
	}
	if (!mx) {
		cout << 2 << endl;
		return;
	}
	// cout << p << " " << val << endl;
	ans = min(d1, d2);
	if (!p) {
		cout << ans << endl;
		return;
	}
	int d = 0;
	rep(i, 0, n - 1) {
		if (arr[i] % p)d += min(arr[i] % p, p - arr[i] % p);
	}
	ans = min(ans, d);
	cout << ans << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	sieve();
	int T = 1;
	// cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

