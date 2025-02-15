template <typename T>
struct Point {
	T x, y;

	Point() : x(0), y(0) {}
	Point(int _x, int _y) : x(_x), y(_y) {}
	Point operator +(Point p) { return Point(x+p.x, y+p.y); }
	Point operator -(Point p) { return Point(x-p.x, y-p.y); }
	Point operator *(T c) { return Point(x*c, y*c); }
	Point operator /(T c) { return Point(x/c, y/c); }
};
template <typename T>
T dot(Point<T> a, Point<T> b) { return a.x*b.x + a.y*b.y; }
template <typename T>
T cross(Point<T> a, Point<T> b) { return a.x*b.y - a.y*b.x; }
