#include "lib1995.h"
using namespace std;

int st[2500000];
int l[1000000], r[1000000];
bitset<1000000> f;

signed main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &l[i], &r[i]);
		l[i]--, r[i]--;
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &st[i]);

	for (int i = 0; i < m; i++)
		if (l[i] == r[i])
			l[i] = st[l[i]], f[i] = true;

	for (int i = 1; (1 << i) <= n; i++) {
		for (int j = 0; j + (1 << i) - 1 < n; j++)
			st[j] = max(st[j], st[j + (1 << (i - 1))]);
		for (int j = 0; j < m; j++)
			if (31 - __builtin_clz(r[j] - l[j] + 1) == i && !f[j])
				l[j] = max(st[l[j]], st[r[j] - (1 << i) + 1]), f[j] = true;
	}

	for (int i = 0; i < m; i++)
		printf("%d\n", l[i]);
}
