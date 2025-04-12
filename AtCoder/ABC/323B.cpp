#include <algorithm>
#include <iostream>
using namespace std;

struct t {
	int p, wins, order;
};

char c;
int n;
t ary[128];

bool cmp(t &a, t &b) {
	if (a.wins == b.wins)
		return a.order < b.order;
	return a.wins > b.wins;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i <= 127; i++)
		ary[i].p = ary[i].order = i;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			if (c == 'o')
				ary[i].wins++;
		}
	}

	sort(ary, ary + n, cmp);

	for (int i = 0; i < n; i++) {
		if (i)
			cout << ' ';
		cout << ary[i].p + 1;
	}
}
