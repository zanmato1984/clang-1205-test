#include <iostream>

struct Foo {};

namespace std {

template<>
struct is_integral<Foo> {
  static constexpr bool value = true;
};

// template<>
// constexpr bool is_integral_v<Foo> = is_integral<Foo>::value;

}

template <typename T>
constexpr bool test_integral = std::is_integral_v<T>;

template <typename T>
inline std::enable_if_t<test_integral<T>, void> bar()
{
  std::cout << "T is integral." << std::endl;
}

template <typename T>
inline std::enable_if_t<!test_integral<T>, void> bar()
{
  std::cout << "T is not integral." << std::endl;
}

int main() {
  bar<Foo>();
  return 0;
}
