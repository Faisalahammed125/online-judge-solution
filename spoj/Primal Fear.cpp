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

bool nonprime[N];
int fearPrime[N];

bool fear(int n) {
	int x = n, md = 10;
	while (x) {
		if (x % 10 == 0)return false;
		x /= 10;
	}
	x = 0;
	while (!nonprime[x] && x < n) {
		x = n % md;
		md *= 10;
	}
	return (x == n);
}

void sieve() {
	nonprime[1] = 1;
	for (int i = 2; i * i < N; i++) {
		if (!nonprime[i]) {
			for (int j = i * i; j < N; j += i)nonprime[j] = 1;
		}
	}
	for (int i = 2; i < N; i++) {
		if (!nonprime[i]) {
			if (fear(i))fearPrime[i]++;
		}
		fearPrime[i] += fearPrime[i - 1];
	}
}

void solve(int t) {
	int n; cin >> n;
	cout << fearPrime[n] << endl;
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

