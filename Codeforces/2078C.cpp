#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> b(2 * n);
		for (int &i : b)
			cin >> i;
		sort(b.begin(), b.end(), greater<int>());

		long long sum = 0;
		vector<long long> ans;

		ans.push_back(b[0]);
		sum += b[0];
		for (int i = 0; i < n - 1; i++) {
			ans.push_back(b[i + n]);
			sum -= b[i + n];
			ans.push_back(b[i + 1]);
			sum += b[i + 1];
		}
		ans.push_back(sum + b[2 * n - 1]);
		ans.push_back(b[2 * n - 1]);

		for (long long i : ans)
			cout << i << ' ';
		cout << '\n';
	}
}
