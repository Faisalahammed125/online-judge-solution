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
int sub[N];
vector<int>adj[N];

void dfs(int node) {
	if (adj[node].empty()) {
		return;
	}
	for (int x : adj[node]) {
		if (!sub[x])dfs(x);
		sub[node] += sub[x] + 1;
	}
}


void solve(int t) {
	int n; cin >> n;
	rep(i, 2, n) {
		int x; cin >> x;
		adj[x].pb(i);
	}
	dfs(1);
	rep(i, 1, n)cout << sub[i] << " ";
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