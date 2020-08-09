#include <cstdio>
#include <cstring>

class MyMember {
public:
  MyMember(const char *lastname) : m_lastname{new char[strlen(lastname) + 1]} {
    strncpy(m_lastname, lastname, strlen(lastname) + 1);
    printf("ctor lastname: %s add: %p\n", m_lastname, m_lastname);
  }

  MyMember(const MyMember& other) : MyMember(other.m_lastname) {
    printf("copy ctor\n");
  }

  MyMember& operator=(MyMember other) {
    printf("copy ass\n");
    delete[] m_lastname;

    m_lastname = new char[strlen(other.m_lastname) + 1];
    strncpy(m_lastname, other.m_lastname, strlen(other.m_lastname));

    return *this;
  }

  // We need a trivial constructor to use in the variant below
  MyMember() : MyMember("") {}

  ~MyMember() {
    printf("dtor add: %p\n", m_lastname);
    delete[] m_lastname;
  }

  const char* lastname() const {
    return m_lastname;
  }

private:
  char *m_lastname;
};
