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
		cin >> n;
		string s;
		cin >> s;
		int ans = 0;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			if (s[i] == '_') {
				if (v.empty())
					s[i] = '(';
				else
					s[i] = ')';
			}

			if (s[i] == '(')
				v.push_back(i);
			else {
				ans += i - v.back();
				v.pop_back();
			}
		}

		cout << ans << '\n';
	}
}
