#include <cmath>
#include <iomanip>
#include <iostream>

void Mass(int n, double* coordinates) {
  double k;
  for (int i = 0; i < n; i++) {
    std::cin >> k;
    if (i == 0) {
      coordinates[i] = k;
    } else {
      double coord1 = pow(coordinates[i - 1], i / (1.0 + i));
      double coord2 = pow(k, 1 / (1.0 + i));
      coordinates[i] = coord1 * coord2;
    }
  }
}

int main() {
  int n;
  std::cin >> n;
  double* coordinates = new double[n];
  Mass(n, coordinates);
  std::cout << std::fixed << std::setprecision(10);
  int q, left, right;
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    std::cin >> left >> right;
    double coord;
    if (left == 0) {
      coord = coordinates[right];
    } else {
      coord = coordinates[right] / pow(coordinates[left - 1], left / (right + 1.0));
    }
    double degree = (right + 1) / (right - left + 1.0);
    double answer = pow(coord, degree);
    std::cout << answer << std::endl;
  }
  delete[] coordinates;
}
