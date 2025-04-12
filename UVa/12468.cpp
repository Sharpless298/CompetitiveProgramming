#include <iostream>
using namespace std;

int main() {
	int a, b, p, q;

	while (cin >> a >> b && a != -1) {
		p = ((a - b) + 100) % 100;
		q = ((b - a) + 100) % 100;
		cout << min(p, q) << '\n';
	}
}
