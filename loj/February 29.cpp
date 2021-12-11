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
	string start_month, end_month;
	int start_date, end_date, start_year, end_year;
	char comma;
	cin >> start_month >> start_date >> comma >> start_year;
	cin >> end_month >> end_date >> comma >> end_year;
	if (start_month != "January" && start_month != "February")start_year++;
	if (end_month == "January" || (end_month == "February" && end_date <= 28))end_year--;
	int ans = end_year / 4 - (start_year - 1) / 4;
	ans -= (end_year / 100 - (start_year - 1) / 100);
	ans += (end_year / 400 - (start_year - 1) / 400);
	cout << "Case " << t << ": " << ans << endl;
}


signed main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

