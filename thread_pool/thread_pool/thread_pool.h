#ifndef LAKETI_INFER_THREAD_POOL_H
#define LAKETI_INFER_THREAD_POOL_H

#include <cstdlib>
#include <utility>
#include <condition_variable>
#include <functional>
#include <vector>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <cassert>
#include <atomic>

#include <sstream>

#include <iostream>

using std::vector;
using std::string;

class ThreadPool {
public:
  typedef std::function<void(int)> Work;
  ThreadPool(int num_thread, const char* name);

  ThreadPool(int num_thread, const std::string& name)
    : ThreadPool(num_thread, name.c_str()) {}

  ~ThreadPool();
  void AddWork(Work work, int64_t priority = 0, bool start_immediately = false);

  void RunAll(bool wait = true);

  void WaitForWork(bool checkForErrors = true);

  int NumThreads() const;

  std::vector<std::thread::id> GetThreadIds() const;

private:
  void ThreadMain(int thread_id, const std::string &name);
  vector<std::thread> threads_;

  using PrioritizedWork = std::pair<int64_t, Work>;

  struct SortByPriority {
    bool operator() (const PrioritizedWork &a, const PrioritizedWork &b) {
      return a.first < b.first;
    }
  };
  std::priority_queue<PrioritizedWork, std::vector<PrioritizedWork>, SortByPriority> work_queue_;

  bool running_;
  bool work_complete_;
  bool started_;
  int active_threads_;
  std::mutex mutex_;
  std::condition_variable condition_;
  std::condition_variable completed_;

  //  Stored error strings for each thread
  vector<std::queue<string>> tl_errors_;
};

#endif