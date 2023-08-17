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

int bs(int arr[], int tar, int n) {
	int low = 0, high = n - 1, ret = -1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] == tar) {
			ret = mid;
			high = mid - 1;
		}
		else if (arr[mid] < tar)low = mid + 1;
		else high = mid - 1;;
	}
	return ret;
}

void solve(int t) {
	int n, q, x;
	cin >> n >> q;
	int arr[n];
	for (int &x : arr)cin >> x;
	while (q--) {
		cin >> x;
		cout << bs(arr, x, n) << endl;
	}
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