#include <iostream>
#include <vector>
using namespace std;

int Case;
long long ans;
vector<int> a, tmp;

void merge(int l, int r) {
	int m = (l + r) / 2;

	for (int i = l, j = m, k = l; k < r; k++) {
		if (i == m)
			tmp[k] = a[j++];
		else if (j == r)
			tmp[k] = a[i++];
		else if (a[i] <= a[j])
			tmp[k] = a[i++];
		else {
			tmp[k] = a[j++];
			ans += (m - i);
		}
	}

	for (int i = l; i < r; i++)
		a[i] = tmp[i];
}

void merge_sort(int l, int r) {
	if (r - l == 1)
		return;

	int m = (l + r) / 2;
	merge_sort(l, m);
	merge_sort(m, r);
	merge(l, r);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	while (cin >> n && n) {
		a.resize(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		ans = 0;
		tmp.resize(n);
		merge_sort(0, n);
		cout << "Case #" << ++Case << ": " << ans << '\n';
	}
}
