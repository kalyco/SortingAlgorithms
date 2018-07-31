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
    int t = f;
    A[f] = A[s];
    A[s] = t;
  }

  int getMedianOfThree(const Array A) {
    int first = 0;
    int second = A.length() / 2;
    int third = A.length() - 1;
    if (A[first] >= A[second] && A[first] >= A[third]) { // first is highest
      return (A[second] >= A[third] ? second : third); // return 2nd highest
    } else { // Another is higher
      if (A[second] <= A[third]) { // find next highest
        return (A[second] >= A[first] ? second : first); // return the higher value
      } else {
        return (A[third] >= A[first] ? third : first); // return 2nd lowest 
      }
    }
  }  

  int partition(Array & A, int low, int high) {
    int pivot = getMedianOfThree(A);
    int i = low - 1; // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
      if (A[j] <= pivot) {
        i++; // increment index of smaller element
        swap(A, i, j);
      }
    }
    swap(A, i + 1, high);
    return i + 1;
  }

  void quickSort(Array & A, int low, int high) {
    if (low >= high) return; // base case
    int pi = partition(A, low, high); // partitioning index
    quickSort(A, low, pi - 1);
    quickSort(A, pi + 1, high);    
  }

  virtual void sort(Array& A) {
    quickSort(A, 0, A.length() - 1);
  }
};

#endif