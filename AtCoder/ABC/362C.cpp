#include <iostream>
using namespace std;

typedef long long int lli;

lli l[200005], r[200005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	lli suml = 0, sumr = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		suml += l[i], sumr += r[i];
	}

	if (suml <= 0 && sumr >= 0) {
		cout << "Yes\n";

		suml = -suml;
		for (int i = 0; i < n; i++) {
			lli t = min(suml, r[i] - l[i]);
			suml -= t;
			l[i] += t;
		}

		for (int i = 0; i < n; i++)
			cout << l[i] << ' ';
		cout << '\n';
	} else
		cout << "No\n";
}
