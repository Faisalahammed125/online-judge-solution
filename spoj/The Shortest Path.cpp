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
const int inf = 1e17 + 5;

vector<PII>adj[N];

int dijkstra(int src, int des) {
	vector<int>dis(N, inf);
	set<PII>st;
	st.insert({0, src});
	dis[src] = 0;
	while (!st.empty()) {
		int v = (*st.begin()).ss;
		st.erase(st.begin());
		if (v == des)return dis[des];
		for (auto child : adj[v]) {
			int ch_v = child.ff;
			int wt = child.ss;
			if (dis[v] + wt < dis[ch_v]) {
				st.erase({dis[ch_v], ch_v});
				dis[ch_v] = dis[v] + wt;
				st.insert({dis[ch_v], ch_v});
			}
		}
	}
}

void solve(int t) {
	int n; cin >> n;
	map<string, int>mp;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		mp[s] = i;
		int con; cin >> con;
		while (con--) {
			int x, y; cin >> x >> y;
			adj[i].pb({x, y});
		}
	}
	int r; cin >> r;
	while (r--) {
		string s1, s2; cin >> s1 >> s2;
		int x = mp[s1], y = mp[s2];
		cout << dijkstra(x, y) << endl;
	}
	for (int i = 1; i <= n; i++)adj[i].clear();
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

