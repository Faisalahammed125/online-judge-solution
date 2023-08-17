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
	int n; cin >> n;
	vector<int>vec(n + 1);
	for (int i = 1; i <= n; i++)cin >> vec[i];
	vec[0] = 0;
	for (int i = 2; i <= n; i++) {
		if (vec[i] % vec[i - 1] == 0)vec[i - 1]++;
		if (i - 2 == 0)continue;
		if (vec[i - 1] % vec[i - 2] == 0)vec[i - 1]++;
	}
	if (n == 1) {
		cout << vec[1] << endl;
		return;
	}
	if (vec[n] % vec[n - 1] == 0)vec[n]++;
	for (int i = 1; i <= n; i++)cout << vec[i] << " ";
	cout << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

