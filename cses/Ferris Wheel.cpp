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
	int n, x;
	cin >> n >> x;
	int arr[n];
	for (int &p : arr)cin >> p;
	sort(arr, arr + n);
	int i = 0, j = n - 1;
	while (i < j) {
		if (arr[i] + arr[j] <= x) {
			arr[i] = 0;
			i++;
			j--;
		}
		else j--;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)if (arr[i])ans++;
	cout << ans << endl;
}

signed main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	int T = 1;
	//cin>>T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

