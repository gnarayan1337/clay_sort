#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// prototypes
//void combine(vector<string> &array, int start, int cut, int end);
//void claysort(vector<string> &array, int start, int end);

// don't touch anything above this
void combine(vector<string> &array, int start, int cut, int end) {
  int i = start; // pointer that points to start
  int j = cut + 1; // pointer that points to mid + 1

  vector<string> temp;

  while (i <= cut and j <= end) {
    if (array[i] < array[j]) {
      temp.push_back(array[i]);
      i++;
    }
    else {
      temp.push_back(array[j]);
      j++;
    }
  }

  // copy remainng elements from first array
  while (i <= cut) {
    temp.push_back(array[i++]);
  }

  // or copy remaining elements from second array
  while(j <= end) {
    temp.push_back(array[j++]);
  }

  // copy back the elements from temp to original array
  int k = 0;
  for (int index = start; index <= end; index++) {
    array[index] = temp[k++];
  }
  return;
}
  
// void claysort(vector<string> &array, int start, int end) {
//   // base case
//   if (start >= end) // we don't have any limits or we just have one element we need to sort
//     return; // array containing 1 element is a sorted array

//   // rec case
//   int mid = (start + end) / 2;
//   claysort(array, start, mid);
//   claysort(array, mid + 1, end);
//   // once the left part and right part are sorted we combine them into a single array
//   return combine(array, start, end);
// }

int main() {
  cin.tie(nullptr) -> ios_base::sync_with_stdio(false);
  
  vector<string> array{};
  int n{}; 

  // new implementation finds end of file
  std::string inp; 
  while (std::getline(std::cin, inp)) {
    // ignoring case
    std::transform(inp.begin(), inp.end(), inp.begin(),
    [](unsigned char c){ return std::tolower(c); });
    array.push_back(inp);
  }

  //claysort(array, start, end);

  //the following code iteratively sorts larger and larger sections of the array at a time
  int windowSize = 2;
  int size = array.size();
  
  while (windowSize / 2 <= size) {
    int start = 0;
    int end = start + windowSize - 1;
    int cut = (start + end) / 2;
    while (end <= size - 1) {
      combine(array, start, cut, end);
      start += windowSize;
      cut += windowSize;
      end += windowSize;
    }
    cut = start + windowSize / 2 - 1;
    end = size - 1;
    combine(array, start, cut, end);
    windowSize *= 2;
  }
  
  for (auto x : array) {
    cout << x << "\n";
  }
  
  return 0;
}
