#include <deque>
#include <iostream>

void Defolt(int number, std::deque<int> &goblin1, std::deque<int> &goblin2) {
  goblin2.push_back(number);
  if (goblin1.size() < goblin2.size()) {
    int n;
    n = goblin2.front();
    goblin2.pop_front();
    goblin1.push_back(n);
  }
}

void Vipgoblin(int number, std::deque<int> &goblin1, std::deque<int> &goblin2) {
  if (goblin1.size() > goblin2.size()) {
    goblin2.push_front(number);
  } else if (goblin1.size() == goblin2.size()) {
    goblin1.push_back(number);
  }
}

void Gotoshaman(std::deque<int> &goblin1, std::deque<int> &goblin2) {
  std::cout << goblin1.front() << std::endl;
  goblin1.pop_front();
  if (goblin1.size() < goblin2.size()) {
    int k;
    k = goblin2.front();
    goblin2.pop_front();
    goblin1.push_back(k);
  }
}

int main() {
  std::deque<int> goblin1;
  std::deque<int> goblin2;
  int count;
  std::cin >> count;
  for (int i = 0; i < count; i++) {
    char ch;
    std::cin >> ch;
    if (ch == '+') {
      int number;
      std::cin >> number;
      Defolt(number, goblin1, goblin2);
    } else if (ch == '*') {
      int number;
      std::cin >> number;
      Vipgoblin(number, goblin1,goblin2);
    } else {
      Gotoshaman(goblin1, goblin2);
    }
  }
}
