#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a > b)
			swap(a, b);

		if ((c >= a && c <= b) && !(d >= a && d <= b)) {
			cout << "YES\n";
			continue;
		}
		swap(c, d);
		if ((c >= a && c <= b) && !((d >= a) && d <= b)) {
			cout << "YES\n";
			continue;
		}

		cout << "NO\n";
	}
}
