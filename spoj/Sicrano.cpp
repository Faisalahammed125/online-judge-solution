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
	vector<PII>points;
	rep(i, 0, n - 1) {
		int x, y; cin >> x >> y;
		points.pb({x, y});
	}
	rep(i, 0, k - 1) {
		int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
		int dx = x1 - x2; int dy = y1 - y2;
		int c = dx * y1 - dy * x1;
		int ans = 0;
		for (auto it : points) {
			int xx = it.ff; int yy = it.ss;
			int left = yy * dx;
			int right = xx * dy + c;
			if (left == right) {
				if (x1 > x2)swap(x1, x2);
				if (y1 > y2)swap(y1, y2);
				if ((xx >= x1 && xx <= x2) && (yy >= y1 && yy <= y2))
					ans++;
			}
		}
		cout << ans << endl;
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

