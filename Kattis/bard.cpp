#include <algorithm>
#include <iostream>
using namespace std;

typedef long long int lli;

lli t;
lli ary[128];
lli villager[128];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, E, K, k = 0;

	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		cin >> K;
		for (int j = 0; j < K; j++)
			cin >> ary[j];

		t = 0;

		sort(ary, ary + K);
		if (ary[0] == 1) {
			t = (1 << k);
			for (int j = 0; j < K; j++)
				villager[ary[j]] |= t;
			k++;
		} else {
			for (int j = 0; j < K; j++)
				t |= villager[ary[j]];
			for (int j = 0; j < K; j++)
				villager[ary[j]] |= t;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (villager[i] == villager[1])
			cout << i << '\n';
	}
}
