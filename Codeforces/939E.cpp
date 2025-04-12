#include <iomanip>
#include <iostream>
using namespace std;

int Q, t;
double sum;
double ary[500005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed << setprecision(6);

	cin >> Q;
	for (int i = 0, j = -1; Q--;) {
		cin >> t;

		if (t == 1)
			cin >> ary[++j];
		else {
			while (i < j && ary[i] < (sum + ary[j]) / (i + 1))
				sum += ary[i++];

			cout << ary[j] - (sum + ary[j]) / (i + 1) << '\n';
		}
	}
}
