#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, n;
	vector<int> v1, v2;

	cin >> T;
	while (T--) {
		v1.clear(), v2.clear();

		cin >> n;

		if (n <= 3) {
			cout << -1 << '\n';
			continue;
		}

		for (int i = 0; i < n - 4; i++) {
			if (i & 1)
				v2.push_back(i + 5);
			else
				v1.push_back(i + 5);
		}
		reverse(v1.begin(), v1.end());

		for (int i : v1)
			cout << i << ' ';
		cout << "3 1 4 2 ";
		for (int i : v2)
			cout << i << ' ';
		cout << '\n';
	}
}
