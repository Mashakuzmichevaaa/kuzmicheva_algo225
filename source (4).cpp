#include <iostream>

void Quicksort(int* mass, int n) {
  int left = 0;
  int right = n - 1;
  int middle = mass[n / 2];
  do {
    while (mass[left] < middle) {
      left++;
    }
    while (mass[right] > middle) {
      right--;
    }
    if (left <= right) {
      std::swap(mass[left], mass[right]);
      left++;
      right--;
    }
  } while (left <= right);
  if (right > 0) {
    Quicksort(mass, right + 1);
  }
  if (left < n) {
    Quicksort(&mass[left], n - left);
  }
}
int main() {
  int n;
  std::cin >> n;
  int* mass = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> mass[i];
  }
  Quicksort(mass, n);
  for (int i = 0; i < n; i++) {
    std::cout << mass[i] << " ";
  }
  delete[] mass;
}