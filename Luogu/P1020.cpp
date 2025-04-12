#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> a;
	int x;
	while (cin >> x)
		a.push_back(x);

	int n = (int)a.size();
	{
		vector<int> dp;
		for (int i = 0; i < n; i++) {
			int l = 0, r = (int)dp.size();
			while (l < r) {
				int m = (l + r) >> 1;

				if (dp[m] >= a[i])
					l = m + 1;
				else
					r = m;
			}

			if (l == (int)dp.size())
				dp.push_back(a[i]);
			else
				dp[l] = a[i];
		}
		cout << dp.size() << '\n';
	}
	{
		vector<int> dp;
		for (int i = 0; i < n; i++) {
			int l = 0, r = (int)dp.size();
			while (l < r) {
				int m = (l + r) >> 1;

				if (dp[m] < a[i])
					l = m + 1;
				else
					r = m;
			}

			if (l == (int)dp.size())
				dp.push_back(a[i]);
			else
				dp[l] = a[i];
		}
		cout << dp.size() << '\n';
	}
}
