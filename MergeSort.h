// MergeSort.h

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "Array.h"
#include "SortingAlgorithm.h"

using namespace std;

// MergeSort: Divide and Conquer
class MergeSort : public SortingAlgorithm {

 public:
  void merge(Array& A, int low, int mid, int high) {
    Array temp = Array(high - low + 1);
    int leftIdx = low;
    int activeIdx = 0;
    int rightIdx = mid + 1;
    while (leftIdx <= mid && rightIdx <= high) { // while either the left or right index extremes are not reached 
      temp[activeIdx] = (A[leftIdx] < A[rightIdx] ? A[leftIdx] : A[rightIdx]); // set the lower value
      A[leftIdx] < A[rightIdx] ? leftIdx++ : rightIdx++; // increment whichever side temp was set to
      activeIdx++;
    }
    while (leftIdx <= mid) { // run through remaining of whichever side wasn't completed
      temp[activeIdx] = A[leftIdx];
      activeIdx++;
      leftIdx++;
    }
    while (rightIdx <= high) { 
      temp[activeIdx] = A[rightIdx];
      activeIdx++;
      rightIdx++;
    }
    for (leftIdx = low; leftIdx <= high; leftIdx++) A[leftIdx] = temp[leftIdx-low]; // set A to temp values
  }

  void mergeSort(Array& A, int low, int high) {
    if (low >= high) return; // base case
    int mid = (low + high) / 2;
    mergeSort(A, low, mid);
    mergeSort(A, mid + 1, high);
    return merge(A, low, mid, high);
  };

  virtual void sort(Array& A) {
    if (A.length() <= 1) return;
    mergeSort(A, 0, A.length() - 1);
  }
};

#endif