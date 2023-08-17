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
	int n, k; cin >> n >> k;
	n--;
	int arr[k];
	for (int &x : arr)cin >> x;
	if (n < 1e6) {
		int ans = n;
		vector<bool>divided(n + 5, false);
		for (int i = 0; i < k; i++) {
			for (int j = 1; j <= n; j++) {
				if (!divided[j] && j % arr[i] == 0) {
					divided[j] = 1;
					ans--;
				}
			}
		}
		cout << ans << endl;
		return;
	}
	int eat = 0;
	for (int i = 1; i < (1 << k); i++) {
		int lcm = 1;
		int bit = __builtin_popcount(i);
		for (int j = 0; j < k; j++) {
			if (i & (1 << j)) {
				int tmp = arr[j];
				int gcd = __gcd(lcm, tmp);
				tmp /= gcd;
				if (lcm > (n / tmp)) {
					lcm = n + 1;
					break;
				}
				lcm = (lcm * tmp);
			}
		}
		if (bit & 1)eat += (n / lcm);
		else eat -= (n / lcm);
	}
	cout << n - eat << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	// cin>>T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}