template <typename T>
inline void readint(T &x) {
	char c;
	x = 0;
	int f = 1;
	c = (char)getchar();
	while (c > 57 || c < 48) {
		if (c == 45) {
			f = -1;
		}
		c = (char)getchar();
	}
	while (c <= 57 && c >= 48) {
		x = (x << 3) + (x << 1) + c - 48;
		c = (char)getchar();
	}
	x *= f;
}
