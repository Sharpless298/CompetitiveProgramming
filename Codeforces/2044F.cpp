#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q;
	cin >> n >> m >> q;
	vector<long long> a(n), b(m);

	for (long long &i : a)
		cin >> i;
	for (long long &i : b)
		cin >> i;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	long long suma = accumulate(a.begin(), a.end(), 0LL);
	long long sumb = accumulate(b.begin(), b.end(), 0LL);

	while (q--) {
		long long x;
		cin >> x;

		long long absx = abs(x);
		vector<long long> div;
		for (long long i = 1; i * i <= absx; i++) {
			if (x % i == 0) {
				div.push_back(i);
				div.push_back(-i);
				if (i * i != absx) {
					div.push_back(absx / i);
					div.push_back(-absx / i);
				}
			}
		}

		bool f = false;
		for (long long d : div) {
			if (binary_search(a.begin(), a.end(), suma - d) && binary_search(b.begin(), b.end(), sumb - x / d)) {
				f = true;
				break;
			}
		}
		cout << (f ? "YES\n" : "NO\n");
	}
}
