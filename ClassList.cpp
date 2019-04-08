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
  Forward() : first(NULL), last(NULL) // initialization before 
  {}
  
  ~Forward()
  {
    while(first)
    {
      first = first->next;
      delete first;
    }
  }
  
  void push_front(T value)
  {
    if (!first)
    {
      first = new Node();
      
      first->data = value;
      first->next = NULL;
      
      last = first;
    } else {
      Node * n = new Node();
      
      n->data = value;
      n->next = first;
      
      first = n;
    }
  }
  
  void push_back(T value)
  {
    if (!last)
    {
      last = new Node();
      
      last->data = value;
      last->next = NULL;
      
      first = last;
    } else {
      
      Node * n = new Node();
      
      last -> next = n;
      n -> data = value;
      n -> next = NULL;
      
      last = n;
    }
 }
 
 
 void erase_front ()
 {
   Node * n = first;
   first = first -> next;
   delete n;
 }
  
 bool empty() const
 {
   return first == NULL;
 }
  
 std::size_t size() const
 {
   Node * n = first;
   int k = 0;
   
   while(n)
   {
     n = n->next;
     ++k;
   }
   
   return k;
 }
};
  
template<typename T>
class BidirectionalList
{
  struct Node
  {
    T data;
    Node * prev;
    Node * next;
  };
  
public:
  BidirectionalList() : first(NULL), last(NULL)
    {}
  
  ~BidirectionalList()
  {
    while(first)
    {
      Node * first = first;
      first = n->next;
      delete n;
    }
  }
  
  bool isEmpty()
  {
    return (first == NULL) || (last == NULL);
  }
  
  std::size_t size() const
  {
    Node * n = first;
    int k = 0;
    
    while(n)
    {
      n = n->next;
      ++k;
    }
    return k;
  }
  
  void dump()
  {
    if(isEmpty())
      std::cout << std::endl << "Already empty!" << std::endl;
    
    Node  * n = first;
    std::cout << "[";
    while(n)
    {
      std::cout << n->data << " ";
      n = n->next;
    }
    std::cout << "]" << std::endl;
  }
  
  void push_back(T value)
  {
    if(!first)
    {
      Node * n = new Node();
      
      n->prev = NULL;
      n->next = NULL;
      n->data = value;
      
      first = n;
      last = n;
      
    } else {
      
      Node  * n = new Node();
      
      n->prev = last;
      n->next = NULL;
      n->data = value;
      
      last->next = n;
      last = n;
    }
  }
  
  void push_front(T value)
  {
    if(!last)
    {
      Node * n = new Node();
      
      n->prev = NULL;
      n->next = NULL;
      n->value = value;
      
      first = n;
      last = n;
      
    } else {
      
      Node * n = new Node();
      
      n->prev = NULL;
      n->next = first;
      n->value = value;
      
      first->prev = n;
      first = n;

    }   
  }
  
  void erase_front()
  {
    if(first)
    {
      Node * n = first;
      first = first->next;
      delete n;
    }
    
    if(!first)
      last = NULL;
  }
  
  void erase_back()
  {
    if(last)
    {
      Node * n = last;
      last = last->prev;
      delete n;
    }
    
    if(!last)
      first = NULL;
  }
};
  
}// namespace andre

void test_1()
{
  andre::ForwardList<int> list;
  
  list.push_front(5);
  
  assert(!list.empty());
  list.erase_front();
  
  assert(list.empty());
}

void test_2()
{
  andre::ForwardList<int> list;
  
  const int k = 99;
  
  for(int i = 0; i < k; ++i)
    list.push_front(i);
  
  list.push_back(100);
  
  assert(list.size() == k+1);
  
  for(int i = 0; i < k; ++i)
    list.erase_back();
  
  assert(list.size() == 1);
}

void test_3()
{
  andre::ForwardList<int> list;
  
  const int k = 88;
  
  for(int i = 0; i < k; ++i)
    list.push_front(i);
  
  for(int i = 0; i < k-1; ++i)
    list.erase_front(i);
  
  assert(list.size() == 1);
}


void Test()
{
  test_1();
  test_2();
  test_3();
  //TODO NEXT FUNCTION TESTS
}

int main()
{
  Test();
  return 0;
  return 0;
}
