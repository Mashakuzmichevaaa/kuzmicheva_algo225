#include <deque>
#include <iostream>

std::deque<int> goblin1;
std::deque<int> goblin2;
void Defolt(int number) {
  goblin2.push_back(number);
  if (goblin1.size() < goblin2.size()) {
    int n;
    n = goblin2.front();
    goblin2.pop_front();
    goblin1.push_back(n);
  }
}

void Vipgoblin(int number) {
  if (goblin1.size() > goblin2.size()) {
    goblin2.push_front(number);
  } else if (goblin1.size() == goblin2.size()) {
    goblin1.push_back(number);
  }
}

void Gotoshaman() {
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
  int count;
  std::cin >> count;
  for (int i = 0; i < count; i++) {
    char ch;
    std::cin >> ch;
    if (ch == '+') {
      int number;
      std::cin >> number;
      Defolt(number);
    } else if (ch == '*') {
      int number;
      std::cin >> number;
      Vipgoblin(number);
    } else {
      Gotoshaman();
    }
  }
}