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
const int N = 2e5 + 5;
const int LOG = 21;

vector<int>adj[N];
int up[N][LOG];
int depth[N];

void dfs(int node, int par) {
	for (int x : adj[node]) {
		if (x == par)continue;
		depth[x] = depth[node] + 1;
		up[x][0] = node;
		for (int j = 1; j < LOG; j++) {
			up[x][j] = up[up[x][j - 1]][j - 1];
		}
		dfs(x, node);
	}
}

int get_lca(int a, int b) {
	if (depth[a] < depth[b])
		swap(a, b);
	int k = depth[a] - depth[b];
	for (int i = 0; i < LOG; i++) {
		if (k & (1 << i)) {
			a = up[a][i];
		}
	}
	if (a == b)return a;
	for (int j = LOG - 1; j >= 0; j--) {
		if (up[a][j] != up[b][j]) {
			a = up[a][j];
			b = up[b][j];
		}
	}
	return up[a][0];
}

void solve(int t) {
	int n, q; cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1, -1);
	while (q--) {
		int a, b; cin >> a >> b;
		int lca = get_lca(a, b);
		cout << depth[a] + depth[b] - 2 * depth[lca] << endl;
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	// cin>>T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

