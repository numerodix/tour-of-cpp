#include <algorithm>
#include <cassert>
#include <deque>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <mutex>
#include <stdexcept>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>


std::mutex mu1;
std::mutex mu2;


void task(int id, const std::vector<int>& vec) {
  for (auto el: vec) {
    // synchronized access to std::cout
    // contrived example showing how to acquire two locks
    // before really locking them
    std::unique_lock<std::mutex> lock1{mu1, std::defer_lock};
    std::unique_lock<std::mutex> lock2{mu2, std::defer_lock};
    std::lock(lock1, lock2);  // only locked here

    std::cout << "[" << id << "] showing: " << el << std::endl;
  }
}


int main() {
  std::vector<int> vec1{1, 2, 3};
  std::vector<int> vec2{4, 5, 6};

  std::thread t1{task, 1, std::ref(vec1)};
  std::thread t2{task, 2, std::ref(vec2)};

  t1.join();
  t2.join();
}