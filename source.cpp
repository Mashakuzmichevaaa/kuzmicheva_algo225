#include <cmath>
#include <iomanip>
#include <iostream>
double coordinates[3000000];
void Mass(int n) {
  double k;
  for (int i = 0; i < n; i++) {
    std::cin >> k;
    if (i == 0) {
      coordinates[i] = k;
    } else {
      double c = pow(coordinates[i - 1], i / (1.0 + i));
      double d = pow(k, 1 / (1.0 + i));
      coordinates[i] = c * d;
    }
  }
}
int main() {
  int n;
  std::cin >> n;
  Mass(n);
  std::cout << std::fixed << std::setprecision(10);
  int q, left, right;
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    std::cin >> left >> right;
    double a =
        coordinates[right] / pow(coordinates[left - 1], left / (right + 1.0));
    double b = (right + 1) / (right - left + 1.0);
    double answer = pow(a, b);
    std::cout << answer << std::endl;
  }
}