#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int k, n = 0;
	vector<int> a;
	while (cin >> k)
		a.push_back(k), n++;

	vector<int> b(n);
	vector<int> LIS;
	for (int i = 0; i < n; i++) {
		auto iter = lower_bound(LIS.begin(), LIS.end(), a[i]);
		if (iter == LIS.end())
			b[i] = (int)LIS.size(), LIS.push_back(a[i]);
		else
			b[i] = (int)(iter - LIS.begin()), LIS[b[i]] = a[i];
	}

	vector<int> ans;
	for (int i = n - 1, j = (int)LIS.size() - 1; i >= 0; i--)
		if (b[i] == j)
			ans.push_back(a[i]), j--;
	reverse(ans.begin(), ans.end());

	cout << LIS.size() << '\n';
	cout << "-\n";
	for (int i : ans)
		cout << i << '\n';
}
