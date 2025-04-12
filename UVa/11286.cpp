#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 1e4 + 5;

struct comb {
	int ary[5];
} stu[MAXN];

int q[MAXN];

bool cmp1(const comb &a, const comb &b) {
	for (int i = 0; i < 5; i++)
		if (a.ary[i] != b.ary[i])
			return a.ary[i] < b.ary[i];
	return false;
}

bool cmp2(int k) {
	for (int i = 0; i < 5; i++)
		if (stu[k].ary[i] != stu[k - 1].ary[i])
			return false;
	return true;
}

int count(int n) {
	int max = q[n - 1], res = max;
	for (int i = n - 2; i >= 0; i--) {
		if (q[i] != max)
			break;
		res += max;
	}
	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, t, ans, k;

	while (cin >> n && n) {
		k = 0;
		t = 1;
		ans = 1;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < 5; j++)
				cin >> stu[i].ary[j];

		for (int i = 0; i < n; i++)
			sort(stu[i].ary, stu[i].ary + 5);
		sort(stu, stu + n, cmp1);
		for (int i = 1; i < n; i++) {
			if (cmp2(i))
				t++;
			else {
				q[k] = t;
				t = 1;
				k++;
			}
			if (i == n - 1) {
				q[k] = t;
				t = 1;
				k++;
			}
		}
		sort(q, q + k);

		cout << count(k) << '\n';
	}
}
