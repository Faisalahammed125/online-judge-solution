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
const int INF = 1e9 + 7;

struct point
{
	int x, y;
};
int direction(point a, point b, point c) {
	int d = (b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x);
	if (d > 0)return 1; //clockwise
	if (d < 0)return 2; //counter-clockwise
	return 0;           //co-linear
}
bool overlap(point a, point b, point c) {
	return ((c.x <= max(a.x, b.x) && c.x >= min(a.x, b.x)) && (c.y <= max(a.y, b.y) && c.y >= min(a.y, b.y)));
}
bool intersect(point a, point b, point c, point d) {
	int d1 = direction(a, b, c);
	int d2 = direction(a, b, d);
	int d3 = direction(c, d, a);
	int d4 = direction(c, d, b);
	// if (d4 == 0 && d3 > 0)return 0;
	// if (d3 == 0 && d4 < 0)return 0;
	// cout << d1 << " " << d2 << " " << d3 << " " << d4 << endl;
	if (d1 != d2 && d3 != d4)return 1;
	return 0;
}

void solve(int t) {
	int n, m; cin >> n >> m;
	vector<point>vertex;
	for (int i = 0; i < n; i++) {
		int px, py; cin >> px >> py;
		vertex.pb({px, py});
	}
	vertex.pb(vertex[0]);
	vector<point>points;
	for (int i = 0; i < m; i++) {
		int px, py; cin >> px >> py;
		points.pb({px, py});
	}
	for (point it : points) {
		point _2 = {INF, INF + 1};
		bool boundary = 0;
		int no_intersect = 0;
		for (int i = 1; i <= n; i++) {
			point ft = vertex[i - 1];
			point sn = vertex[i];
			if (direction(ft, sn, it) == 0 && overlap(ft, sn, it)) {
				boundary = 1;
				break;
			}
			if (intersect(ft, sn, it, _2))no_intersect++;
		}
		if (boundary) {
			cout << "BOUNDARY" << endl;
			continue;
		}
		// cout << no_intersect << endl;
		if (no_intersect & 1)cout << "INSIDE" << endl;
		else cout << "OUTSIDE" << endl;
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

