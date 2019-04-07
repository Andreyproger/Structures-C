#include <iostream>
#include <list>
#include <cassert>

namespace andre{
  
template <int N, typename T>
class stack
{
public:
  static int const max_size = N;
  typedef T value_type;

private:
  value_type arr[max_size];
  value_type top;

public:
  
  stack()
  {
    top = -1;
  }
  
  void Push(const value_type value)
  {
    if(top >= (N-1))
      std::cerr << "Stack overflow!" << std::endl;
    else
    {
      ++top;
      arr[top]=value;
    }
  }
  
  void Pop()
  {
    if(top <= -1)
      std::cerr << "Stack underflow!" << std::endl;
    else
      --top;
  }
  
  value_type & Top ()
  {
    assert(top >= 0);
    return arr[top];
  }
  
  value_type Top () const
  {
    assert(top >= 0);
    return arr[top];
  }
  
  void Clear ()
  {
    top = -1;
  }
  
  std::size_t size() const
  {
    return (top + 1);
  }
  bool isEmpty()
  {
    if(top != -1)
      return false;
    else
      return true;
  }
  
  bool isFull()
  {
    return N == size(); //equal return N == size() ? true : false;
  }
#ifndef NDEBUG
  void dump()
  {
    if (size() == 0)
    {
      std::cerr << "Stack is empty!" << std::endl;
    }
    
    for(int i = 0; i < size(); ++i)
      std::cout << arr[i] << std::endl;
  }
#endif
};
}

void test_0 ()
{
  andre::stack<10, int> st;
  assert(st.isEmpty());
  assert(st.size() == 0);
}

void test_1 ()
{
  typedef andre::stack<10, int> st;
  stack_st st;
  
  for(int i = 0; i < stack_t::max_size; ++i)
    st.Push(i);
    
  assert(!st.isEmpty());
  assert(st.isFull());
  assert(st.size() == st.max_size());
}

void Test()
{
  test_0();
  test_1();
}

int main()
{
  Test();
  return 0;
}
