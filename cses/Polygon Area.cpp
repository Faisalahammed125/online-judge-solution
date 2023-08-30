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
	int n; cin >> n;
	vector<PII>points;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		points.pb({x, y});
	}
	points.pb(points[0]);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = (points[i - 1].ff * points[i].ss) - (points[i - 1].ss * points[i].ff);
		ans += tmp;
	}
	cout << abs(ans) << endl;
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

