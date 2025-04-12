#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int N = 1 << 20;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<long long int> a(N, -1);
	set<int> s;
	for (int i = 0; i < N; i++)
		s.insert(i);

	int q;
	cin >> q;
	while (q--) {
		int t;
		long long int x;
		cin >> t >> x;

		if (t == 1) {
			int h = x % N;
			auto iter = s.lower_bound(h);

			int k;
			if (iter != s.end())
				k = *iter;
			else
				k = *s.begin();

			a[k] = x;
			s.erase(k);
		} else
			cout << a[x % N] << '\n';
	}
}
