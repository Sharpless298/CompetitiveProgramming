#include <iostream>
using namespace std;

bool flag;
char c;
char G[100][100];
int a, b, f = 0, cur_r, cur_c;
string s;

const int N = 0;
const int E = 1;
const int S = 2;
const int W = 3;

void move() {
	if (f == N && G[cur_r - 1][cur_c] == ' ')
		cur_r--;
	else if (f == E && G[cur_r][cur_c + 1] == ' ')
		cur_c++;
	else if (f == S && G[cur_r + 1][cur_c] == ' ')
		cur_r++;
	else if (f == W && G[cur_r][cur_c - 1] == ' ')
		cur_c--;

	return;
}

void facing() {
	if (f == N)
		cout << 'N';
	else if (f == E)
		cout << 'E';
	else if (f == S)
		cout << 'S';
	else
		cout << 'W';

	return;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	while (n--) {
		if (flag)
			cout << '\n';
		flag = true;
		f = 0;
		cin >> a >> b;
		cin.ignore();
		for (int i = 1; i <= a; i++) {
			getline(cin, s);
			for (int j = 1; j <= b; j++)
				G[i][j] = s[j - 1];
		}
		cin >> cur_r >> cur_c;
		while (cin >> c) {
			if (c == 'Q')
				break;
			else if (c == 'R')
				f = (f + 1) % 4;
			else if (c == 'L')
				f = (f + 3) % 4;
			else if (c == 'F')
				move();
			else
				continue;
		}

		cout << cur_r << ' ' << cur_c << ' ';
		facing();
		cout << '\n';
	}
}
