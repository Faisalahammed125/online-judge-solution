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
const int N = 5e6 + 5;

int mp1[N], mp2[N];
vector<int>v1, v2;

void fact(int x, int *mp, vector<int>&vec) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			vec.pb(i);
			while (x % i == 0) {
				x /= i;
				mp[i]++;
			}
		}
	}
	if (x > 1) {
		vec.pb(x);
		mp[x]++;
	}
}

bool check(int n, int *mp, vector<int>&v) {
	for (int div : v) {
		int m = n, p = 0;
		while (m)
		{
			p += (m / div);
			m /= div;
		}
		if (mp[div] > p) return false;
	}
	return true;
}

void solve(int t) {
	int a, b;
	cin >> a >> b;
	fact(a, mp1, v1);
	fact(b, mp2, v2);
	bool ok1 = false, ok2 = false;
	int x1 = -1, x2 = -1;
	for (int i = 2; i <= b; i++) {
		if (!ok1) {
			if (check(i, mp1, v1)) {
				ok1 = true;
				x1 = i;
			}
		}
		if (!ok2) {
			if (check(i, mp2, v2)) {
				ok2 = true;
				x2 = i;
			}
		}
		if (ok1 && ok2)break;
	}
	cout << max(0LL, x2 - x1) << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	//cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

