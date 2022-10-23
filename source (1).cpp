#include <iostream>
#include <string>
#include <vector>

void SiftUp(long long a, std::vector<std::pair<long long, long long>>& heap) {
  while (a != 0) {
    if (heap[a] < heap[(a - 1) / 2]) {
      std::swap(heap[a], heap[(a - 1) / 2]);
      a = (a - 1) / 2;
    } else {
      break;
    }
  }
}
void SiftDown(long long a, std::vector<std::pair<long long, long long>>& heap,
              long long& size) {
  while (2 * a + 1 < size) {
    long long b = a;
    if (heap[2 * a + 1] < heap[b]) {
      b = 2 * a + 1;
    }
    if (2 * a + 2 < size && heap[2 * a + 2] < heap[b]) {
      b = 2 * a + 2;
    }
    if (a == b) {
      return;
    }
    std::swap(heap[a], heap[b]);
    a = b;
  }
}
void Getmin(std::vector<std::pair<long long, long long>>& heap,
            long long& count) {
  count++;
  long long t;
  t = heap[0].first;
  std::cout << t << std::endl;
}
void DecreaseKey(long long c, long long key,
                 std::vector<std::pair<long long, long long>>& heap,
                 long long& size, long long& count) {
  for (long long i = 0; i < size; i++) {
    if (heap[i].second == c) {
      ++count;
      heap[i].first -= key;
      SiftUp(i, heap);
    }
  }
}
void Insert(long long x, std::vector<std::pair<long long, long long>>& heap,
            long long& count, long long& size) {
  heap.push_back(std::make_pair(x, count));
  SiftUp(size, heap);
  ++size;
  ++count;
}
void ExtractMin(std::vector<std::pair<long long, long long>>& heap,
                long long& count, long long& size) {
  std::swap(heap[0], heap[size - 1]);
  heap.pop_back();
  count++;
  size--;
  SiftDown(0, heap, size);
}
void Command(std::vector<std::pair<long long, long long>>& heap,
             long long& count, long long& size) {
  std::string input;
  std::cin >> input;
  if (input == "insert") {
    long long element;
    std::cin >> element;
    Insert(element, heap, count, size);
  }
  if (input == "extractMin") {
    ExtractMin(heap, count, size);
  }
  if (input == "getMin") {
    Getmin(heap, count);
  }
  if (input == "decreaseKey") {
    long long c, key;
    std::cin >> c >> key;
    DecreaseKey(c - 1, key, heap, size, count);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  long long n;
  std::cin >> n;
  long long count = 0;
  long long size = 0;
  std::vector<std::pair<long long, long long>> heap;
  for (long long i = 0; i < n; i++) {
    Command(heap, count, size);
  }
}