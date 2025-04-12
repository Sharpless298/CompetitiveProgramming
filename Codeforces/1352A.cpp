#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, n, k;

	cin >> T;
	while (T--) {
		ans.clear();

		cin >> n;

		k = 10;
		while (n) {
			if (n % k != 0)
				ans.push_back(n % k);
			n -= n % k;
			k *= 10;
		}

		cout << ans.size() << '\n';
		for (int i : ans)
			cout << i << ' ';
		cout << '\n';
	}
}
