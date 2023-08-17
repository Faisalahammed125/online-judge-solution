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

vector<int>adj[N];
vector<int>nodes;
int vis[N], rt;

bool dfs(int node, int par) {
	vis[node] = 1;
	nodes.pb(node);
	for (int child : adj[node]) {
		if (!vis[child]) {
			if (dfs(child, node) == true)
				return true;
		}
		else {
			if (child != par) {
				rt = child;
				return true;
			}
		}
	}
	vis[node] = 2;
	return false;
}

void solve(int t) {
	int n, m; cin >> n >> m;
	while (m--) {
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	bool ok = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i])ok = dfs(i, -1);
		if (ok)break;
	}
	if (!ok) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	vector<int>ans;
	ans.pb(rt);
	ok = 0;
	for (int x : nodes) {
		if (x == rt) {
			ok = 1;
			continue;
		}
		if (ok && vis[x] == 1) {
			ans.pb(x);
		}
	}
	ans.pb(rt);
	cout << ans.size() << endl;
	for (int x : ans)cout << x << " ";
	cout << endl;
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

