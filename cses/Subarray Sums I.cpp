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
	int n, x; cin >> n >> x;
	int arr[n];
	for (int &v : arr)cin >> v;
	int sum = 0, i = 0, j = 0, ans = 0;
	while (i < n) {
		while (sum < x && i < n) {
			sum += arr[i];
			i++;
		}
		if (sum == x)ans++;
		while (sum >= x && j < n) {
			sum -= arr[j];
			if (sum == x)ans++;
			j++;
		}
	}
	cout << ans << endl;
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

