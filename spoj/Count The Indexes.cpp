//BISMILLAHIR RAHMANIR RAHEEM
#include<bits/stdc++.h>
#define  MX           200005
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

vector<int>vec[MX];

int BS(int val, int n) {
	int l = 0; int r = vec[val].size() - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (vec[val][m] >= n)
			r = m - 1;
		else
			l = m + 1;
	}
	return l;
}

void solve(int t) {
	int q; cin >> q;
	int idx = 0;
	map<int, int>mp;
	while (q--) {
		int op; cin >> op;
		if (op == 1) {
			int x; cin >> x;
			vec[x].pb(++idx);
			mp[idx] = x;
		}
		else if (!op) {
			if (!idx)cout << "Invalid" << endl;
			else {
				int val = mp[idx];
				vec[val].pop_back();
				idx--;
			}
		}
		else {
			int x, i, j; cin >> x >> i >> j;
			int idx1 = BS(x, i);
			int idx2 = BS(x, j + 1);
			// cout << idx1 << " " << idx2 << endl;
			cout << idx2 - idx1 << endl;
		}
	}
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

