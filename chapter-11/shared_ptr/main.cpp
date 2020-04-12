#include <algorithm>
#include <cassert>
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
#include <vector>

struct User {
  User(int id): id{id} {}
  ~User() { std::cerr << "dtor\n"; }

  int id;
};

std::shared_ptr<User> create_user(int id) {
  return std::make_shared<User>(id);
}

void display(std::shared_ptr<User> user) {
  std::cerr << "Got a user: " << user.get()->id << "\n";
}

int main() {
  auto user = create_user(1);
  display(user);
  display(user);
}