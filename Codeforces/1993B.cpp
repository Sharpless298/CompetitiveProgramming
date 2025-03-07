#include <algorithm>
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

		long long int tmp = 0;
		vector<long long int> v;
		for (int i = 0; i < n; i++) {
			long long int x;
			cin >> x;
			if (x & 1)
				tmp = max(tmp, x);
			else
				v.push_back(x);
		}

		if (v.size() == 0 || (int)v.size() == n) {
			cout << 0 << '\n';
			continue;
		}

		sort(v.begin(), v.end());
		int ans = 0;
		for (int i = 0; i < (int)v.size(); i++) {
			if (v[i] < tmp)
				ans++, tmp += v[i];
			else
				tmp += 2 * v[i], ans += 2;
		}

		cout << min(ans, (int)v.size() + 1) << '\n';
	}
}
