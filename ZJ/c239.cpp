#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int INF = 2147483647;

int n, m, MIN, MAX, num, den;
int dis[32][32], dp_min[32][1 << 16], dp_max[32][1 << 16];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> n) {
		MIN = INF, MAX = 0;

		for (int i = 0, x; i < n; i++)
			for (int j = i + 1; j < n; j++) cin >> x, dis[i][j] = dis[j][i] = x;
		m = (1 << n);

		memset(dp_min, 0x3f3f3f3f, sizeof(dp_min));
		memset(dp_max, -0x3f3f3f3f, sizeof(dp_max));
		dp_min[0][1] = 0;
		dp_max[0][1] = 0;
		for (int i = 0; i < (1 << n); i++) {
			for (int j = 0; j < n; j++) {
				if (!(i & (1 << j))) continue;

				for (int k = 0; k < n; k++) {
					if (i & (1 << k)) {
						dp_min[j][i] = min(dp_min[k][i ^ (1 << j)] + dis[j][k], dp_min[j][i]);
						dp_max[j][i] = max(dp_max[k][i ^ (1 << j)] + dis[j][k], dp_max[j][i]);
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			MIN = min(dp_min[i][m - 1] + dis[i][0], MIN);
			MAX = max(dp_max[i][m - 1] + dis[i][0], MAX);
		}

		num = MAX / __gcd(MIN, MAX), den = MIN / __gcd(MIN, MAX);
		if (den != 1)
			cout << MAX / __gcd(MIN, MAX) << '/' << MIN / __gcd(MIN, MAX) << '\n';
		else
			cout << num << '\n';
	}
}
