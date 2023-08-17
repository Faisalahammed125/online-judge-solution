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
const int N = 5e5 + 5;

void solve(int t) {
	while (1) {
		int n, k; cin >> n >> k;
		if (n == -1 && k == -1)return;
		if (k <= 2) {
			cout << 0 << endl;
			continue;
		}
		k -= 2;
		int tm = (k + 1) / 2;
		int p;
		if (k & 1)p = tm * tm;
		else p = tm * (tm + 1);
		int q = (n * (n - 1)) / 2;
		int g = __gcd(p, q);
		cout << (p / g) << "/" << (q / g) << endl;
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	// cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}
