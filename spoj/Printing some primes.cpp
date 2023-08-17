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
const int N = 1e8 + 5;

bool isprime[N];

void sieve() {
	for (int i = 2; i * i < N; i++) {
		if (!isprime[i]) {
			for (int j = i * i; j < N; j += i)isprime[j] = 1;
		}
	}
	int p = 0;
	for (int i = 2; i < N; i++) {
		if (!isprime[i]) {
			p++;
			if (p % 100 == 1)cout << i << endl;
		}
	}
}

void solve(int t) {
	sieve();
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	// cin>>T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

