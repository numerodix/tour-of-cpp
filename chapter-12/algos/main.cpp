#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  std::vector<int> nums_a{1, 2, 3};
  std::vector<int> nums_b{2, 2, 2};
  std::vector<int> dest(3, 0);

  const auto plus = [](int a, int b) { return a + b; };
  const auto equal_to = [](int a, int b) { return a == b; };


  int res = std::accumulate(nums_a.begin(), nums_a.end(), 7);
  assert(res == 13);

  res = std::accumulate(nums_a.begin(), nums_a.end(), 7, plus);
  assert(res == 13);


  // sum of products: nums[0] * nums2[0]   +   nums[1] * nums2[1]   +    ...
  res = std::inner_product(nums_a.begin(), nums_a.end(), nums_b.begin(), 0);
  assert(res == 12);

  // map/reduce version:
  //  use plus a pair from each vector:   int r0 = plus(nums[0], nums[1])
  //  use equal_to to reduce the intermediate results:  equal_to(r0, r1)
  res = std::inner_product(nums_a.begin(), nums_a.end(), nums_b.begin(), 0,
                           plus, equal_to);
  assert(res == 1);


  // iterate over the vector and for each element calculate the sum of all elements
  // up to that one
  std::partial_sum(nums_a.begin(), nums_a.end(), dest.begin(), plus);
  for (auto x: dest) {
    std::cout << x << ", ";
  }
  std::cout << '\n';


  // iterate over the vector and compute the difference between each two subsequent 
  // elements
  std::adjacent_difference(nums_a.begin(), nums_a.end(), dest.begin());
  for (auto x: dest) {
    std::cout << x << ", ";
  }
  std::cout << '\n';


  // fill the vector with values that increase by one for each element
  std::iota(dest.begin(), dest.end(), 1);
  for (auto x: dest) {
    std::cout << x << ", ";
  }
  std::cout << '\n';
}