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

int dp[70][70];
string inp;

int wow(int i, int j) {
	if (i > j)return 0;
	if (dp[i][j] != -1)return dp[i][j];
	else {
		///if the character matches
		if (inp[i] == inp[j])
			return dp[i][j] = wow(i, j - 1) + wow(i + 1, j) + 1;
		///if the character doesn't match
		///the reason for subtracting (i+1,j-1) is the previous two item add (i+1,j-1) which is not required cz character doesnt match
		else return dp[i][j] = wow(i, j - 1) + wow(i + 1, j) - wow(i + 1, j - 1);
	}
}

void solve(int t) {
	cin >> inp;
	memset(dp, -1, sizeof(dp));
	cout << "Case " << t << ": " << wow(0, inp.size() - 1) << endl;
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

