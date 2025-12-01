#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		c[a[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		b[i]--;
		b[i] = c[b[i]];
	}

	vector<int> LIS;
	for (int i = 0; i < n; i++) {
		auto it = upper_bound(LIS.begin(), LIS.end(), b[i]);
		if (it == LIS.end()) {
			LIS.push_back(b[i]);
		} else {
			LIS[it - LIS.begin()] = b[i];
		}
	}
	cout << LIS.size() << '\n';
}
