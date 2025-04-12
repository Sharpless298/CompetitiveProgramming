#include "lib1338.h"

long long g[20][1000000], mn[20][1000000];

long long int gcd(long long int a, long long int b) {
	return b ? gcd(b, a % b) : a;
}

long long int min(long long int &a, long long int &b) {
	return a < b ? a : b;
}

void init(int n, long long int c[]) {
	for (int i = 0; i < n; ++i)
		g[0][i] = mn[0][i] = c[i];
	for (int i = 1; i < 20; i++) {
		for (int j = 0; j + (1 << i) - 1 < n; j++) {
			g[i][j] = gcd(g[i - 1][j], g[i - 1][j + (1 << (i - 1))]);
			mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
		}
	}
}

int query(int l, int r) {
	int k = 31 - __builtin_clz(r - l);
	long long int tmp = gcd(g[k][l], g[k][r - (1 << k)]);
	long long int tmp2 = min(mn[k][l], mn[k][r - (1 << k)]);

	return tmp == tmp2;
}
