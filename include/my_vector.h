#include <bits/stdc++.h>

template <typename T> class myVector {
  T *arr;
  size_t cap;
  size_t curr;

public:
  myVector() : arr(nullptr), curr(0), cap(0) {}

  ~myVector() { delete[] arr; }

  void push_back(T data) {
    if (curr == cap) {
      cap = (cap == 0 ? 1 : cap * 2);
      T *temp = new T[2 * cap];
      for (int i = 0; i < curr; ++i) {
        temp[i] = arr[i];
      }
      delete[] arr;
      cap *= 2;
      arr = temp;
    }
    arr[curr++] = data;
  }

  T get(int idx) {
    if (idx < curr) {
      return arr[idx];
    }
    throw std::out_of_range("idx out of range");
  }

  void pop() {
    if (curr > 0)
      --curr;
  }

  int size() { return curr; }

  int get_capacity() { return cap; }

  const T &operator[](size_t idx) const {
    if (idx >= curr)
      throw std::out_of_range("index out of range");
    return arr[idx];
  }

  T &operator[](size_t idx) {
    if (idx >= curr)
      throw std::out_of_range("index out of range");
    return arr[idx];
  }
};
