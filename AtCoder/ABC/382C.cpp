#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<int> b(m);
	for (int i = 0; i < m; i++)
		cin >> b[i];

	vector<int> c = b;
	sort(c.begin(), c.end(), greater<int>());

	vector<int> idx(200001);
	for (int i = 0, j = 0; i < m; i++) {
		while (j < n && c[i] < a[j])
			j++;
		idx[c[i]] = (j == n ? -1 : j + 1);
	}

	for (int i = 0; i < m; i++)
		cout << idx[b[i]] << '\n';
}
