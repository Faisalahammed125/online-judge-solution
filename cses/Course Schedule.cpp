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

vector<int>adj[N];
int vis[N];
vector<int>ans;
bool cycle;

void dfs(int v) {
	vis[v] = 1;
	for (int u : adj[v]) {
		if (vis[u] == 1)cycle = 1;
		if (!vis[u])dfs(u);
		if (cycle)return;
	}
	vis[v] = 2;
	ans.pb(v);
}

void solve(int t) {
	int n, m; cin >> n >> m;
	while (m--) {
		int x, y; cin >> x >> y;
		adj[y].pb(x);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	if (cycle) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	for (int x : ans)cout << x << " ";
	cout << endl;

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