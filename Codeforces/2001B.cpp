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

		if (n % 2 == 0)
			cout << -1 << '\n';
		else {
			vector<int> ans(n);
			int j = 1;
			for (int i = n / 2; i >= 0; i--, j++)
				ans[i] = j;
			for (int i = n / 2 + 1; i < n; i++, j++)
				ans[i] = j;

			for (int &i : ans)
				cout << i << ' ';
			cout << '\n';
		}
	}
}
