#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i], a[i]--;

		vector<bool> f(n);
		vector<int> b(n, -1);
		for (int i = 0; i < n; i++) {
			if (!f[a[i]]) {
				f[a[i]] = true;
				b[i] = a[i];
			}
		}
		int ptr = 0;
		for (int i = 0; i < n; i++) {
			if (b[i] == -1) {
				while (f[ptr])
					ptr++;

				b[i] = ptr;
				f[ptr] = true;
			}
		}

		for (int i : b)
			cout << i + 1 << ' ';
		cout << '\n';
	}
}
