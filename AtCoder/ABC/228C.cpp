#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int a[100005], b[100005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;

	cin >> n >> k;
	k--;
	for (int i = 0; i < n; i++) {
		for (int j = 0, x; j < 3; j++)
			cin >> x, a[i] += x;
	}

	memcpy(b, a, sizeof(int) * n);
	sort(b, b + n, greater<int>());

	for (int i = 0; i < n; i++)
		cout << (a[i] + 300 >= b[k] ? "Yes" : "No") << '\n';
}
