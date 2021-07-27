#include <algorithm>
#include <iostream>
#include <numeric>
#include <tuple>
#include <vector>


std::tuple<std::vector<int>, std::vector<int>> get_indices(int s, int e) {
  std::vector<int> indices_r((std::abs(e - s) + 1));
  std::iota(std::begin(indices_r), std::end(indices_r), 0); // fill the vector
  std::vector<int> indices_c(indices_r);
  std::reverse(indices_c.begin(), indices_c.end()); // reverse the vector
  return std::make_tuple(indices_r, indices_c);
}

void diagnolSort(std::vector<std::vector<int>> &vec) { /*sorting the secondary diagonal*/
  size_t m_size = vec.at(0).size();          // get the size of the first vector
  for (int c = 0; c < m_size; c++) {
    auto indices = get_indices(0, c);
    // get the actual values from the matrix
    std::vector<int> temp; // temporarily store the values of the matrix
    for (int i = 0; i <= c; i++) {
      temp.emplace_back(vec[std::get<0>(indices)[i]][std::get<1>(indices)[i]]);
    }
    // sort the elements of the vector
    std::sort(temp.begin(), temp.end());
    // return the value back the array
    for (int i = 0; i <= c; i++) {
      vec[std::get<0>(indices)[i]][std::get<1>(indices)[i]] = temp.at(i);
    }
  }
}

int main() {
  std::vector<std::vector<int>> vec = {
      {15, 18, 19, 71, 42, 71, 35, 61}, {82, 87, 15, 19, 30, 71, 72, 15},
      {31, 66, 44, 16, 26, 26, 75, 17}, {26, 66, 73, 76, 64, 36, 56, 56},
      {45, 24, 53, 94, 60, 17, 52, 25}, {21, 67, 57, 94, 3, 75, 29, 54},
      {25, 73, 51, 92, 30, 27, 26, 54}, {25, 75, 57, 92, 07, 74, 26, 56}};
  diagnolSort(vec);
  for (int i = 0; i < vec.size(); i++) {
    std::cout << "{ ";
    for (int j = 0; j < vec.at(i).size(); j++) {
      std::cout << vec.at(i).at(j) << " ,";
    }
    std::cout << " }," << '\n';
  }
  return 0;
}
