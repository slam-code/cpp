//g++ -std=c++11 constexpr_ad.cpp -o ad
//https://www.zhihu.com/question/48356514
#include <iostream>


namespace AD {
template<typename T>
constexpr T pow_helper(T x, unsigned n) {
  return (n == 0) ? 1 :
    (n % 2 == 0) ? pow_helper(x*x, n/2) :
      x * pow_helper(x*x, (n-1)/2);
}
// x^n
template<typename T>
constexpr T pow(T x, int n) {
    return (n == 0) ? 1 :
        (n > 0) ? pow_helper(x, n) :
            1 / pow_helper(x, -n);
}
// n!
template<typename T>
constexpr T factorial(T n) {
  return (n == 1) ? 1: n*factorial(n-1);
}

// x^n/n!
template<typename T>
constexpr T xn_n(T x, unsigned n) {
  return pow(x, n) / factorial(n);
}
// calculation sin(x), N controls Taylor series order
template<typename T>
constexpr double sin(T x, unsigned N = 12) {
  return (N % 2 == 0 || N == 1) ? ((N ==1 ) ? x : sin(x, N-1)) :
    (((N-1)/2) % 2 == 0) ? (xn_n(x, N) + sin(x, N-2)) :
      (-xn_n(x, N) + sin(x, N-2));
}
// calculation cos(x), N controls Taylor series order
template<typename T>
constexpr double cos(T x, unsigned N = 12) {
  return (N % 2 == 1 || N == 0) ? ((N == 0) ? 1 : cos(x, N-1)) :
    ((N/2) % 2 == 0) ? (xn_n(x, N) + cos(x, N-2)) :
      (-xn_n(x, N) + cos(x, N-2));
}

// var
template<typename T>
struct Var {
  constexpr Var(T in):
    y(in), dy(1.0) {}
  T y;
  T dy;
};

// const
template<typename T>
struct Konst {
  constexpr Konst(T in):
    y(in), dy(0.0) {}
  T y;
  T dy;
};

// cos
//FIXME: 当N大于12时，N!会超出unsigned的最大值，导致精度下降
template<typename T>
struct Cos {
  constexpr Cos(T in, unsigned N = 12):
    y(cos(in.y, N)), dy(-sin(in.y, N)*in.dy) {}
  double y;
  double dy;
};
// sin
//FIXME: 当N大于12时，N!会超出unsigned的最大值，导致精度下降
template<typename T>
struct Sin {
  constexpr Sin(T in, unsigned N = 12):
    y(sin(in.y, N)), dy(cos(in.y, N)*in.dy) {}
  double y;
  double dy;
};
// add
template<typename T1, typename T2>
struct Add {
  constexpr Add(T1 in1, T2 in2):
    y(in1.y + in2.y), dy(in1.dy + in2.dy) {}
  double y;
  double dy;
};

// sub
template<typename T1, typename T2>
struct Sub {
  constexpr Sub(T1 in1, T2 in2):
    y(in1.y - in2.y), dy(in1.dy - in2.dy) {}
  double y;
  double dy;
};
// mutiply
template<typename T1, typename T2>
struct Mul {
  constexpr Mul(T1 in1, T2 in2):
    y(in1.y * in2.y), dy(in1.dy*in2.y + in1.y*in2.dy) {}
  double y;
  double dy;
};

} // end namespace AD

int main() {
  using namespace AD;

  constexpr Var<double> x0 {3.1415926};
  constexpr Konst<double> x1 {2.0};
  constexpr Konst<double> x2 {1.0};

  constexpr Cos<decltype(x0)> y1 {x0};
  constexpr Sin<decltype(x0)> y2 {x0};

  constexpr Mul<decltype(x1), decltype(y1)> y3 {x1, y1};
  constexpr Mul<decltype(x2), decltype(y2)> y4 {x2, y2};
  constexpr Mul<decltype(x1), decltype(y2)> y5 {x1, y2};
  constexpr Mul<decltype(x2), decltype(y1)> y6 {x2, y1};
  
  // z1 = x1*cos(x0) + x2*sin(x0)
  constexpr Add<decltype(y3), decltype(y4)> z1 {y3, y4};
  // z2 = x2*cos(x0) - x1*sin(x0)
  constexpr Sub<decltype(y6), decltype(y5)> z2 {y6, y5};

  static_assert(z1.dy < 0 , "Got z1 diff in compile time!");
  static_assert(z2.dy > 0 , "Got z2 diff in compile time!");

  std::cout << "x = [" << x0.y << ", " << x1.y << ", " << x2.y << "]" << std::endl;
  std::cout << "z = [" << z1.y << ", " << z2.y << "]" << std::endl;
  std::cout << "[dz1/dx0, dz2/dx0] = [" << z1.dy << "," << z2.dy << "]" << std::endl;

  return 0;
}
