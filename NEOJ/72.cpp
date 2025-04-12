#include <iomanip>
#include <iostream>
using namespace std;

double const EPS = 1e-7;

int T, n;
double a[16], b[16], c[16];

double f(double x, int i) {
	return a[i] * (x - b[i]) * (x - b[i]) + c[i];
}

double ternary_search(double l, double r) {
	double ml, mr, tmp_l = 0, tmp_r = 0;

	while (r - l > EPS) {
		tmp_l = tmp_r = 0;
		ml = (l + l + r) / 3, mr = (l + r + r) / 3;

		for (int i = 0; i < n; i++) {
			tmp_l = max(tmp_l, f(ml, i));
			tmp_r = max(tmp_r, f(mr, i));
		}

		if (tmp_l > tmp_r)
			l = ml;
		else
			r = mr;
	}

	return tmp_l;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed << setprecision(8);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i] >> b[i] >> c[i];

		cout << ternary_search(0, 300) << '\n';
	}
}
