#include<bits/stdc++.h>
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
#define  pi      acos(-1)
#define  mod     1000000007
using namespace std;
const int N = 5e3 + 3;

vector<int>adj[N];
int cost[N][N];
int dis[N];

void bfs(int st) {
	for (int i = 0; i < N; i++) {
		dis[i] = INT_MAX;
	}
	dis[st] = 0;
	queue<int>q;
	q.push(st);
	while (!q.empty()) {
		int node = q.front();
		int val = dis[node];
		q.pop();
		for (int child : adj[node]) {
			int wt = cost[node][child];
			int mx = max(val, wt);
			if (dis[child] > mx) {
				dis[child] = mx;
				q.push(child);
			}
		}
	}
}

void solve(int t) {
	int n, m, st;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		if (cost[u][v]) {
			cost[u][v] = cost[v][u] = min(cost[u][v], w);
		}
		else {
			cost[u][v] = cost[v][u] = w;
			adj[u].pb(v);
			adj[v].pb(u);
		}
	}
	cin >> st;
	bfs(st);
	cout << "Case " << t << ":" << endl;
	for (int i = 0; i < n; i++) {
		if (dis[i] != INT_MAX)cout << dis[i] << endl;
		else cout << "Impossible\n";
	}
	for (int i = 0; i < n; i++) {
		adj[i].clear();
		for (int j = 0; j < n; j++)cost[i][j] = 0;
	}
}

signed main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

