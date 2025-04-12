#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];

	int m = 0;
	for (int i = 0; i < n; i++)
		m = max(m, (int)s[i].size());

	for (int i = 0; i < n; i++)
		while ((int)s[i].size() < m)
			s[i] += '*';

	vector<string> ans(m);
	for (int i = 0; i < m; i++) {
		for (int j = n - 1; j >= 0; j--) {
			ans[i] += s[j][i];
		}
	}

	for (int i = 0; i < m; i++) {
		while (ans[i].back() == '*')
			ans[i].pop_back();
		cout << ans[i] << '\n';
	}
}
