#include <cstdio>

class MyMember {
public:
  MyMember(int id) : m_id{id} {
    printf("ctor id: %d\n", m_id);
  }

  // We need a trivial constructor to use in the variant below
  MyMember() : MyMember(0) {}

  ~MyMember() {
    printf("dtor id: %d\n", m_id);
  }

  int id() const {
    return m_id;
  }

private:
  int m_id;
};