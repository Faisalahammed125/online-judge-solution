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
vector<int>adj[N];
int dia = 0;
int len[N];

void dfs(int node, int par) {
	for (int x : adj[node]) {
		if (x == par)continue;
		dfs(x, node);
		len[node] = max(len[node], len[x] + 1);
	}
	if (par != -1)dia = max(dia, len[node] + len[par] + 1);
}

void solve(int t) {
	int n; cin >> n;
	rep(i, 1, n - 1) {
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1, -1);
	cout << dia << endl;
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

