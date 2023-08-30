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
	int x1, x2, x3, y1, y2, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	int val = (x1 - x2) * (y1 - y3) - (x1 - x3) * (y1 - y2);
	if (val > 0)cout << "LEFT" << endl;
	else if (val == 0)cout << "TOUCH" << endl;
	else cout << "RIGHT" << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

