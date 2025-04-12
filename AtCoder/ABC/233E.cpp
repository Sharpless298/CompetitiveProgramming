#include <algorithm>
#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	string s;
	cin >> s;

	int sum = 0;
	for (char &c : s)
		sum += c - '0';

	int c = 0;
	string ans;
	for (int i = (int)s.size() - 1;; i--) {
		c += sum;
		ans += (char)('0' + c % 10);
		c /= 10;
		if (i >= 0)
			sum -= s[i] - '0';
		if (i <= 0 && c == 0)
			break;
	}

	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
}
