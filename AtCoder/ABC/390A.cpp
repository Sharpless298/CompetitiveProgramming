#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> a(5);
	for (int &i : a)
		cin >> i;
	for (int i = 0; i < 4; i++) {
		vector<int> b = a;
		swap(b[i], b[i + 1]);
		bool ok = true;
		for (int j = 0; j < 4; j++)
			if (b[j] > b[j + 1])
				ok = false;

		if (ok) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
}
