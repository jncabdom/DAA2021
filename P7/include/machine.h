#include <utility>
#include <vector>

class machine {
 private:
  std::vector<std::pair<int, int>> tasks;
  int TCT;

 public:
  machine() {}
  ~machine() {}
  inline void insertTask(std::pair<int, int> newTask) {
    tasks.push_back(newTask);
  }
  inline bool isEmpty() { return tasks.empty(); }
  inline int getLast() { return (tasks.size() == 0) ? 0 : tasks.back().first; }
  inline std::vector<std::pair<int, int>>& getTasks() { return tasks; };
  inline int getTCT() { return TCT; }
  inline int size() { return tasks.size(); }
  int calculateIncrement();
  void calculateTCT();
  void clear();
};