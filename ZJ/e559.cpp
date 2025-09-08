#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	cin.ignore();
	while (T--) {
		string s;
		getline(cin, s);

		stringstream ss(s);
		int sum = 0;
		vector<int> a;
		int x;
		while (ss >> x) {
			a.push_back(x);
			sum += x;
		}
		if (sum & 1) {
			cout << "NO\n";
			continue;
		}

		int n = (int)a.size();
		vector<bool> dp(sum / 2 + 1);
		dp[0] = true;
		for (int i = 0; i < n; i++) {
			for (int j = sum / 2 - a[i]; j >= 0; j--) {
				dp[j + a[i]] = dp[j + a[i]] | dp[j];
			}
		}

		cout << (dp.back() ? "YES\n" : "NO\n");
	}
}
