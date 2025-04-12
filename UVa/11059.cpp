#include <iostream>
using namespace std;

int ary[100], id;
long long int sum[100][100], ans;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	while (cin >> n) {
		id++;
		ans = 0;

		for (int i = 1; i <= n; i++)
			cin >> sum[i][i];

		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if (i != j)
					sum[i][j] = sum[i][j - 1] * sum[j][j];
				ans = max(sum[i][j], ans);
			}
		}
		cout << "Case #" << id << ": The maximum product is " << ans << ".\n\n";
	}
}
