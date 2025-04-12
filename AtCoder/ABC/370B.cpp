#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i + 1; j++)
			cin >> a[i][j], a[i][j]--;

	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (cur >= i)
			cur = a[cur][i];
		else
			cur = a[i][cur];
	}

	cout << cur + 1 << '\n';
}
