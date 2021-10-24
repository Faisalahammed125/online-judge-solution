#include <bits/stdc++.h>
using namespace std;

int main() {
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
	return 0;
}