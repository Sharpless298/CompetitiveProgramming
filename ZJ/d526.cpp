#include <cstring>
#include <iostream>
using namespace std;

struct node {
	int key;
	int left, right;
};

int n, k, root, t;
node BST[1024];

void insert(int x, int &idx) {
	if (!idx) {
		idx = ++k;
		BST[idx].key = x;
		BST[idx].left = BST[idx].right = 0;
		return;
	}

	if (x < BST[idx].key)
		insert(x, BST[idx].left);
	else
		insert(x, BST[idx].right);
}

void DFS(int idx) {
	cout << BST[idx].key << ' ';
	if (BST[idx].left)
		DFS(BST[idx].left);
	if (BST[idx].right)
		DFS(BST[idx].right);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> n) {
		k = root = 0;
		memset(BST, 0, sizeof(BST));

		for (int i = 0; i < n; i++) {
			cin >> t;
			insert(t, root);
		}
		DFS(1);

		cout << '\n';
	}
}
