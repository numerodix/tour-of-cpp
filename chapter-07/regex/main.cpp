#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <list>
#include <regex>
#include <string>
#include <vector>


int main() {
  std::regex pat{R"([a-zA-Z0-9]+)"};
  bool matches = std::regex_match(std::string{"bob"}, pat);

  assert(matches == true);

  std::string sentence{"mary had a little lamb"};
  for (std::sregex_iterator si(sentence.begin(), sentence.end(), pat);
        si != std::sregex_iterator{}; 
        si++) {
    std::cout << (*si)[0] << std::endl;
  }
}