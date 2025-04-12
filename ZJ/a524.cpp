#include <algorithm>
#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	string s;

	while (cin >> n) {
		s = "";
		for (int i = n; i >= 1; i--)
			s += '0' + i;

		cout << s << '\n';
		while (prev_permutation(s.begin(), s.end()))
			cout << s << '\n';
	}
}
