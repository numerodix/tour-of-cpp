#include <algorithm>
#include <cassert>
#include <chrono>
#include <condition_variable>
#include <deque>
#include <functional>
#include <future>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <mutex>
#include <numeric>
#include <queue>
#include <stdexcept>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>


double accum(double *beg, double *end, double init) {
  return std::accumulate(beg, end, init);
}

int main() {
  std::vector<double> nums{1.1, 2.2, 3.3, 4.4, 5.5};

  using TaskType = double(double *, double *, double);

  std::packaged_task<TaskType> pt1{accum};
  std::packaged_task<TaskType> pt2{accum};

  std::future<double> f1{pt1.get_future()};
  std::future<double> f2{pt2.get_future()};

  double *first = &nums[0];

  std::thread t1{std::move(pt1), first, first + nums.size() / 2, 0};
  std::thread t2{std::move(pt2), first + nums.size() / 2, first + nums.size(), 0};

  t1.join();
  t2.join();

  double result = f1.get() + f2.get();
  std::cerr << "result: " << result << "\n";
}