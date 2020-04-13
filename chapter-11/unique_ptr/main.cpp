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

std::unique_ptr<User> create_user(int id) {
  return std::unique_ptr<User>{new User{id}};
}

void display(User* user) {
  std::unique_ptr<User> puser;
  puser.reset(user);
  std::cerr << "Got a user: " << puser.get()->id << "\n";
}

void pdisplay(std::unique_ptr<User> puser) {
  std::cerr << "Got a user: " << puser.get()->id << "\n";
}

int main() {
  auto puser = create_user(1);
  User *user = puser.release();
  display(user);

  auto puser2 = create_user(2);
  pdisplay(std::move(puser2));
}