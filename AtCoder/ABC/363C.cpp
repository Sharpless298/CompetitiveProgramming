#include <algorithm>
#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	bool f;
	int n, k, ans = 0;
	string s;

	cin >> n >> k >> s;
	sort(s.begin(), s.end());
	do {
		f = true;
		for (int i = 0; i < n - k + 1; i++) {
			bool check = true;
			int l = i, r = i + k - 1;

			while (l < r)
				if (s[l++] != s[r--])
					check = false;
			if (check)
				f = false;
		}
		ans += f;
	} while (next_permutation(s.begin(), s.end()));

	cout << ans << '\n';
}
