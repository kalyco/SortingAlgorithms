// QuickSort.h

#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "Array.h"
#include "SortingAlgorithm.h"
#include <cstdlib>

using namespace std;

class QuickSort : public SortingAlgorithm {
 
 public:
  void swap(Array & A, int f, int s) {
    int t = A[f];
    A[f] = A[s];
    A[s] = t;
  }

  int getMedianOfThree(const Array A) {
    int first = 0;
    int second = A.length() / 2;
    int third = A.length() - 1;
    if (A[first] >= A[second] && A[first] >= A[third]) { // first is highest
      return (A[second] >= A[third] ? A[second] : A[third]); // return 2nd highest
    } else { // Another is higher
      if (A[second] <= A[third]) { // find next highest
        return (A[second] >= A[first] ? A[second] : A[first]); // return the higher value
      } else {
        return (A[third] >= A[first] ? A[third] : A[first]); // return 2nd lowest 
      }
    }
  } 

  virtual void sort(Array& A) {
    quickSort(A, 0, A.length() - 1);
  }

  int partition(Array & A, int low, int high) {
    int pi = low + (rand() % (high - low + 1));  // 1: Select pivot
    int pivot = A[pi]; // reference value
    A[pi] = A[high]; // 2: Swap pivot and high
    A[high] = pivot;
    int li = (low - 1);
    int hi = high;
    do {
      do {li++;} while (A[li] < pivot); // increment low index while it's value <= pivot
      do {hi--;} while (A[hi] > pivot && hi > low); // decrement high while its value > pivot
      if (li < hi) { 
        int tempHi = A[hi]; // swap the values
        A[hi] = A[li];
        A[li] = tempHi;
      }
    } while (li < hi);
    A[high] = A[li]; // set pivot back to middle and return
    A[li] = pivot;
    return li;
  }

  void quickSort(Array & A, int low, int high) {
    if (low >= high) return; // base case
    int x = partition(A, low, high);
    quickSort(A, low, x - 1);
    quickSort(A, x + 1, high);
  }
};

#endif