#include <iostream>
#include <vector>
using namespace std;

#define lowbit(x) x & -x

int n;
vector<vector<long long>> BIT;

void update(int x, int y, int k) {
	for (; y <= n; y += lowbit(y)) {
		int tmp = x;
		for (; tmp <= n; tmp += lowbit(tmp))
			BIT[y][tmp] += k;
	}
}

long long query(int x, int y) {
	long long res = 0;
	for (; y; y -= lowbit(y)) {
		int tmp = x;
		for (; tmp; tmp -= lowbit(tmp))
			res += BIT[y][tmp];
	}

	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	BIT.resize(n + 1, vector<long long>(n + 1));

	int t;
	while (cin >> t) {
		if (t == 1) {
			int x, y, z;
			cin >> x >> y >> z;
			update(x + 1, y + 1, z);
		} else {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			cout << query(x2 + 1, y2 + 1) - query(x2 + 1, y1) - query(x1, y2 + 1) + query(x1, y1) << '\n';
		}
	}
}
