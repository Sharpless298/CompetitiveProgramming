#include <cstring>
#include <iostream>
using namespace std;

typedef long long int lli;

lli A[128][128], B[128][128], ans[128][128];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c, d;

	while (cin >> a >> b >> c >> d) {
		memset(ans, 0, sizeof(ans));

		if (b != c) {
			cout << "Error\n";
			continue;
		}

		for (int i = 0; i < a; i++)
			for (int j = 0; j < b; j++)
				cin >> A[i][j];
		for (int i = 0; i < c; i++)
			for (int j = 0; j < d; j++)
				cin >> B[i][j];

		for (int i = 0; i < a; i++)
			for (int j = 0; j < d; j++)
				for (int k = 0; k < b; k++)
					ans[i][j] += A[i][k] * B[k][j];

		for (int i = 0; i < a; i++) {
			for (int j = 0; j < d; j++)
				cout << ans[i][j] << ' ';
			cout << '\n';
		}
	}
}
