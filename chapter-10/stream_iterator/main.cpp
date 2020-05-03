#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>

bool read_self() {
  std::ifstream is{"main.cpp"};
  std::istream_iterator<std::string> ii{is};
  std::istream_iterator<std::string> eos{};

  std::ofstream os{"output.txt"};
  std::ostream_iterator<std::string> oo{os, "\n"};

  // std::vector<std::string> b{ii, eos};
  // std::sort(b.begin(), b.end());
  // std::unique_copy(b.begin(), b.end(), oo);

  std::set<std::string> b{ii, eos};
  std::copy(b.begin(), b.end(), oo);

  return !is.eof() || !os;
}

int main() {
  std::ostream_iterator<std::string> oo{std::cout};
  *oo = "Hi ";
  ++oo;
  *oo = "there";

  read_self();
}