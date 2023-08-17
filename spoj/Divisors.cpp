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
const int N = 1e4 + 5;

bool isprime[N];
int cnt[N];
vector<int>divs[N];
set<int>ans[MX];

void sieve() {
	isprime[2] = 1;
	for (int i = 3; i < N; i += 2)isprime[i] = 1;
	for (int i = 3; i * i < N; i += 2) {
		if (isprime[i]) {
			for (int j = i * i; j < N; j += i)
				isprime[j] = 0;
		}
	}
	for (int i = 1; i < N; i++) {
		if (isprime[i])continue;
		for (int j = i; j < N; j += i)divs[j].pb(i);
	}
}

void solve(int t) {
	int n; cin >> n;
	int num = 0;
	while (n--) {
		string check; cin >> check;
		if (check == "UPD") {
			string op; cin >> op;
			if (op == "ADD") {
				int x; cin >> x;
				num++;
				for (int d : divs[x]) {
					cnt[d]++;
					ans[cnt[d]].insert(d);
				}
			}
			else {
				num--;
				int x; cin >> x;
				for (int d : divs[x]) {
					ans[cnt[d]].erase(d);
					cnt[d]--;
				}
			}
		}
		else {
			if (!num)cout << -1 << endl;
			else {
				for (int x : ans[num])cout << x << " ";
				cout << endl;
			}
		}
	}
	for (int i = 1; i < MX; i++)ans[i].clear();
	for (int i = 1; i < N; i++)cnt[i] = 0;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	sieve();
	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

// 1
// 8
// UPD ADD 6
// UPD ADD 15
// CON
// UPD ADD 24
// UPD ADD 54
// CON
// UPD REM 15
// CON