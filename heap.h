// heap.h
// Daniel Li 

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include <algorithm>

class Heap{
   public:
    // return size of the heap
      unsigned int size() {
         return vdata.size();
      }
   
      void push(int value);     // insert value; //duplicates are allowed
      void pop(); // delete the min element 
      int top();
      bool empty();

   private:
      std::vector<int> vdata; //store the binary heap tree as a dynamic array
 
      int parent(int i) {
         return (i - 1) / 2;
      }
 
      int left(int i) {
         return (2*i + 1);
      }
 
      int right(int i) {
         return (2*i + 2);
      }
 

    void heapdown(int i)
    {
        int leftnum = left(i);
        int rightnum = right(i);
        int min = i;
 
        if (leftnum < size() && vdata[leftnum] < vdata[i]) {
            min = leftnum;
        }
 
        if (rightnum < size() && vdata[rightnum] < vdata[min]) {
            min = rightnum;
        }
 
        if (min != i)
        {
            std::swap(vdata[i], vdata[min]);
            heapdown(min);
        }
    }
 
    void heapup(int i)
    {
        if (i && vdata[parent(i)] > vdata[i])
        {
            std::swap(vdata[i], vdata[parent(i)]);
            heapup(parent(i));
        }
    }
 

};




#endif
