#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, q;
		string a, b;
		cin >> n >> q;
		cin >> a >> b;

		vector<vector<int>> pref1(n, vector<int>(26)), pref2(n, vector<int>(26));
		pref1[0][a[0] - 'a'] = 1;
		pref2[0][b[0] - 'a'] = 1;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < 26; j++) {
				pref1[i][j] = pref1[i - 1][j];
				pref2[i][j] = pref2[i - 1][j];
			}

			pref1[i][a[i] - 'a']++;
			pref2[i][b[i] - 'a']++;
		}

		while (q--) {
			int l, r;
			cin >> l >> r;
			l--, r--;

			int cnt = 0;
			for (int i = 0; i < 26; i++) {
				int tmp1 = pref1[r][i];
				int tmp2 = pref2[r][i];
				if (l - 1 >= 0)
					tmp1 -= pref1[l - 1][i], tmp2 -= pref2[l - 1][i];
				cnt += abs(tmp1 - tmp2);
			}

			cout << cnt / 2 << '\n';
		}
	}
}
