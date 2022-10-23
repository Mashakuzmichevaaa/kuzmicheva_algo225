#include <iostream>
#include <vector>

struct MinMaxHeap {
  std::vector<int> min_heap, max_heap, min_brother, max_brother;
  int size;

  MinMaxHeap() { size = 0; }

  void Swap(std::vector<int>& heap, std::vector<int>& brother,
            std::vector<int>& second_brother, int ind1, int ind2) {
    std::swap(second_brother[brother[ind1]], second_brother[brother[ind2]]);
    std::swap(heap[ind1], heap[ind2]);
    std::swap(brother[ind1], brother[ind2]);
  }

  void MinSiftDown(int node) {
    while (2 * node + 1 < size) {
      int child = node;
      if (min_heap[2 * node + 1] < min_heap[child]) {
        child = 2 * node + 1;
      }
      if (2 * node + 2 < size && min_heap[2 * node + 2] < min_heap[child]) {
        child = 2 * node + 2;
      }
      if (node == child) {
        return;
      }
      Swap(min_heap, min_brother, max_brother, node, child);
      node = child;
    }
  }

  void MaxSiftDown(int node) {
    while (2 * node + 1 < size) {
      int child = node;
      if (max_heap[2 * node + 1] > max_heap[child]) {
        child = 2 * node + 1;
      }
      if (2 * node + 2 < size && max_heap[2 * node + 2] > max_heap[child]) {
        child = 2 * node + 2;
      }
      if (node == child) {
        return;
      }
      Swap(max_heap, max_brother, min_brother, node, child);
      node = child;
    }
  }

  void MinSiftUp(int node) {
    while (node != 0) {
      if (min_heap[node] < min_heap[(node - 1) / 2]) {
        Swap(min_heap, min_brother, max_brother, node, (node - 1) / 2);
        node = (node - 1) / 2;
      } else {
        break;
      }
    }
  }

  void MaxSiftUp(int node) {
    while (node != 0) {
      if (max_heap[node] > max_heap[(node - 1) / 2]) {
        Swap(max_heap, max_brother, min_brother, node, (node - 1) / 2);
        node = (node - 1) / 2;
      } else {
        break;
      }
    }
  }

  void SiftUp(std::vector<int>& heap, std::vector<int>& brother,
              std::vector<int>& second_brother, int node) {
    while (node != 0) {
      Swap(heap, brother, second_brother, node, (node - 1) / 2);
      node = (node - 1) / 2;
    }
  }

  void Insert(int value) {
    min_brother.push_back(size);
    max_brother.push_back(size);
    min_heap.push_back(value);
    max_heap.push_back(value);
    MinSiftUp(size);
    MaxSiftUp(size);
    size++;
  }

  void ExtractMinRoot() {
    Swap(min_heap, min_brother, max_brother, 0, size - 1);
    min_heap.pop_back();
    min_brother.pop_back();
    size--;
    MinSiftDown(0);
    size++;
  }

  void ExtractMaxRoot() {
    Swap(max_heap, max_brother, min_brother, 0, size - 1);
    max_heap.pop_back();
    max_brother.pop_back();
    size--;
    MaxSiftDown(0);
    size++;
  }

  void ExtractMin() {
    int index_in_max = min_brother[0];
    ExtractMinRoot();
    SiftUp(max_heap, max_brother, min_brother, index_in_max);
    ExtractMaxRoot();
    --size;
  }

  void ExtractMax() {
    int index_in_min = max_brother[0];
    ExtractMaxRoot();
    SiftUp(min_heap, min_brother, max_brother, index_in_min);
    ExtractMinRoot();
    --size;
  }

  int GetMin() { return min_heap[0]; }

  int GetMax() { return max_heap[0]; }

  int Size() { return size; }

  void Clear() {
    size = 0;
    min_heap.clear();
    max_heap.clear();
    min_brother.clear();
    max_brother.clear();
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  MinMaxHeap heap;
  int m;
  std::cin >> m;
  for (int i = 0; i < m; ++i) {
    std::string command;
    std::cin >> command;
    if (command == "insert") {
      int value;
      std::cin >> value;
      heap.Insert(value);
      std::cout << "ok\n";
    } else if (command == "extract_min") {
      if (heap.Size() == 0) {
        std::cout << "error\n";
      } else {
        std::cout << heap.GetMin() << '\n';
        heap.ExtractMin();
      }
    } else if (command == "extract_max") {
      if (heap.Size() == 0) {
        std::cout << "error\n";
      } else {
        std::cout << heap.GetMax() << '\n';
        heap.ExtractMax();
      }
    } else if (command == "get_min") {
      if (heap.Size() == 0) {
        std::cout << "error\n";
      } else {
        std::cout << heap.GetMin() << '\n';
      }
    } else if (command == "get_max") {
      if (heap.Size() == 0) {
        std::cout << "error\n";
      } else {
        std::cout << heap.GetMax() << '\n';
      }
    } else if (command == "size") {
      std::cout << heap.Size() << '\n';
    } else if (command == "clear") {
      heap.Clear();
      std::cout << "ok\n";
    }
  }
}