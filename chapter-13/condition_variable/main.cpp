#include <algorithm>
#include <cassert>
#include <chrono>
#include <condition_variable>
#include <deque>
#include <functional>
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


std::mutex mu;
std::condition_variable mcond;
std::queue<int> mqueue;

void consumer() {
  while (true) {
    std::unique_lock<std::mutex> lck{mu};
    mcond.wait(lck);

    auto i = mqueue.front();
    mqueue.pop();

    lck.unlock();

    std::cerr << "Got from queue: " << i << "\n";
    if (i == 0) {
      break;
    }
  }
}

void producer() {
  for (int i=10; i >= 0; --i) {
    std::unique_lock<std::mutex> lck{mu};

    mqueue.push(i);
    mcond.notify_one();

    lck.unlock();

    std::this_thread::sleep_for(std::chrono::seconds{1});
  }
}

int main() {
  std::thread t1{consumer};
  std::thread t2{producer};

  t1.join();
  t2.join();
}