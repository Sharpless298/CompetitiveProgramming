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
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		sort(a.begin(), a.end());
		long long sum = accumulate(a.begin(), a.end(), 0LL);
		long long A = 0, B = 0;
		vector<int> b;
		for (int i = 0; i < n;) {
			if (a[i] & 1) {
				int j = i + 1;
				while (j < n && a[j] == a[i]) {
					j++;
				}
				b.push_back(j - i);
				sum -= j - i;
				i = j;
			} else {
				i++;
			}
		}

		sort(b.begin(), b.end(), greater<int>());
		for (int i = 0; i < (int)b.size(); i++) {
			if (i & 1) {
				B += b[i];
			} else {
				A += b[i];
			}
		}

		cout << A + sum / 2 << ' ' << B + sum / 2 << '\n';
	}
}
