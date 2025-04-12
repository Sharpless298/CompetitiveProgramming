#include <iostream>
using namespace std;

int n;
string s;

bool check(int l, int r, int err) {
	for (; l < r; l++, r--) {
		if (s[l] != s[r]) {
			if (err == 1)
				return false;
			return check(l + 1, r, err + 1) || check(l, r - 1, err + 1);
		}
	}
	return true;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	while (n--) {
		cin >> s;

		if (check(0, s.size() - 1, 0))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
