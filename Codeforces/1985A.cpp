#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	string s, t;

	cin >> T;
	while (T--) {
		cin >> s >> t;

		swap(s[0], t[0]);
		cout << s << ' ' << t << '\n';
	}
}
