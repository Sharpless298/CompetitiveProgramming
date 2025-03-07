#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		string a;
		cin >> a;
		reverse(a.begin(), a.end());
		for (char &c : a) {
			if (c == 'p')
				cout << 'q';
			else if (c == 'q')
				cout << 'p';
			else
				cout << c;
		}
		cout << '\n';
	}
}
