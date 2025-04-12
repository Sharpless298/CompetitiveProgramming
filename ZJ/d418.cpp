#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int T, n;
vector<int> v;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		v.clear();

		cin >> n;

		for (int i = 9; i >= 2; i--) {
			while (n % i == 0) {
				v.push_back(i);
				n /= i;
			}
		}

		if (n > 1)
			cout << -1 << '\n';
		else if (v.empty())
			cout << n << '\n';
		else {
			reverse(v.begin(), v.end());
			for (int i : v)
				cout << i;
			cout << '\n';
		}
	}
}
