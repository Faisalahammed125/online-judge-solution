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

void solve(int t) {
	int n; cin >> n;
	int mem[n + 1][n + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++)mem[i][j] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char ch; cin >> ch;
			if (ch == '*')mem[i][j] = -1;
		}
	}
	if (mem[1][1] == -1 || mem[n][n] == -1) {
		cout << 0 << endl;
		return;
	}
	mem[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mem[i][j] == -1)continue;
			if (mem[i][j - 1] != -1)(mem[i][j] += mem[i][j - 1]) %= mod;
			if (mem[i - 1][j] != -1)(mem[i][j] += mem[i - 1][j]) %= mod;
		}
	}
	cout << mem[n][n] << endl;
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