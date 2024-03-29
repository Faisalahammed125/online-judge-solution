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
	int n;
	cin >> n;
	int arr[n + 5];
	int high = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		high = max(high, arr[i]);
	}
	int divisors[high + 1] = {0};
	for (int i = 0; i < n; i++) {
		for (int j = 1; j * j <= arr[i]; j++) {
			if (arr[i] % j == 0) {
				divisors[j]++;
				if (j != arr[i] / j)divisors[arr[i] / j]++;
			}
		}
	}
	for (int i = high; i >= 1; i--) {
		if (divisors[i] > 1) {
			cout << i << endl;
			break;
		}
	}
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

