#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>

#include "member_alloc.h"
// #include "member_trivial.h"

class MyVariant {
public:
  enum class MyType { Initial, Rubles, Atoms, Name, Member };

  explicit MyVariant(char initial) : m_type{MyType::Initial}, m_initial{initial} {}

  explicit MyVariant(uint32_t rubles) : m_type{MyType::Rubles}, m_rubles{rubles} {}

  explicit MyVariant(uint64_t atoms) : m_type{MyType::Atoms}, m_atoms{atoms} {}

  explicit MyVariant(std::string name) : m_type{MyType::Name}, m_name{name} {}

  explicit MyVariant(MyMember& member) : m_type{MyType::Member}, m_member{member} {}

  MyVariant(const MyVariant& other) {
    printf("MyVariant copy ctor\n");
    m_type = other.m_type;

    switch (m_type) {
    case MyType::Initial:
      m_initial = other.m_initial;
      break;
    case MyType::Rubles:
      m_rubles = other.m_rubles;
      break;
    case MyType::Atoms:
      m_atoms = other.m_atoms;
      break;
    case MyType::Name:
      m_name = other.m_name;
      break;
    case MyType::Member:
      m_member = other.m_member;
      break;
    }
  }

  MyVariant& operator=(MyVariant& other) {
    printf("MyVariant copy ass\n");
    m_type = other.m_type;

    switch (m_type) {
    case MyType::Initial:
      m_initial = other.m_initial;
      break;
    case MyType::Rubles:
      m_rubles = other.m_rubles;
      break;
    case MyType::Atoms:
      m_atoms = other.m_atoms;
      break;
    case MyType::Name:
      m_name = other.m_name;
      break;
    case MyType::Member:
      m_member = other.m_member;
      break;
    }

    return *this;
  }

  ~MyVariant() {
    switch (m_type) {
    case MyType::Initial:
    case MyType::Rubles:
    case MyType::Atoms:
    case MyType::Name:
      // m_name.~basic_string<char>();
      break;
    case MyType::Member:
      m_member.~MyMember();
      break;
    }
  }

  MyType type() const {
    return m_type;
  }

  char initial() const {
    assert(m_type == MyType::Initial);
    return m_initial;
  }

  uint32_t rubles() const {
    assert(m_type == MyType::Rubles);
    return m_rubles;
  }

  uint64_t atoms() const {
    assert(m_type == MyType::Atoms);
    return m_atoms;
  }

  const std::string& name() const {
    assert(m_type == MyType::Name);
    return m_name;
  }

  const MyMember& member() const {
    assert(m_type == MyType::Member);
    return m_member;
  }

private:
  MyType m_type;

  union {
    MyMember m_member;
    std::string m_name;
    uint64_t m_atoms;
    uint32_t m_rubles;
    char m_initial;
  }; 

};


int main() {
  const MyVariant init{'c'};
  std::cout << init.initial() << '\n';

  const MyVariant rubl{1498U};
  std::cout << rubl.rubles() << '\n';

  const MyVariant ato{1UL << 52};
  std::cout << ato.atoms() << '\n';

  std::string rog{"roger"};
  const MyVariant na{rog};
  std::cout << na.name() << '\n';

  MyMember member{"harden"};
  const MyVariant mem{member};
  std::cout << mem.member().lastname() << '\n';

  std::cout << sizeof(MyVariant) << '\n';
  std::cout << sizeof init << '\n';
  std::cout << sizeof rubl << '\n';
  std::cout << sizeof ato << '\n';
  std::cout << sizeof na << '\n';

  // // copy ctor
  // const MyVariant init2{init};
  // std::cout << init2.initial() << '\n';

  // // copy ass
  // const MyVariant init3 = init;
  // std::cout << init3.initial() << '\n';

  // // move ctor
  // const MyVariant init4{std::move(init)};
  // std::cout << init4.initial() << '\n';

  // // move ass
  // const MyVariant init5 = std::move(init);
  // std::cout << init5.initial() << '\n';

  return 0;
}