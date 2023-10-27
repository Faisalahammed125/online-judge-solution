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
const int N = 1e3 + 5;
const int dx[] = {0, 0, +1, -1};
const int dy[] = { +1, -1, 0, 0};

int n, m;
char grid[N][N], path[N][N];
int dis[N][N], step[N][N];
bool vis[N][N];
queue<PII>q;

bool isvalid(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && grid[x][y] != '#')
		return true;
	return false;
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().ff;
		int y = q.front().ss;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			// cout << xx << " " << yy << endl;
			if (isvalid(xx, yy)) {
				q.push({xx, yy});
				vis[xx][yy] = 1;
				dis[xx][yy] = dis[x][y] + 1;
			}
		}
	}
}

void solve(int t) {
	PII st;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'M') {
				q.push({i, j});
				vis[i][j] = 1;
			}
			if (grid[i][j] == 'A')st = {i, j};
		}
	}
	bfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)vis[i][j] = 0;
	}
	q.push(st);
	vis[st.ff][st.ss] = 1;
	path[st.ff][st.ss] = '$';
	while (!q.empty()) {
		int x = q.front().ff;
		int y = q.front().ss;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (isvalid(xx, yy) && ((!dis[xx][yy] && grid[xx][yy] == '.') || dis[xx][yy] > (step[x][y] + 1))) {
				step[xx][yy] = step[x][y] + 1;
				vis[xx][yy] = 1;
				q.push({xx, yy});
				if (i == 0)path[xx][yy] = 'R';
				else if (i == 1)path[xx][yy] = 'L';
				else if (i == 2)path[xx][yy] = 'D';
				else if (i == 3)path[xx][yy] = 'U';
			}
		}
	}
	int tx, ty, sp = 1e7;
	for (int i = 0; i < m; i++) {
		if (vis[0][i] && step[0][i] < sp) {
			tx = 0, ty = i;
			sp = step[0][i];
		}
		if (vis[n - 1][i] && step[n - 1][i] < sp) {
			tx = n - 1, ty = i;
			sp = step[n - 1][i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (vis[i][0] && step[i][0] < sp) {
			tx = i, ty = 0;
			sp = step[i][0];
		}
		if (vis[i][m - 1] && step[i][m - 1] < sp) {
			tx = i, ty = m - 1;
			sp = step[i][m - 1];
		}
	}
	if (sp == 1e7) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl << sp << endl;
	string ans;
	while (path[tx][ty] != '$') {
		ans += path[tx][ty];
		if (path[tx][ty] == 'D')tx -= 1;
		else if (path[tx][ty] == 'U')tx += 1;
		else if (path[tx][ty] == 'R')ty -= 1;
		else if (path[tx][ty] == 'L') ty += 1;
	}
	reverse(all(ans));
	cout << ans << endl;
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