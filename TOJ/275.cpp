#include <iomanip>
#include <iostream>
#include <set>
using namespace std;

int n, t, a, b;
multiset<int> p, q;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed << setprecision(6);

	cin >> n;

	cin >> a >> b;
	cout << a * 1.0 << '\n';
	if (a <= b)
		p.insert(a), q.insert(b);
	else
		p.insert(b), q.insert(a);

	cout << (a * 1.0 + b) / 2 << '\n';

	for (int i = 2; i < n; i++) {
		cin >> t;

		if (p.size() < q.size()) {
			if (t <= *q.begin())
				p.insert(t);
			else {
				p.insert(*q.begin());
				q.erase(q.begin());
				q.insert(t);
			}
		} else {
			if (t >= *p.rbegin())
				q.insert(t);
			else {
				auto iter = --p.end();
				p.insert(t);
				q.insert(*iter);
				p.erase(iter);
			}
		}
		if (p.size() == q.size())
			cout << (*p.rbegin() * 1.0 + *q.begin()) / 2 << '\n';
		else
			cout << *q.begin() * 1.0 << '\n';
	}
}
