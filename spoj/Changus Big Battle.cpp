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

bool check(int x, int n) {
	int tmp = (x + 1) / 2;
	int val;
	if (tmp & 1)val = ((tmp + 1) / 2) * tmp;
	else val = (tmp / 2) * (tmp + 1);
	val *= 2;
	if (x & 1)val -= tmp;
	if (val < n)return false;
	else return true;
}

void solve(int t) {
	int n; cin >> n;
	int l = 1, r = 1e10 + 5;
	while (l < r) {
		int m = l + (r - l) / 2;
		if (!check(m, n))l = m + 1;
		else r = m;
		// cout << l << " " << m << " " << r << endl;
	}
	cout << l << endl;
}

signed main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

