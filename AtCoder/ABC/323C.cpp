#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (int i = 0; i < m; i++)
		cin >> a[i];

	vector<int> score(n);
	vector<string> b(n);
	for (int i = 0; i < n; i++)
		score[i] = i;
	for (int i = 0; i < n; i++) {
		cin >> b[i];

		for (int j = 0; j < m; j++)
			if (b[i][j] == 'o')
				score[i] += a[j];
	}

	int mx = *max_element(score.begin(), score.end());
	for (int i = 0; i < n; i++) {
		vector<int> r;
		for (int j = 0; j < m; j++)
			if (b[i][j] == 'x')
				r.push_back(a[j]);
		sort(r.rbegin(), r.rend());

		int ans = 0;
		while (score[i] < mx)
			score[i] += r[ans++];

		cout << ans << '\n';
	}
}
