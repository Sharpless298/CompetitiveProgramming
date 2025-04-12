#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int T, ans, cur, n;
string s;
vector<int> lens;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cur = ans = 0;
		lens.clear();

		cin >> s;

		n = (int)s.size();
		for (int i = 0; i < n; i++) {
			if (s[i] == 'A')
				cur++;
			else {
				lens.push_back(cur);
				cur = 0;
			}
		}
		if (s[n - 1] == 'B')
			lens.push_back(0);
		else
			lens.push_back(cur);

		sort(lens.begin(), lens.end());
		for (int i = 1; i < (int)lens.size(); i++)
			ans += lens[i];

		cout << ans << '\n';
	}
}
