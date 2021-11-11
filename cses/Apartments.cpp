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
	int n, m, k;
	cin >> n >> m >> k;
	int arr[n], brr[m];
	for (int &x : arr)cin >> x;
	for (int &x : brr)cin >> x;
	sort(arr, arr + n);
	sort(brr, brr + m);
	int i = 0, j = 0, ans = 0;
	while (i < n && j < m) {
		if (abs(arr[i] - brr[j]) <= k) {
			i++;
			j++;
			ans++;
		}
		else if (arr[i] > brr[j])j++;
		else i++;
	}
	cout << ans << endl;
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

