#include <iostream>
#include <vector>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, y, x;
	cin >> n >> m >> y >> x;
	vector<vector<char>> G(n, vector<char>(m));
	string s;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> G[i][j];
	cin >> s;

	y--, x--;
	for (int i = 0; i < (int)s.size(); i++) {
		int ny, nx;

		if (s[i] == 'R') {
			ny = y + dy[0];
			nx = x + dx[0];
		} else if (s[i] == 'D') {
			ny = y + dy[1];
			nx = x + dx[1];
		} else if (s[i] == 'L') {
			ny = y + dy[2];
			nx = x + dx[2];
		} else {
			ny = y + dy[3];
			nx = x + dx[3];
		}
		if (ny >= 0 && ny < n && nx >= 0 && nx < m && G[ny][nx] != '#')
			y = ny, x = nx;
	}

	cout << y + 1 << ' ' << x + 1 << '\n';
}
