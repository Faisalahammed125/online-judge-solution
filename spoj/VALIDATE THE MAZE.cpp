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
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int n, m, sx, sy, ex, ey;
char grid[25][25];
int vis[25][25];

bool isvalid(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && grid[x][y] == '.')return true;
	return false;
}

bool dfs(int x, int y) {
	if (x == ex && y == ey)return 1;
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i]; int yy = y + dy[i];
		if (isvalid(xx, yy)) {
			if (dfs(xx, yy))return 1;
		}
	}
	return 0;
}

void solve(int t) {
	rep(i, 0, 25) {
		rep(j, 0, 25)vis[i][j] = 0;
	}
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)cin >> grid[i][j];
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && grid[i][j] == '.') {
				if (cnt == 0) {
					sx = i; sy = j;
				}
				if (cnt == 1) {
					ex = i; ey = j;
				}
				cnt++;
			}
		}
	}
	if (cnt > 2 || (n == 1 && m == 1) || cnt <= 1) {
		cout << "invalid" << endl;
		return;
	}
	if (dfs(sx, sy))cout << "valid" << endl;
	else cout << "invalid" << endl;
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

