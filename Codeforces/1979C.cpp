#include <algorithm>
#include <iostream>
using namespace std;

typedef long long int lli;

int T, n;
lli t, sum, k[55];

lli lcm(lli a, lli b) {
	return a * b / __gcd(a, b);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> k[i];

		t = 1;
		for (int i = 0; i < n; i++)
			t = lcm(t, k[i]);

		sum = 0;
		for (int i = 0; i < n; i++)
			sum += t / k[i];

		if (sum < t) {
			for (int i = 0; i < n; i++)
				cout << t / k[i] << ' ';
			cout << '\n';
		} else
			cout << -1 << '\n';
	}
}
