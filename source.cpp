#include <iostream>
#include <string>

class Queue {
 private:
  int data_[200000];
  int min_[200000];
  int start_, end_, startmin_, endmin_;

 public:
  Queue() : start_(0), end_(0), startmin_(0), endmin_(0) {}

  void Enqueue(int a) {
    data_[end_] = a;
    end_++;
    std::cout << "ok" << std::endl;
    while (endmin_ > startmin_) {
      if (a <= data_[min_[endmin_ - 1]]) {
        endmin_--;
      } else {
        break;
      }
    }
    min_[endmin_] = end_ - 1;
    ++endmin_;
  }

  void Dequeue() {
    if (end_ == start_) {
      std::cout << "error" << std::endl;
    } else {
      std::cout << data_[start_] << std::endl;
      start_++;
      if ((start_ - 1) == min_[startmin_]) {
        startmin_++;
      }
    }
  }

  void Front() {
    if ((end_ - start_) == 0) {
      std::cout << "error" << std::endl;
    } else {
      std::cout << data_[start_] << std::endl;
    }
  }

  int Size() { return (end_ - start_); }

  void Clear() {
    start_ = 0;
    end_ = 0;
    std::cout << "ok" << std::endl;
    startmin_ = 0;
    endmin_ = 0;
  }

  void Min() {
    if ((end_ - start_) == 0) {
      std::cout << "error" << std::endl;
    } else {
      std::cout << data_[min_[startmin_]] << std::endl;
    }
  }
};

void Command(Queue& q) {
  std::string input;
  std::cin >> input;
  if (input == "enqueue") {
    int element;
    std::cin >> element;
    q.Enqueue(element);
  }
  if (input == "dequeue") {
    q.Dequeue();
  }
  if (input == "front") {
    q.Front();
  }
  if (input == "size") {
    std::cout << q.Size() << std::endl;
  }
  if (input == "clear") {
    q.Clear();
  }
  if (input == "min") {
    q.Min();
  }
}
int main() {
  int n = 0;
  std::cin >> n;
  Queue q;
  for (int i = 0; i < n; ++i) {
    Command(q);
  }
}
