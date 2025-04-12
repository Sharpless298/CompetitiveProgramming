#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	long long int T = 0;
	for (int i = 0; i < n; i++) {
		if (T % 3 == 1)
			a[i]--, T++;
		if (a[i] > 0 && T % 3 == 2)
			a[i] -= 3, T++;
		if (a[i] > 0)
			T += a[i] / 5 * 3;

		if (a[i] <= 0)
			continue;
		if (a[i] % 5 >= 4)
			T += 3;
		else
			T += a[i] % 5;
	}

	cout << T << '\n';
}
