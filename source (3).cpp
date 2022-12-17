#include <cmath>
#include <iostream>
#include <vector>

void LSD(std::vector<unsigned long long>& mass, int count, int n) {
  unsigned long long cur_pow = 1;
  std::vector<unsigned long long> res(n);
  for (int i = 0; i < count; i++) {
    std::vector<int> counter(10, 0);
    std::vector<int> remainder(10);
    for (int j = 0; j < n; j++) {
      unsigned long long c = mass[j] / cur_pow;
      int balance = c % 10;
      ++remainder[balance];
    }
    for (int j = 1; j < 10; ++j) {
      counter[j] = counter[j - 1] + remainder[j - 1];
    }
    for (int j = 0; j < n; ++j) {
      unsigned long long c = mass[j] / cur_pow;
      int balance = c % 10;
      res[counter[balance]] = mass[j];
      counter[balance]++;
    }
    std::swap(res, mass);
    cur_pow *= 10;
  }
}

int main() {
  int n;
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::cin >> n;
  int count = 0;
  std::vector<unsigned long long> mass(n);
  unsigned long long max = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> mass[i];
    if (mass[i] > max) {
      max = mass[i];
    }
  }
  count = log10(max) + 1;
  LSD(mass, count, n);
  for (int i = 0; i < n; i++) {
    std::cout << mass[i] << '\n';
  }
}
