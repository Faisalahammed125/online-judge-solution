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
const int N = 2e5 + 5;

int arr[N];
int tree[4 * N];

void init(int node, int l, int r) {
	if (l == r) {
		tree[node] = arr[l];
		return;
	}
	int left = 2 * node;
	int right = 2 * node + 1;
	int md = l + (r - l) / 2;
	init(left, l, md);
	init(right, md + 1, r);
	tree[node] = min(tree[left] , tree[right]);
}

int query(int node, int s, int e, int l, int r) {
	if (l > e || r < s)return 1e10;
	if (s >= l && e <= r)return tree[node];
	int left = 2 * node;
	int right = 2 * node + 1;
	int md = s + (e - s) / 2;
	return min(query(left, s, md, l, r), query(right, md + 1, e, l, r));
}

void solve(int t) {
	int n, q; cin >> n >> q;
	rep(i, 1, n)cin >> arr[i];
	init(1, 1, n);
	while (q--) {
		int l, r; cin >> l >> r;
		cout << query(1, 1, n, l, r) << endl;
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	// cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

