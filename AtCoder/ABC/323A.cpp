#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;

	cin >> s;

	for (int i = 1; i < 16; i += 2) {
		if (s[i] == '1') {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
}
