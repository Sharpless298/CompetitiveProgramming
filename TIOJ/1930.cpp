#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

const int MAXN = 2e6;

int cur, A, B, C, K, N, M, t;
int pre[MAXN + 5], nxt[MAXN + 5];
lli sum;
vector<int> v;

void solve() {
	sum = 0;
	v.clear();

	cin >> N >> M >> t;

	pre[t] = 0;
	nxt[0] = t;
	nxt[t] = N + 1;
	pre[N + 1] = t;

	for (int i = 0; i < M; i++) {
		cin >> K >> A >> B >> C;

		if (K == 1) {
			if (C == 1) {
				nxt[A] = B;
				nxt[pre[B]] = A;
				pre[A] = pre[B];
				pre[B] = A;
			} else {
				nxt[A] = nxt[B];
				nxt[B] = A;
				pre[A] = B;
				pre[nxt[A]] = A;
			}
		} else if (K == 2) {
			nxt[pre[A]] = nxt[B];
			pre[nxt[B]] = pre[A];

			nxt[B] = C;
			pre[A] = pre[C];
			nxt[pre[C]] = A;
			pre[C] = B;
		} else {
			cur = A;
			if (C == 1) {
				while (B) {
					if (cur == 0)
						break;

					v.push_back(cur);
					cur = pre[cur];
					B--;
				}
				nxt[cur] = nxt[A];
				pre[nxt[A]] = cur;
			} else {
				while (B) {
					if (cur == N + 1)
						break;

					v.push_back(cur);
					cur = nxt[cur];
					B--;
				}
				nxt[pre[A]] = cur;
				pre[cur] = pre[A];
			}
			sum += B;
		}
	}

	cout << sum << '\n';
	for (int i : v)
		cout << i << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--)
		solve();
}
