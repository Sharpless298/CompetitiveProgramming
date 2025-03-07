template <typename T>
struct Point {
	T x, y;

	Point() : x(0), y(0) {}
	Point(T _x, T _y) : x(_x), y(_y) {}

	friend Point operator+(const Point &p, const Point &q) {
		return Point(p.x + q.x, p.y + q.y);
	}
	friend Point operator-(const Point &p, const Point &q) {
		return Point(p.x - q.x, p.y - q.y);
	}
	friend Point operator*(const Point &p, const T &k) {
		return Point(p.x * k, p.y * k);
	}
	friend Point operator/(const Point &p, const T &k) {
		return Point(p.x / k, p.y / k);
	}
	friend T dot(const Point &p, const Point &q) {
		return p.x * q.x + p.y * q.y;
	}
	friend T cross(const Point &p, const Point &q) {
		return p.x * q.y - p.y * q.x;
	}
};
