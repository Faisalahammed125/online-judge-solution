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

bool ok[N];
vector<PII>pfactor;
vector<int>prime, ans;
map<int, int>isprime;

void sieve() {
	for (int i = 2; i < N; i++) {
		if (!ok[i]) {
			for (int j = i * i; j < N; j += i)
				ok[j] = 1;
		}
	}
	for (int i = 2; i < N; i++)if (!ok[i])prime.pb(i);
}

void generateDivisors(int curindex, int curdivisor) {
	if (curindex == pfactor.size()) {
		if (!isprime[curdivisor])ans.pb(curdivisor);
		return;
	}
	for (int i = 0; i <= pfactor[curindex].ff; i++) {
		generateDivisors(curindex + 1, curdivisor);
		curdivisor *= pfactor[curindex].ss;
	}
}

void allclear() {
	ans.clear();
	pfactor.clear();
	isprime.clear();
}
void solve(int t) {
	int n; cin >> n;
	if (n == 0) {
		cout << 0 << " " << 0 << endl;
		return;
	}
	if (n & 1) {
		cout << 0 << endl;
		return;
	}
	n /= 2;
	for (int d : prime) {
		if (d * d > n)break;
		if (n % d == 0) {
			int cnt = 0;
			while (n % d == 0) {
				cnt++;
				n /= d;
			}
			pfactor.pb({cnt, d});
			isprime[d] = 1;
		}
	}
	if (n > 1)pfactor.pb({1, n}), isprime[n] = 1;
	generateDivisors(0, 1);
	sort(all(ans));
	cout << ans.size() << " ";
	for (int d : ans)cout << d << " ";
	cout << endl;
	allclear();
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	sieve();
	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}