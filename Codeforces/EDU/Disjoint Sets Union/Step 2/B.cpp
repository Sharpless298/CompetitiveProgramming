#include <iostream>
#include <numeric>
using namespace std;

int n;
int parent[300005], ans[300005];

int Find(int x) {
	return x == parent[x] ? x : parent[x] = Find(parent[x]);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++)
		parent[i] = i;

	for (int i = 0, x; i < n; i++) {
		cin >> x, x--;

		ans[i] = Find(x);
		parent[ans[i]] = Find((ans[i] + 1) % n);
	}

	for (int i = 0; i < n; i++) {
		if (i)
			cout << ' ';
		cout << ans[i] + 1;
	}
	cout << '\n';
}
