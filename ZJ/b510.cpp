#include <iostream>
using namespace std;

bool c[32], Qp[32], Qq[32];
int ans, Q, C, Cp[32], Cq[32], M, N;

void DFS(int depth) {
	if (depth == M + N) {
		ans++;
		return;
	}

	for (int i = 0; i < (M + N); i++) {
		if (Q && !c[i] && !Qp[depth + i] && !Qq[depth - i + 10] && !Cp[depth + i] && !Cq[depth - i + 10]) {
			Q--;
			c[i] = Qp[depth + i] = Qq[depth - i + 10] = true;
			DFS(depth + 1);
			Q++;
			c[i] = Qp[depth + i] = Qq[depth - i + 10] = false;
		}
		if (C && !c[i] && !Qp[depth + i] && !Qq[depth - i + 10]) {
			C--;
			c[i] = true;
			Cp[depth + i]++, Cq[depth - i + 10]++;
			DFS(depth + 1);
			C++;
			c[i] = false;
			Cp[depth + i]--, Cq[depth - i + 10]--;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> N;

	Q = M, C = N;
	DFS(0);

	cout << ans << '\n';
}
