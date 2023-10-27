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
bool vis[N], ok[N];

void _init(int n) {
	rep(i, 1, n)vis[i] = 0;
}

void dfs(int node) {
	vis[node] = 1;
	for (int x : adj[node]) {
		if (!vis[x])
			dfs(x);
	}
}

bool bfs(int src) {
	queue<int>q;
	q.push(src);
	vis[src] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int y : adj[x]) {
			if (ok[y])return true;
			if (!vis[y]) {
				vis[y] = 1;
				q.push(y);
			}
		}
	}
	return false;
}
void solve(int t) {
	int n, m; cin >> n >> m;
	while (m--) {
		int x, y; cin >> x >> y;
		adj[x].pb(y);
	}
	dfs(1);
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) {
			cout << "NO" << endl;
			cout << 1 << " " << i << endl;
			return;
		}
	}
	ok[1] = 1;
	for (int i = 2; i <= n; i++) {
		_init(n);
		if (bfs(i)) {
			ok[i] = 1;
			continue;
		}
		cout << "NO" << endl;
		for (int j = 1; j <= n; j++) {
			if (!vis[j]) {
				cout << i << " " << j << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
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