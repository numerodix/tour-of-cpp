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

  explicit MyVariant(char initial) : m_type{MyType::Initial}, m_value{MyValue{}} {
    m_value.m_initial = initial;
  }

  explicit MyVariant(uint32_t rubles) : m_type{MyType::Rubles}, m_value{MyValue{}} {
    m_value.m_rubles = rubles;
  }

  explicit MyVariant(uint64_t atoms) : m_type{MyType::Atoms}, m_value{MyValue{}} {
    m_value.m_atoms = atoms;
  }

  explicit MyVariant(std::string& name) : m_type{MyType::Name}, m_value{MyValue{}} {
    m_value.m_name = std::move(name);
  }

  explicit MyVariant(MyMember& member) : m_type{MyType::Member}, m_value{MyValue{}} {
    m_value.m_member = member;
  }

  char initial() const {
    assert(m_type == MyType::Initial);
    return m_value.m_initial;
  }

  uint32_t rubles() const {
    assert(m_type == MyType::Rubles);
    return m_value.m_rubles;
  }

  uint64_t atoms() const {
    assert(m_type == MyType::Atoms);
    return m_value.m_atoms;
  }

  std::string name() const {
    assert(m_type == MyType::Name);
    return m_value.m_name;
  }

  const MyMember& member() const {
    assert(m_type == MyType::Member);
    return m_value.m_member;
  }

private:
  struct MyValue {
    MyMember m_member;
    std::string m_name;
    uint64_t m_atoms;
    uint32_t m_rubles;
    char m_initial;
  }; 

  MyType m_type;
  MyValue m_value;
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
  // MyMember other = member;

  std::cout << sizeof(MyVariant) << '\n';
  std::cout << sizeof init << '\n';
  std::cout << sizeof rubl << '\n';
  std::cout << sizeof ato << '\n';
  std::cout << sizeof na << '\n';

  return 0;
}