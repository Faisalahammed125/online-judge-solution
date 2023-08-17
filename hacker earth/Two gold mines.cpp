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
const int dx[] = { +1, -1, +0, +0};
const int dy[] = { +0, +0, +1, -1};

int n;
int val[105][105];
bool vis[105][105];
char inp[105][105];

void allclear() {
	rep(i, 0, n - 1) {
		rep(j, 0, n - 1) {
			val[i][j] = 0;
			vis[i][j] = false;
		}
	}
}

bool isvalid(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n && !vis[x][y] && inp[x][y] != '#')return true;
	return false;
}

void bfs(int x1, int y1) {
	queue<PII>q;
	vis[x1][y1] = true;
	q.push({x1, y1});
	while (!q.empty()) {
		int x = q.front().ff;
		int y = q.front().ss;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (isvalid(xx, yy)) {
				vis[xx][yy] = true;
				val[xx][yy] = val[x][y] + 1;
				q.push({xx, yy});
			}
		}
	}
}

void solve(int t) {
	int gx1, gx2, gy1, gy2, fx1, fx2, fy1, fy2;
	bool ok1 = false, ok2 = false;
	cin >> n;
	rep(i, 0, n - 1) {
		rep(j, 0, n - 1) {
			cin >> inp[i][j];
			if (inp[i][j] == '*') {
				if (ok1) {
					gx2 = i;
					gy2 = j;
				}
				else {
					gx1 = i;
					gy1 = j;
					ok1 = true;
				}
			}
			if (inp[i][j] == '^') {
				if (ok2) {
					fx2 = i;
					fy2 = j;
				}
				else {
					fx1 = i;
					fy1 = j;
					ok2 = true;
				}
			}
		}
	}
	ok1 = false, ok2 = false;
	int v1 = 105, v2 = 105;
	bfs(fx1, fy1);
	if (vis[gx1][gy1]) {
		ok1 = true;
		v1 = val[gx1][gy1];
	}
	if (vis[gx2][gy2]) {
		ok2 = true;
		v2 = val[gx2][gy2];
	}
	allclear();
	bfs(fx2, fy2);
	if (vis[gx1][gy1]) {
		ok1 = true;
		v1 = min(v1, val[gx1][gy1]);
	}
	if (vis[gx2][gy2]) {
		ok2 = true;
		v2 = min(v2, val[gx2][gy2]);
	}
	allclear();
	if (ok1 && ok2) {
		cout << "YES" << endl;
		cout << max(v1, v2) << endl;
	}
	else cout << "NO" << endl;
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

