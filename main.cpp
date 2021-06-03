#include "no_matching_function_issue.h"

int main() {
  /// clang 12.0.0: T is integral.
  /// clang 12.0.5: T is not integral.
  bar<Foo>();

  return 0;
}
