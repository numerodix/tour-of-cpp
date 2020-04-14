#include <algorithm>
#include <bitset>
#include <chrono>
#include <deque>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <stdexcept>
#include <string>
#include <thread>
#include <unordered_map>
#include <utility>
#include <vector>


class User {
  public:
    int get_id() { return -1; }
};


int main() {
  User u{};

  // creates a unbound method
  auto fn = std::mem_fn(&User::get_id);
  fn(u);
}