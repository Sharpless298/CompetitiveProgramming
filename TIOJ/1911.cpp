#include <iostream>
#include <set>
using namespace std;

multiset<int> s;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;

	while (cin >> t && t) {
		if (t > 0) {
			s.insert(t);
		} else {
			if (s.empty())
				continue;

			if (t == -2) {
				auto iter = s.end();
				iter--;
				cout << *iter;
				s.erase(iter);
			} else {
				cout << *s.begin();
				s.erase(s.begin());
			}
			cout << ' ';
		}
	}
	cout << '\n';
}
