#include <algorithm>
#include <iostream>
using namespace std;

struct elem {
	string name;
	int order;
};

elem str[200];

bool cmp(const elem &a, const elem &b) {
	string p = a.name.substr(0, 2), q = b.name.substr(0, 2);
	if (p != q)
		return p < q;
	return a.order < b.order;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	while (cin >> n && n) {
		for (int i = 0; i < n; i++) {
			cin >> str[i].name;
			str[i].order = i;
		}

		sort(str, str + n, cmp);

		for (int i = 0; i < n; i++)
			cout << str[i].name << '\n';
		cout << '\n';
	}
}
