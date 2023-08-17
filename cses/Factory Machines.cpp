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
int n, m;
int arr[N];

int can(int x) {
	int par = 0;
	rep(i, 0, n - 1) {
		par += x / arr[i];
		if (par >= 1e18)return 1e18;
	}
	return par;
}

void solve(int t) {
	cin >> n >> m;
	int mx = 0;
	rep(i, 0, n - 1) {
		cin >> arr[i];
		mx = max(mx, arr[i]);
	}
	int l = 0; int r = m * mx;
	int ans = r;
	while (l <= r) {
		int md = l + (r - l) / 2;
		if (can(md) < m)
			l = md + 1;
		else {
			ans = md;
			r = md - 1;
		}
	}
	cout << ans << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	// cin>>T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

