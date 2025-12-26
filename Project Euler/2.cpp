#include <iostream>
#include <vector>
using namespace std;

signed main() {
	int ans = 2;
	vector<int> f(10000);
	f[1] = 1, f[2] = 2;
	for (int i = 3;; i++) {
		f[i] = f[i - 1] + f[i - 2];
		if (f[i] > 4000000) {
			break;
		}
		if (f[i] % 2 == 0) {
			ans += f[i];
		}
	}

	cout << ans << '\n';
}
