/*
the formula is SOD=(cnt1+1)*(cnt2+1).......
where n=(p1^cnt1)*(p2^cnt2).....
here p1,p2 are prime factor of n
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int NOD = 1;
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				int cnt = 0;
				while (n % i == 0) {
					n /= i;
					cnt++;
				}
				//cout<<n<<" "<<cnt<<endl;
				NOD = NOD * (cnt + 1);
			}
		}
		if (n > 1)NOD *= 2;
		cout << NOD << endl;
	}
	return 0;
}