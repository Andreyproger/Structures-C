#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <complex>

namespace andre{
template <typename T>
class ForwardList
{
  struct Node
  {
    T data;
    Node * next; 
  };
  
  Node first;
  Node last;
  
public:
  Forward() : first(NULL), last(NULL)
  {}
};
}
