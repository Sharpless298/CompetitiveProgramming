#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &b) {
	int n = (int)b.size();
	int mex = 0;
	vector<int> suf(n);
	vector<bool> used(n + 1, false);
	for (int i = n - 1; i >= 1; i--) {
		if (b[i] <= n)
			used[b[i]] = true;
		while (used[mex])
			mex++;
		suf[i] = mex;
	}
	int mn = b[0];
	for (int i = 0; i < n - 1; i++) {
		mn = min(mn, b[i]);
		if (mn < suf[i + 1])
			return false;
	}
	return true;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int &i : a)
			cin >> i;

		int cnt0 = 0;
		vector<int> b;
		for (int i = 0, f = 0; i < n; i++) {
			if (a[i] == 0) {
				cnt0++;
				if (!f) {
					f = 1;
					b.push_back(a[i]);
				}
			} else {
				b.push_back(a[i]);
			}
		}

		if (cnt0 > 0 && check(b)) {
			cout << n - cnt0 + 1 << '\n';
		} else {
			cout << n - cnt0 << '\n';
		}
	}
}
