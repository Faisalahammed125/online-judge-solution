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
const int N = 5e3 + 5;
const int dx[] = { +1, -1, +0, +0, -1, +1, +1, -1};
const int dy[] = { +0, +0, +1, -1, -1, +1, -1, +1};

int row, col, cx, cy;
int ans[N][N];
bool vis[N][N];

bool isvalid(int x, int y) {
	if (x >= 0 && x < row && y >= 0 && y < col && !vis[x][y])return true;
	return false;
}

void bfs() {
	vis[cx][cy] = true;
	queue<PII>q;
	q.push({cx, cy});
	while (!q.empty()) {
		int x = q.front().ff;
		int y = q.front().ss;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (isvalid(xx, yy)) {
				vis[xx][yy] = true;
				q.push({xx, yy});
				ans[xx][yy] = ans[x][y] + 1;
			}
		}
	}
}

void solve(int t) {
	cin >> row >> col >> cx >> cy;
	bfs();
	rep(i, 0, row - 1) {
		rep(j, 0, col - 1)cout << ans[i][j] << " ";
		cout << endl;
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	//cin>>T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

