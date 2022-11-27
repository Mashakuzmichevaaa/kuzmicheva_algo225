#include <iostream>
#include <string>

void Enqueue(int a, int* sos, int* data, int* min) {
  int k = sos[0];
  data[k] = a;
  sos[0]++;
  std::cout << "ok" << std::endl;
  while (sos[1] > sos[2]) {
    if (a <= data[min[sos[1] - 1]]) {
      sos[1]--;
    } else {
      break;
    }
  }
  min[sos[1]] = sos[0] - 1;
  ++sos[1];
}
void Dequeue(int* sos, int* data, const int* min) {
  if (sos[0] == sos[3]) {
    std::cout << "error" << std::endl;
  } else {
    std::cout << data[sos[3]] << std::endl;
    sos[3]++;
    if ((sos[3] - 1) == min[sos[2]]) {
      sos[2]++;
    }
  }
}
void Front(const int* sos, int* data) {
  if ((sos[0] - sos[3]) == 0) {
    std::cout << "error" << std::endl;
  } else {
    std::cout << data[sos[3]] << std::endl;
  }
}
int Size(int* sos) { return (sos[0] - sos[3]); }
void Clear(int* sos) {
  sos[3] = 0;
  sos[0] = 0;
  std::cout << "ok" << std::endl;
  sos[2] = 0;
  sos[1] = 0;
}
void Min(const int* sos, int* data, const int* min) {
  if ((sos[0] - sos[3]) == 0) {
    std::cout << "error" << std::endl;
  } else {
    std::cout << data[min[sos[2]]] << std::endl;
  }
}
void Command(int* sos, int* data, int* min) {
  std::string input;
  std::cin >> input;
  if (input == "enqueue") {
    int element;
    std::cin >> element;
    Enqueue(element, sos, data, min);
  }
  if (input == "dequeue") {
    Dequeue(sos, data, min);
  }
  if (input == "front") {
    Front(sos, data);
  }
  if (input == "size") {
    std::cout << Size(sos) << std::endl;
  }
  if (input == "clear") {
    Clear(sos);
  }
  if (input == "min") {
    Min(sos, data, min);
  }
}
int main() {
  int n = 0;
  std::cin >> n;
  int* data = new int[n];
  int start = 0;
  int end = 0;
  int* min = new int[n];
  int startmin = 0;
  int endmin = 0;
  int sos[4];
  sos[0] = end;
  sos[1] = endmin;
  sos[2] = startmin;
  sos[3] = start;
  for (int i = 0; i < n; ++i) {
    Command(sos, data, min);
  }
  delete[] data;
  delete[] min;
}
