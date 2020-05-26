#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <list>
#include <regex>
#include <string>
#include <memory>


class Dummy {
  public:
    Dummy(int _id) : id{_id} { std::cout << "ctor" << id << "\n"; }
    ~Dummy() { std::cout << "dtor" << id << "\n"; }

    void show() { std::cout << "I am " << id << "\n"; }

  private:
    int id;
};

using UDummy = std::unique_ptr<Dummy>;
using SDummy = std::shared_ptr<Dummy>;

UDummy get_udmmy() {
  auto up = std::make_unique<Dummy>(3);
  return up;
}

void usink(UDummy p) {
  p->show();
}

void ssink(SDummy p) {
  p->show();
}

class Holder {
  public:
    Holder(SDummy _sd) : sd{_sd} {}
  private:
    SDummy sd;
};

int main() {
  auto up = std::make_unique<Dummy>(1);
  auto sp = std::make_shared<Dummy>(2);

  auto up2 = get_udmmy();

  Holder* h = new Holder(sp);  // not deleted - causes sp to leak as well

  usink(std::move(up));
  ssink(sp);

  up->show();  // segfault because up has been moved from!
  sp->show();
  std::cout << "ma\n";
}