#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<int>> pref(19, vector<int>(200001));
	for (int i = 0; i <= 18; i++)
		for (int j = 1; j <= 200000; j++)
			pref[i][j] = pref[i][j - 1] + ((j & (1 << i)) == 0);

	int T;
	cin >> T;
	while (T--) {
		int l, r;
		cin >> l >> r;

		int ans = 0x3f3f3f3f;
		for (int i = 0; i <= __lg(r); i++)
			ans = min(ans, pref[i][r] - pref[i][l - 1]);

		cout << ans << '\n';
	}
}
