// SelectionSort.h

#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "Array.h"
#include "SortingAlgorithm.h"

using namespace std;

class SelectionSort : public SortingAlgorithm {
 public:
  void selectionSort(Array& A) {
    for (int i=0; i < A.length(); i++) {
      int min = i;
      for (int j= i + 1; j < A.length(); j++) {
        if (A[j] < A[min]) {
          min = j;
        }
      }
      int temp = A[min];
      A[min] = A[i];
      A[i] = temp;
    }
  }

  virtual void sort(Array& A) {
    selectionSort(A);
  }
};

#endif