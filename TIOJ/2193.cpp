#include <algorithm>
#include <iostream>
using namespace std;

int b[1030];
struct elem {
	int v, order;
} ary[1005];

int count(int x) {
	int t = 0;
	while (x) {
		if (x & 1)
			t++;
		x >>= 1;
	}
	return t;
}

bool cmp(const elem &p, const elem &q) {
	if (b[p.v] != b[q.v])
		return b[p.v] < b[q.v];
	return p.order < q.order;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 1; i <= 1024; i++)
		b[i] = count(i);

	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ary[i].v;
		ary[i].order = i;
	}

	sort(ary, ary + n, cmp);

	for (int i = 0; i < n; i++) {
		if (i)
			cout << ' ';
		cout << ary[i].v;
	}
	cout << '\n';
}
