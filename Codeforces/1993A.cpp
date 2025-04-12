#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		string s;
		cin >> n >> s;

		int ans = 0;
		vector<int> cnt(4);
		for (int i = 0; i < (int)s.size(); i++) {
			if (s[i] == '?')
				continue;
			cnt[s[i] - 'A']++;
			if (cnt[s[i] - 'A'] <= n)
				ans++;
		}

		cout << ans << '\n';
	}
}
