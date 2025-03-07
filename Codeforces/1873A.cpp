#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	string s;

	cin >> t;

	while (t--) {
		cin >> s;

		if (s == "abc" || s == "acb" || s == "cba" || s == "bac")
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
