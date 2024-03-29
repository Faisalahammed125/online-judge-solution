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

vector<int> adj[N], radj[N], order;
vector<bool> vis;

void dfs1(int node) {
	vis[node] = 1;
	for (int x : adj[node]) {
		if (!vis[x])dfs1(x);
	}
	order.pb(node);
}

void dfs2(int node) {
	vis[node] = 1;
	for (int x : radj[node]) {
		if (!vis[x])dfs2(x);
	}
}

void solve(int t) {
	int n, m; cin >> n >> m;
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
	reverse(all(order));
	vector<int>ans;
	for (int x : order) {
		if (!vis[x]) {
			ans.pb(x);
			dfs2(x);
		}
	}
	if (ans.size() <= 1) {
		cout << "YES" << endl;
		return;
	}
	cout << "NO" << endl << ans[ans.size() - 1] << " " << ans[ans.size() - 2] << endl;
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