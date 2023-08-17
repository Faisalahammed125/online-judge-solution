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
	int n, sum; cin >> n >> sum;
	vector<PII>ar;
	rep(i, 0, n - 1) {
		int x; cin >> x;
		ar.pb({x, i + 1});
	}
	sort(all(ar));
	rep(i, 0, n - 3) {
		int j = i + 1, k = n - 1;
		while (j < k) {
			if (ar[i].ff + ar[j].ff + ar[k].ff == sum) {
				cout << ar[i].ss << " " << ar[j].ss << " " << ar[k].ss << endl;
				return;
			}
			if (ar[i].ff + ar[j].ff + ar[k].ff < sum)j++;
			else k--;
		}
	}
	cout << "IMPOSSIBLE" << endl;
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

