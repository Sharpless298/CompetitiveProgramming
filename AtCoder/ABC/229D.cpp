#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	string s;
	cin >> s >> k;

	int n = (int)s.size();
	vector<int> pref(n + 1);
	for (int i = 0; i < n; i++)
		pref[i + 1] = pref[i] + (s[i] == '.');

	int ans = 0;
	for (int l = 0, r = 0; l < n; l++) {
		while (r < n && pref[r + 1] - pref[l] <= k)
			r++;
		ans = max(ans, r - l);
	}

	cout << ans << '\n';
}
