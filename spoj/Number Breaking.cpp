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
const int N = 1e6 + 5;

int spf[N];

void sieve() {
	for (int i = 2; i < N; i++)spf[i] = i;
	for (int i = 2; i * i < N; i++) {
		if (spf[i] == i) {
			for (int j = i * 2; j < N; j += i)
				if (spf[j] == j)spf[j] = i;
		}
	}
}

void solve(int t) {
	int n; cin >> n;
	vector<int>primeDiv;
	while (n != 1) {
		int d = spf[n];
		primeDiv.pb(d);
		while (n % d == 0)n /= d;
	}
	sort(all(primeDiv));
	cout << "Case " << t << ": ";
	for (int p : primeDiv)cout << p << " ";
	cout << endl;
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

