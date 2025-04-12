#include <iostream>
#include <set>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	set<int> s;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		s.insert(x);
	}

	cout << s.size() << '\n';
}
