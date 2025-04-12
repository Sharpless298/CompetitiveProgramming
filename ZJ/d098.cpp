#include <iostream>
#include <sstream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	bool f;
	int ans;
	string s, t;
	stringstream ss;

	while (getline(cin, s)) {
		ss.clear();
		ans = 0;
		ss.str(s);

		while (ss >> t) {
			f = true;
			for (int i = 0; i < (int)t.size(); i++)
				if (t[i] < '0' || t[i] > '9') {
					f = false;
					break;
				}
			if (f)
				ans += stoi(t);
		}

		cout << ans << '\n';
	}
}
