#include <bits/stdc++.h>
using namespace std;

bool query(string t) {
	cout << "? " << t << endl;
	int x;
	cin >> x;
	return x;
}

signed main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		string ans;
		while ((int)ans.size() < n) {
			if (query(ans + '0'))
				ans = ans + '0';
			else if (query(ans + '1'))
				ans = ans + '1';
			else
				break;
		}
		while ((int)ans.size() < n) {
			if (query('0' + ans))
				ans = '0' + ans;
			else
				ans = '1' + ans;
		}
		cout << "! " << ans << endl;
	}
}
