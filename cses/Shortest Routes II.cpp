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
const int N = 510;
const int inf = 1e17 + 5;

void floydWarshall(vector<vector<int>>&cost, int n) {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}
}

void solve(int t) {
	int n, m, q; cin >> n >> m >> q;
	vector<vector<int>>cost(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j)cost[i][j] = inf;
		}
	}
	for (int i = 1; i <= m; i++) {
		int x, y, wt; cin >> x >> y >> wt;
		cost[x][y] = min(wt, cost[x][y]);
		cost[y][x] = min(wt, cost[y][x]);
	}
	floydWarshall(cost, n);
	while (q--) {
		int x, y; cin >> x >> y;
		if (cost[x][y] == inf)cout << -1 << endl;
		else cout << cost[x][y] << endl;
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	// cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

