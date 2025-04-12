#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;

	int now = 0;
	string s;
	for (int i = 0; i < (1 << n); i++) {
		now = now ^ (i & -i);

		int k = now;
		s.clear();
		while (k) {
			if (k & 1)
				s += '1';
			else
				s += '0';
			k >>= 1;
		}
		reverse(s.begin(), s.end());
		cout << setw(n) << setfill('0') << s << '\n';
	}
}
