#include <iostream>
#include <vector>
using namespace std;

vector<int> pref(200001);

int f(int x) {
	int res = 0;

	while (x)
		x /= 3, res++;

	return res;
}

void solve() {
	int l, r;
	cin >> l >> r;

	cout << pref[r] - pref[l - 1] + f(l) << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	for (int i = 1; i <= 200000; i++) {
		int tmp = f(i);
		pref[i] = pref[i - 1] + tmp;
	}

	int T;
	cin >> T;
	while (T--)
		solve();
}
