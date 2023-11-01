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
const int N = 1e5 + 5;

vector<int> adj[N], radj[N], order, adj2[N];
vector<bool> vis;
vector<int>scc;
map<PII, int>done;
int coin[N], cnt, cost[N];

void dfs1(int node) {
	vis[node] = 1;
	for (int x : adj[node]) {
		if (!vis[x])dfs1(x);
	}
	order.pb(node);
}

void dfs2(int node, int k) {
	vis[node] = 1;
	scc[node] = k;
	cnt += coin[node];
	for (int x : radj[node]) {
		if (!vis[x])dfs2(x, k);
	}
}

void make_Condensation_graph(int n) {
	for (int i = 1; i <= n; i++) {
		for (int ch : adj[i]) {
			int x = scc[ch];
			int y = scc[i];
			if (x != y && !done[ {x, y}]) {
				done[ {x, y}]++;
				adj2[x].pb(y);
			}
		}
	}
}

void dfs3(int node) {
	int mx = 0;
	vis[node] = 1;
	for (int x : adj2[node]) {
		if (!vis[x]) {
			dfs3(x);
		}
		mx = max(mx, cost[x]);
	}
	cost[node] += mx;
}

void solve(int t) {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> coin[i];
	while (m--) {
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		radj[y].pb(x);
	}
	vis.assign(n + 1, false);
	for (int i = 1; i <= n; i++) {
		if (!vis[i])
			dfs1(i);
	}
	vis.assign(n + 1, false);
	scc.assign(n + 1, 0);
	reverse(all(order));
	int k = 0;
	for (int x : order) {
		if (!vis[x]) {
			k++;
			dfs2(x, k);
			cost[k] = cnt;
			cnt = 0;
		}
	}
	make_Condensation_graph(n);
	vis.assign(k + 1, false);
	for (int i = 1; i <= k; i++) {
		if (!vis[i])
			dfs3(i);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)ans = max(ans, cost[i]);
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
