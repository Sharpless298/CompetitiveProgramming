#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<int, int>> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].first;
			a[i].second = i;
		}

		sort(a.begin(), a.end());
		bool ok = true;
		vector<int> b(n);
		for (int i = 0, j = n - 1, cnt = 0; i <= j;) {
			if (a[i].first - cnt == 0) {
				b[i] = -(j - i + 1);
				i++;
			} else if (a[j].first - cnt == j - i + 1) {
				b[j] = j - i + 1;
				j--;
				cnt++;
			} else {
				ok = false;
				break;
			}
		}

		if (!ok) {
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
		vector<int> ans(n);
		for (int i = 0; i < n; i++) {
			ans[a[i].second] = b[i];
		}
		for (int i = 0; i < n; i++) {
			cout << ans[i] << " \n"[i + 1 == n];
		}
	}
}
