#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;
///  order_of_key return number of elements less than x.
///  find_by_order return index.
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  endl    "\n"
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
#define  pi      acos(-1)
#define  mod     1000000007

const int N = 5e5 + 5;

void solve(int t) {
	int n;
	cin >> n;
	int A[n], B[n], C[n], D[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	unordered_map<int, int>check;
	check.reserve(16000000);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int sum = C[i] + D[j];
			check[sum]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int sum = A[i] + B[j];
			int rem = 0LL - sum;
			if (check.find(rem) != check.end())ans += check[rem];
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
	//cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}