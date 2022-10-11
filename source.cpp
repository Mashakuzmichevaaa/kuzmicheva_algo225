#include <iostream>
#include <string>
int data[200000];
int start = 0;
int end = 0;
int min[200000];
int startmin = 0;
int endmin = 0;
void Enqueue(int a) {
  data[end] = a;
  end++;
  std::cout << "ok" << std::endl;
  while (endmin > startmin) {
    if (a <= data[min[endmin - 1]]) {
      endmin--;
    } else {
      break;
    }
  }
  min[endmin] = end - 1;
  ++endmin;
}
void Dequeue() {
  if (end == start) {
    std::cout << "error" << std::endl;
  } else {
    std::cout << data[start] << std::endl;
    start++;
    if ((start - 1) == min[startmin]) {
      startmin++;
    }
  }
}
void Front() {
  if ((end - start) == 0) {
    std::cout << "error" << std::endl;
  } else {
    std::cout << data[start] << std::endl;
  }
}
int Size() { return (end - start); }
void Clear() {
  start = 0;
  end = 0;
  std::cout << "ok" << std::endl;
  startmin = 0;
  endmin = 0;
}
void Min() {
  if ((end - start) == 0) {
    std::cout << "error" << std::endl;
  } else {
    std::cout << data[min[startmin]] << std::endl;
  }
}
void Command() {
  std::string input;
  std::cin >> input;
  if (input == "enqueue") {
    int element;
    std::cin >> element;
    Enqueue(element);
  }
  if (input == "dequeue") {
    Dequeue();
  }
  if (input == "front") {
    Front();
  }
  if (input == "size") {
    std::cout << Size() << std::endl;
  }
  if (input == "clear") {
    Clear();
  }
  if (input == "min") {
    Min();
  }
}
int main() {
  int n = 0;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    Command();
  }
}