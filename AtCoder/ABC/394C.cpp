#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	int n = (int)s.size();
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == 'A' && s[i + 1] == 'W') {
			s[i] = 'C', s[i + 1] = 'A';
		}
	}
	reverse(s.begin(), s.end());
	cout << s << '\n';
}
