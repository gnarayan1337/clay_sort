#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

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
  
  vector<string> array{};
  int n{}; 
  cout << "How many words would you like to sort?: ";
  cin >> n;

  for (int i = 0; i < n; i++) {
    cout << "Enter word #" << i + 1 << " : ";
    string inp; cin >> inp;
    array.push_back(inp);
  }

  int start = 0;
  int end = array.size() - 1;
  claysort(array, start, end);

  cout << "Sorted array!" << "\n";
  for (auto x : array) 
    cout << x << ", ";
  
  return 0;
}
