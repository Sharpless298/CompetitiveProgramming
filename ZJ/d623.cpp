#include <iomanip>
#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	double a, b, c, d;

	cout << fixed << setprecision(5);

	while (cin >> a >> b >> c >> d) {
		if (a == 0 && b == 0 && c == 0 && d == 0)
			return 0;

		double det = a * d - b * c;
		if (det == 0)
			cout << "cheat!\n";
		else {
			cout << d / det << ' ' << -b / det << '\n';
			cout << -c / det << ' ' << a / det << '\n';
		}
	}
}
