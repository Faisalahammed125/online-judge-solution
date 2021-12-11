#include<bits/stdc++.h>
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
#define  pi      acos(-1)
#define  mod     1000000007
using namespace std;
const int N = 5e5 + 5;

void solve(int t) {
	int n, x, p1, p2;
	cin >> n >> x;
	map<int, int>pos, mark;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		pos[arr[i]] = i + 1;
		mark[arr[i]]++;
	}
	bool ok = 0;
	for (int i = 0; i < n; i++) {
		int val = arr[i];
		if (val > x)continue;
		int rem = x - val;
		//cout << val << " " << rem << endl;
		if (mark[rem]) {
			p1 = pos[val];
			p2 = pos[rem];
			if (p1 == p2) {
				if (mark[rem] > 1) {
					for (int i = 0; i < n; i++) {
						if (arr[i] == rem && (i + 1) != p1) {
							p2 = i + 1;
							break;
						}
					}
				}
				else continue;
			}
			ok = 1;
			break;
		}
	}
	if (ok)cout << p1 << " " << p2 << endl;
	else cout << "IMPOSSIBLE" << endl;
}

signed main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	int T = 1;
	//cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

