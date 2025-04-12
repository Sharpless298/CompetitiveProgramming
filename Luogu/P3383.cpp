#include <iostream>
#include <vector>
using namespace std;

int lpf[100000005];
vector<int> p;

void sieve(int n) {
	fill(lpf, lpf + n + 1, 1);

	for (int i = 2; i <= n; i++) {
		if (lpf[i] == 1) {
			lpf[i] = i;
			cout << i << '\n';
		}
		for (int j : p) {
			if (i * j > n)
				break;
			lpf[i * j] = j;
			if (j == lpf[i])
				break;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q, k;

	cin >> n >> q;

	sieve(100000000);
	while (q--) {
		cin >> k;

		cout << p[k - 1] << '\n';
	}
}
