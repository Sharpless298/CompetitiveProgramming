#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		long long x;
		cin >> x;
		int c = 0;
		vector<int> a;
		while ((1LL << (c + 1)) <= x) {
			a.push_back(c);
			c++;
		}
		x -= (1LL << c);

		vector<int> b;
		for (int i = 0; i < c; i++) {
			if (x & (1LL << (c - i - 1))) {
				x -= (1LL << (c - i - 1));
				b.push_back(i);
			}
		}

		reverse(b.begin(), b.end());
		cout << a.size() + b.size() << '\n';
		for (int i : b) {
			cout << i << ' ';
		}
		for (int i = 0; i < (int)a.size(); i++) {
			cout << a[i] << " \n"[i + 1 == (int)a.size()];
		}
	}
}
