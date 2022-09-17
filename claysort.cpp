#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// prototypes
void combine(vector<string> &array, int start, int end);
void claysort(vector<string> &array, int start, int end);

// don't touch anything above this
void combine(vector<string> &array, int start, int end) {
  int i = start; // pointer that points to start
  int mid = (start + end) / 2; // pointer that points to middle of array
  int j = mid + 1; // pointer that points to mid + 1

  vector<string> temp;

  while (i <= mid and j <= end) {
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
  while (i <= mid) {
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
  
void claysort(vector<string> &array, int start, int end) {
  // base case
  if (start >= end) // we don't have any limits or we just have one element we need to sort
    return; // array containing 1 element is a sorted array

  // rec case
  int mid = (start + end) / 2;
  claysort(array, start, mid);
  claysort(array, mid + 1, end);
  // once the left part and right part are sorted we combine them into a single array
  return combine(array, start, end);
}

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
  
  int start = 0;
  int end = array.size() - 1;
  int mid = (start + end) / 2;
  int q1 = (start + mid) / 2;
  int q3 = (mid + end) / 2;
  int e1 = (start + q1) / 2;
  int e3 = (q1 + mid) / 2;
  int e5 = (mid + q3) / 2;
  int e7 = (q3 + end) / 2;
    
  claysort(array, start, e1);
  claysort(array, e1 + 1, q1);
  combine(array, start, q1);
  claysort(array, q1 + 1, e3);
  claysort(array, e3 + 1, mid);
  combine(array, q1, mid);
  combine(array, start, mid);
  claysort(array, mid + 1, e5);
  claysort(array, e5 + 1, q3);
  combine(array, mid, q3);
  claysort(array, q3 + 1, e7);
  claysort(array, e7 + 1, end);
  combine(array, q3, end);
  combine(array, mid, end);
  combine(array, start, end);

  for (auto x : array) {
    cout << x << "\n";
  }
  
  return 0;
}
