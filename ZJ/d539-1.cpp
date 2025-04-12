#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<int> lg(n + 1);
	lg[1] = 0;
	for (int i = 2; i <= n; i++)
		lg[i] = lg[i / 2] + 1;

	int lgN = __lg(n) + 1;
	vector<vector<int>> st(n, vector<int>(lgN));
	for (int i = 0; i < n; i++)
		st[i][0] = a[i];

	for (int j = 1; j < lgN; j++)
		for (int i = 0; i + (1 << j) - 1 < n; i++)
			st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;

		if (l > r)
			swap(l, r);
		l--, r--;
		int k = lg[r - l + 1];
		cout << max(st[l][k], st[r - (1 << k) + 1][k]) << '\n';
	}
}
