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

int par[N], col[N];

int find(int x) {
	if (par[x] == x)return x;
	return par[x] = find(par[x]);
}

void connect(int u, int v) {
	int a = find(u);
	int b = find(v);
	par[u] = max(a, b);
	par[v] = max(a, b);
}

void solve(int t) {
	int n, q; cin >> n >> q;
	int l[q], r[q], c[q];
	rep(i, 1, n + 1) par[i] = i;
	rep(i, 0, q - 1) {
		cin >> l[i] >> r[i] >> c[i];
	}
	irep(i, q - 1, 0) {
		int next = find(l[i]);
		while (next <= r[i]) {
			col[next] = c[i];
			// if (next + 1 > n)break;
			connect(next, next + 1);
			next = find(next);
		}
	}
	rep(i, 1, n)cout << col[i] << endl;
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

