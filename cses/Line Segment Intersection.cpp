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

struct point {
	int x, y;
};

int direction(point a, point b, point c) {
	int d = (b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x);
	if (d > 0)return 1; //clockwise
	if (d < 0)return 2; //counter-clockwise
	return 0;           //co-linear
}

bool overlap(point a, point b, point c) {
	int d = direction(a, b, c);
	if (d == 0) {
		if ((c.x <= max(a.x, b.x) && c.x >= min(a.x, b.x)) && (c.y <= max(a.y, b.y) && c.y >= min(a.y, b.y)))
			return true;
	}
	return false;
}

void solve(int t) {
	point a, b, c, d; cin >> a.x >> a.y >> b.x >> b.y;
	cin >> c.x >> c.y >> d.x >> d.y;
	int d1 = direction(a, b, c);
	int d2 = direction(a, b, d);
	int d3 = direction(c, d, a);
	int d4 = direction(c, d, b);
	// cout << d1 << " " << d2 << " " << d3 << " " << d4 << endl;
	if (d1 != d2 && d3 != d4)cout << "YES" << endl;
	else if (d1 == 0 && overlap(a, b, c))cout << "YES" << endl;
	else if (d2 == 0 && overlap(a, b, d))cout << "YES" << endl;
	else if (d3 == 0 && overlap(c, d, a))cout << "YES" << endl;
	else if (d4 == 0 && overlap(c, d, b))cout << "YES" << endl;
	else cout << "NO" << endl;
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

