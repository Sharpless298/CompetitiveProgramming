#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<lli> tot(18);
	tot[0] = 0;
	for (lli i = 1, j = 9; i <= 17; i++, j *= 10)
		tot[i] = tot[i - 1] + i * j;

	int q;
	cin >> q;
	while (q--) {
		lli k;
		cin >> k;

		int t = 0;
		while (tot[t + 1] < k)
			t++;

		k -= tot[t] + 1;
		t++;

		lli tmp = 1;
		for (int i = 0; i < t - 1; i++)
			tmp *= 10;
		lli a = k / t, b = k % t;
		string s = to_string(tmp + a);
		cout << s[b] << '\n';
	}
}
