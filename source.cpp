#include <iostream>

long long Quickselect(int* mass, int left, int right, int k) {
  int i = left;
  int j = right;
  if (left == right - 1) {
    if (mass[i] > mass[j]) {
      std::swap(mass[i], mass[j]);
    }
    if (k == 2) {
      return mass[j];
    }
    return mass[i];
  }
  int middle = mass[(right + left) / 2];
  while (i < j) {
    while (i < right && mass[i] < middle) {
      i++;
    }
    while (j > left && mass[j] > middle) {
      j--;
    }
    if (i < j) {
      std::swap(mass[i], mass[j]);
      i++;
      j--;
    }
  }
  if (i - left + 1 < k) {
    return Quickselect(mass, i, right, k + left - i);
  }
  if (k > j - left + 1) {
    return middle;
  }
  return Quickselect(mass, left, j, k);
}
int main() {
  int n;
  std::cin >> n;
  int k;
  std::cin >> k;
  int* mass = new int[n];
  int a_0, a_1;
  std::cin >> a_0 >> a_1;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      mass[0] = a_0;
    } else if (i == 1) {
      mass[1] = a_1;
    } else {
      int t;
      t = (mass[i - 1] * 123 + mass[i - 2] * 45) % (10000000 + 4321);
      mass[i] = t;
    }
  }
  std::cout << Quickselect(mass, 0, n - 1, k);
  delete[] mass;
}