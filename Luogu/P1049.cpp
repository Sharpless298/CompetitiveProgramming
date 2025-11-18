#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int V, n;
	cin >> V >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	bitset<20001> bs;
	bs[0] = 1;
	for (int i = 0; i < n; i++) {
		bs |= (bs << v[i]);
	}
	for (int i = V; i >= 0; i--) {
		if (bs[i]) {
			cout << V - i << '\n';
			break;
		}
	}
}
