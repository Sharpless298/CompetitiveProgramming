#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		long long sum = 0, mn = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i];
			mn = min(mn, sum);
		}

		cout << sum - 2 * mn << '\n';
	}
}
