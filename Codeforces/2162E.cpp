#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		set<int> s1, s2;
		for (int i = 0; i < n; i++) {
			s1.insert(i + 1);
			s2.insert(i + 1);
		}
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			s1.erase(a[i]);
		}

		for (int i = 0; i < k; i++) {
			if (!s1.empty()) {
				a.push_back(*s1.begin());
				s2.erase(*s1.begin());
				s1.erase(*s1.begin());
			} else {
				auto it = s2.begin();
				for (int j = 0; j < 2; j++) {
					if (*it == a[n - 1 + i] || *it == a[n - 2 + i]) {
						it++;
					}
				}
				a.push_back(*it);
				s2.erase(*it);
			}
		}
		for (int i = n; i < n + k; i++) {
			cout << a[i] << " \n"[i + 1 == n + k];
		}
	}
}
