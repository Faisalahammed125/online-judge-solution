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
	int n, k;
	cin >> n >> k;
	cout << "Case " << t << ": ";
	if (k > n) {
		cout << 0 << endl;
		return;
	}
	int m = k;
	int fact = 1, ans = 1;
	while (m)fact *= m--;
	while (k--) {
		int gcd = __gcd(fact, n * n);
		int tmp = (n * n) / gcd;
		ans *= tmp;
		fact /= gcd;
		n--;
	}
	cout << ans << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

