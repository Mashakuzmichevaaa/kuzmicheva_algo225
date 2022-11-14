#include <algorithm>
#include <iostream>
#include <vector>

class SparseTable {
  using Type = std::pair<int, int>;
  const int kDefault = 1000000005;
  size_t Size_;
  std::vector<Type> Sorted_;
  std::vector<int> Steps_;
  std::vector<size_t> Index_;
  std::vector<std::vector<Type>> Table_;
  static Type Operation(Type left, Type right) {
    int elements[4] = {left.first, left.second, right.first, right.second};
    std::sort(elements, elements + 4);
    std::unique(elements, elements + 4);
    return {elements[0], elements[1]};
  }

 public:
  explicit SparseTable(std::vector<int>& arr) {
    Size_ = arr.size();
    Steps_.resize(Size_ + 1);
    Table_.resize(Size_ + 1);
    for (size_t i = 0; i < Size_; ++i) {
      Sorted_.push_back({arr[i], i});
    }
    std::sort(Sorted_.begin(), Sorted_.end());
    Index_.resize(Size_);
    for (size_t i = 0; i < Size_; ++i) {
      Index_[Sorted_[i].second] = i;
    }
  }
  void Build() {
    for (size_t i = 0; i < Size_; ++i) {
      Table_[i].push_back({Index_[i], kDefault});
    }
    for (size_t k = 1, len = 2; len <= Size_; ++k, len <<= 1) {
      for (size_t i = 0; i + len <= Size_; ++i) {
        Table_[i].push_back(
            Operation(Table_[i + len / 2][k - 1], Table_[i][k - 1]));
      }
    }
    for (size_t i = 2, step = 2; i <= Size_; ++i) {
      Steps_[i] = Steps_[i - 1];
      if (i == step) {
        step *= 2;
        ++Steps_[i];
      }
    }
  }
  int Get(size_t l, size_t r) {
    size_t k = Steps_[r - l + 1];
    size_t len = 1 << k;
    return Sorted_[Operation(Table_[l][k], Table_[r - len + 1][k]).second]
        .first;
  }
};

class Task {
  size_t Size_;
  size_t QueriesSize_;
  std::vector<int> Original_;
  std::vector<std::pair<size_t, size_t>> Queries_;
  std::vector<int> Answers_;

 public:
  void ReadInput() {
    std::cin >> Size_ >> QueriesSize_;
    Original_.resize(Size_);
    Queries_.resize(QueriesSize_);
    Answers_.resize(QueriesSize_);
    for (size_t i = 0; i < Size_; ++i) {
      std::cin >> Original_[i];
    }
    for (size_t i = 0; i < QueriesSize_; ++i) {
      std::cin >> Queries_[i].first >> Queries_[i].second;
      if (Queries_[i].first > Queries_[i].second) {
        std::swap(Queries_[i].first, Queries_[i].second);
      }
    }
  }

  void Solve() {
    SparseTable table(Original_);
    table.Build();
    for (size_t i = 0; i < QueriesSize_; ++i) {
      Answers_[i] = table.Get(Queries_[i].first - 1, Queries_[i].second - 1);
    }
  }

  void PrintOutput() const {
    for (auto ans : Answers_) {
      std::cout << ans << "\n";
    }
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  Task task;
  task.ReadInput();
  task.Solve();
  task.PrintOutput();
}