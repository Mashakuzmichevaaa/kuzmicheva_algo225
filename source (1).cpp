#include <iostream>
#include <string>
#include <vector>

class Decrease {
 private:
  std::vector<std::pair<long long, long long>> heap_;

 public:
  void SiftUp(long long a) {
    while (a != 0) {
      if (heap_[a] < heap_[(a - 1) / 2]) {
        std::swap(heap_[a], heap_[(a - 1) / 2]);
        a = (a - 1) / 2;
      } else {
        break;
      }
    }
  }

  void SiftDown(long long a, long long& size) {
    while (2 * a + 1 < size) {
      long long b = a;
      if (heap_[2 * a + 1] < heap_[b]) {
        b = 2 * a + 1;
      }
      if (2 * a + 2 < size && heap_[2 * a + 2] < heap_[b]) {
        b = 2 * a + 2;
      }
      if (a == b) {
        return;
      }
      std::swap(heap_[a], heap_[b]);
      a = b;
    }
  }

  void Getmin(long long& count) {
    count++;
    long long t;
    t = heap_[0].first;
    std::cout << t << std::endl;
  }

  void DecreaseKey(long long c, long long key, long long& size,
                   long long& count) {
    for (long long i = 0; i < size; i++) {
      if (heap_[i].second == c) {
        ++count;
        heap_[i].first -= key;
        SiftUp(i);
      }
    }
  }

  void Insert(long long x, long long& count, long long& size) {
    heap_.push_back(std::make_pair(x, count));
    SiftUp(size);
    ++size;
    ++count;
  }

  void ExtractMin(long long& count, long long& size) {
    std::swap(heap_[0], heap_[size - 1]);
    heap_.pop_back();
    count++;
    size--;
    SiftDown(0, size);
  }

  void Command(long long& count, long long& size) {
    std::string input;
    std::cin >> input;
    if (input == "insert") {
      long long element;
      std::cin >> element;
      Insert(element, count, size);
    }
    if (input == "extractMin") {
      ExtractMin(count, size);
    }
    if (input == "getMin") {
      Getmin(count);
    }
    if (input == "decreaseKey") {
      long long c, key;
      std::cin >> c >> key;
      DecreaseKey(c - 1, key, size, count);
    }
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  long long n;
  std::cin >> n;
  long long count = 0;
  long long size = 0;
  Decrease heap;
  for (long long i = 0; i < n; i++) {
    heap.Command(count, size);
  }
}
