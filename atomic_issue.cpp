#include <memory>
#include <string>
#include <vector>

namespace {

struct Block {
  std::vector<std::string> v;
};

std::shared_ptr<Block> foo() {
  std::shared_ptr<Block> p;

  /// Following code compiles on clang 12.0.0 but not on clang 12.0.5.
  // std::atomic_store<Block>(&p, std::make_shared<Block>());

  /// Removing `<Block>` compiles on both.
  std::atomic_store(&p, std::make_shared<Block>());

  return p;
}

} // namespace
