#include <iostream>
#include <algorithm>

class Segment
        {
    double A, B;

public:
    Segment(double A, double B) : A(A), B(B) {}

    double getA() const { return A; }
    double getB() const { return B; }

    Segment operator*(double d) const
    {
        return Segment(A * d, B * d);
    }

    friend Segment operator*(double d, const Segment& seg)
    {
        return seg * d;
    }

    Segment operator/(double d) const
    {
        return Segment(A / d, B / d);
    }

    Segment operator+(double d) const
    {
        return Segment(A + d, B + d);
    }

    friend Segment operator+(double d, const Segment& seg)
    {
        return seg + d;
    }

    Segment operator-(double d) const
    {
        return Segment(A - d, B - d);
    }

    Segment operator+(const Segment& seg) const
    {
        return Segment(std::min(A, seg.A), std::max(B, seg.B));
    }

    bool operator()(double d) const
    {
        return d >= A && d <= B;
    }

    friend std::ostream& operator<<(std::ostream& os, const Segment& seg)
    {
        os << "[" << seg.A << "," << seg.B << "]";
        return os;
    }
};

int main() {
    using std::cout; using std::endl;
    Segment seg{2, 3}, s = 1 + 2 * ((seg - 2) / 2 + seg) / 3;
    cout << s << endl << std::boolalpha;
    for (double x = 0.5; x < 4; x += 1) {
        cout << "x=" << x << ": " << s(x) << endl;
    }
    return 0;
}
