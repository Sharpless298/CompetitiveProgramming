#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int &i : a)
		cin >> i;

	vector<int> b(n);
	{
		vector<int> LIS;
		for (int i = 0; i < n; i++) {
			auto it = lower_bound(LIS.begin(), LIS.end(), a[i]);

			if (it == LIS.end())
				LIS.push_back(a[i]);
			else
				*it = a[i];

			b[i] = (int)LIS.size();
		}
	}
	reverse(a.begin(), a.end());
	vector<int> c(n);
	{
		vector<int> LIS;
		for (int i = 0; i < n; i++) {
			auto it = lower_bound(LIS.begin(), LIS.end(), a[i]);

			if (it == LIS.end())
				LIS.push_back(a[i]);
			else
				*it = a[i];

			c[i] = (int)LIS.size();
		}
	}

	int ans = n;
	for (int i = 0; i < n; i++)
		ans = min(ans, n - b[i] - c[n - i - 1] + 1);
	cout << ans << '\n';
}
