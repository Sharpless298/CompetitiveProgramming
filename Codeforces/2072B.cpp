#include <bits/stdc++.h>
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
		long long a = 0, b = 0;
		for (char c : s) {
			if (c == '_')
				a++;
			if (c == '-')
				b++;
		}

		cout << (b / 2) * a * ((b / 2) + (b & 1)) << '\n';
	}
}
