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
#include <queue>
#include <stdexcept>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>


void consumer(std::future<int>&& fut) {
  int i = fut.get();
  std::cerr << "Got value: " << i << "\n";
}

void producer(std::promise<int>&& pr) {
  pr.set_value(7);
}

int main() {
  std::promise<int> pr{};
  std::future<int> fut = pr.get_future();

  std::thread t1{consumer, std::move(fut)};
  std::thread t2{producer, std::move(pr)};

  t1.join();
  t2.join();
}