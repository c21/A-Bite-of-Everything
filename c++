1.RPC
  remote procedure call.
  A program calls a procedure, which is implemented in another process's address space.
  a form of inter process communication.

  IDL: interface description language
  define the interface between systems in different languages, commonly used in RPC.


2.Apache Thrift
  an implementation of RPC.
   

3.C++
(1).namespace
  A collection of names.
  The standard library uses "std" as namespace, to contain all the names it defines. 
  e.g.std::cout refers to standard output stream, std::cerr, std::clog refers to standard error stream.
      std::cout is qualified name
      :: is scope operator

(2).variable
  A variable is an object that has a name.
  An object is a part of memory that has a type.
  A type is a data structure and operations.

(3).std::string (type)
  construct:
  string s
  string s(length, character): e.g. string s(5,'*'); (s is "*****") 

  operator:
  +: concatenate two strings, e.g. string str_a = str_b + "\n"; 
  =: copy string content, e.g. string str_a = str_b.
  <: compare two strings by alphabetical order (like strcmp in C)
  [i]: get the ith char.
 
  member function:
  size(): the length of string
  push_back(): append a new char to string
  substr(idx, length): get substring   
  begin(): denote the first element (iterator) in string.
  end(): denote one past the last element (iterator) in string. 

  header:
  <string>      

(4).using declaration
  e.g. using std::cout;
  we can use cout, instead of std::cout in the scope of using declaration.
 
(5).if(cin >> x)
  This if condition will succeed when there is one input.
  The result of "cin >> x" is "cin".
  if(cin >> x) is equal to 
  cin >> x; if(cin)
  the class of cin provides a conversion from cin to an integer value used in condition.

(6).vector (type) 
  (Accelerated C++: P130)
  vector is a type (fast random/sequential access array), specifically a container(holds values).
  All values in vector must be the same type. 
  vector<value-type> id;
  e.g. vector<int> my_array; 

  construct:
  vector<value-type> v: construct an empty vector
  vector<value-type> v(begin, end): construct a vector based on iterator begin and end.
                                    copy element in [begin, end) into vector from another vector.
  operator:
  =: copy all elements in another vector, e.g. vector<int> a = b;
  [i]: get the ith element.
 
  member function:
  push_back(v): append new element "v" to the end of vector.
                push_back() will make all previous iteratos invalidate.
  begin(): denote the first element in vector.
  end(): denote one past the last element in vector.
  rbegin(): denote the last element in vector, and march backward in container.
  size(): the number of elements in vector.
  clear(): clear the vector.
  erase(i): remove the "i"(i is an iterator) element in vector,
            e.g. erase the ith element: int i = 5; v.erase(v.begin()+i);
            return the new iterator after the one erased.
            erase() will make all previous iterators invalidate.
  erase(begin, end): begin, end are iterator. remove element in [begin, end).
  insert(): insert another vector into this vector.
  empty(): check whether the vector is empty (more efficient than check size() is zero)
   
  header:
  <vector> 

  *insert or delete elements other than at the end of vector, is expensive.
  *call to size() is fast.

(7).list (type)
  list is a type of container (fast random deletion and insertion, slow access array)
  It has same operations with vector, except random access by indexing: [i]
  Because lacking of support for random access, cannot use sort() funciton in <algorithm>.
  list provides its own sort function. 

(8).map (type)
  map is a type of container (fast look up)
  each element is key-value pair (type pair).
  map<key-type, value-type> id;
  e.g. map<string, int> my_map;

  operator:
  [i]: get the value for key i (i can be any type, not just integer).
      *first time use a key to index map, and key doesn't appear in map, map will create
       a new value for that key, the value is default (such as 0 for int, empty for vector)

  member function:
  find(key): find the iterator for the key, if not find, return the iterator for end

(9).pair (type)
  a pair has two elements.
  pair<first-type, second-type> id;
  e.g. pair<int, int> my_pair;

  member variable:
  first: the first element, e.g. my_pair.first;
  second: the second element, e.g. my_pair.second;
 
(7).useful functions
  (anywhere there is an iterator argument, can also be provided with a pointer argument)
  1.<algorithm>
  http://www.cplusplus.com/reference/algorithm/
  sort(begin, end): e.g. vector<int> v; sort(v.begin(), v.end())
                    sort the container[begin,end) in place, do not create any new container.   
  sort(begin, end, pred): pred is a function to implement <, e.g. bool compare(...& a, ...& b) 
  max(e1, e2): return the larger of e1 and e2. 
  copy(begin, end, iter): copy the element from begin to end, to iter.
                          begin, end, iter are all iterators.
                          e.g. copy(v1.begin(), v1.end(), back_inserter(v2))
  find_if(begin, end, pred): pred is a function with input element, output bool.
                             test pred on each element from begin to end, 
                             stop when it finds an element that pred yield true.
                             return an iterator (if not find, return end).
  find(begin, end, elem): find elem on each element from begin to end,
                          return an iterator (if not find, return end).
  search(begin1, end1, begin2, end2): search [begin2, end2) in [begin1, end1),
                                      return an iterator (if not find, return end1).
  equal(begin, end, begin2): it compares two container is equal or not.
                             begin, end indicates one container, begin2 indicates
                             the start element of another container.
                             assume two container has the same size.  
                             e.g. string s; equal(s.begin(), s.end(), s.rbegin())                               
  transform(begin, end, iter, func): begin,end,iter are iterator, func is function.
                                     apply func for each element from begin to end,
                                     store the result of func to iter.
  remove(begin, end, elem): begin,end are iterator, remove all elements from begin to end,
                            that equal to elem, return the new end of elements.
  remove_if(begin, end, pred): pred is a function with input element, output bool.
                               begin,end are iterator, remove all elements from begin to end,
                               that yeilds pred true, return the new end of elements.
  remove_copy(begin, end, iter, elem): begin,end,iter are iterator, remove all elements from begin to end,
                                       that equal to elem, return the new end of elements, copy all elements
                                       that are not removed to iter.
  remove_copy_if(begin, end, iter, pred): pred is a function with input element, output bool.
                                          begin,end,iter are iterator, remove all elements from begin to end,
                                          that yields pred true, return the new end of elements, copy all elements
                                          that are not removed to iter.
  *remove,remove_if,remove_copy,remove_copy_if functions don't remove elements, just move the elements not removed
   to the beginning of container, and overwrite previous elements.

  partition(begin, end, pred): pred is a function with input element, output bool.
                               begin,end are iterator, move all elements from begin to end,
                               that yeilds pred true to the beginning of vector, move other elements
                               to the end of vector, return the new begin of second part of elements.

  stable_partition(begin, end, pred): same as partition, keep the previous of order of elements unchanged.

  *these functions don't change the property of containers(such as size), only change the element in containers. 
  2.<numeric>
  offer function for numeric computation.
  accumulate(begin, end, initial_value):begin, end are iterator, sum up element (and initial_value) 
                                        from begin to end. The type of return value is same as inital_value.
                                        e.g. vector<double> v; accumulate(v.begin(), v.end(), 0.0);
(8).function parameter
  1.call by value:
    C++ function is call by value, which means each parameter takes a copy of the value of argument.

  2.function as parameter
    parameter that represents a function is written as function declaration.
    void func_b(int x)
    {
      ...
    }
    void func_a(void func_b(int), int)
    {
      ...
    }

  3.default argument
    default argument is used to provide a default value of argument, when caller don't 
    specify that argument, the default value will be used.
    e.g. 
    int foo(int a, int b=1)
    {
      ...
    }  
    foo(2,2); // okay, b == 2
    foo(2);   // okay, b == 1

(9).reference
  Another name of object. type& a = b;
  Anything doing on a is the same as anything doing on b.

(10).overloading
  Functions with the same function name.  

(11).exception
  C++ can throw exception.
  try
  {
    throw ...;
  }
  catch (...) 
  {

  }

(12).header file
  put declarations in header file.
  #include <...>: system header
  #include "...": user defined header

  Better to start with 
  #ifndef ...
  #define ...
    ...
  #endif
  avoid multiple inclusion of header file. 

(13).iterator
  Iterator is a type, every container has an iterator type.
  container-type::iterator
  e.g. vector<int>::iterator
  Iterator is used to sequentially(not random) access and operate on element in container.
  It will be efficient due to sequentially access. 

  operator:
  =: assign an iterator, e.g. vector<int> v; vector<int>::iterator iter = v.begin();
  !=,==: determine whether two iterators are equal, e.g. iter != v.end(); 
  ++,--: increment/decrement the iterator to refer to next element, e.g. iter++;
  +,-: increment/decrement the iterator to refer to next ith element, e.g. int i; iter+i 
       (only avaiable for container supporting random access)
       + : one iterator and one integer -> one iterator
       - : one interator and one integer -> one iterator
           one iterator and one iterator -> one integer
  *: dereference. access the element, e.g. *iter
  ->: access the member of element by iterator, e.g. iter->name (more convenient than (*iter).name)
  []: access the element by iterator, e.g. iter[-1] is the element before iter (same as *(iter-1))
  
  There are 5 iterator categories: input, output, forward, bidirectional, random-access.
  The difference between iterators are the difference of operations on iterators. 
 
  iterator adaptor
  it is a function with input container, and output iterator.
  back_inserter(v): take container v, output an iterator, can be used to append value to container.
 
(14).function as parameter
  parameter that represents a function is written as function declaration.
  void func_b(int x)
  {
    ...
  }
  void func_a(void func_b(int), int) 
  {
    ...
  } 

(15).container
  sequential container (each element stay where it is inserted): vector, list
  associative container (each element can be arranged automatically, for faster look up): map 

(16).generic/template function/class
  a function/class can work with many different types of parameters and return value.
  should add template header
  e.g. 
  template<class T> 
  T median(vector<T> v)
  {
    ...
  }    

  e.g.
  template<class T>
  class A 
  {
    A foo(A);
  }

  A<T> A<T>::foo(A<T> a)
  {
    ...
  }

  T is called type parameter.
  During compilation, compiler will emit code for that specialized type (template instantiation).
  If one calls vector<int> v; median(v); emit code for int (T == int).
  It one calls A<int> a; emit code for int (T == int).
  
  keyword "this" is a pointer to the object in member functions.
 
(17).define new type
  1.struct
    e.g.
    struct s
    {
      private:
        std::string a;
        double b;

      public:
        double f1();
        void f2(int) const;   // const means f2 will not change any data members(i.e. a,b) of this object.
    };

    // member function: return-type class/struct-name :: function-name (parameter list) { ... }
    double s::f1()          // s:: means this function f1 is a member function of s
    {
      return b;             // directly use b, to access the object's member b.
    }
    *If a function changes the state of an object, it should be a member function of that object.

  2.class
    The only difference between struct and class is the default protection.
    The default protection of struct is public, and the default protection of class is private.
    e.g.
    class s: public A           // inherit from class A, means in class s, it gets all members in class A
    {
      friend double f3(s& x);   // make a function to be "friend", means that f3() is not a member function,
                                // but can access the all member in s
      virtual double f4(s& x);  // make a function to be "virtual", means allowing dynamic binding of subclass's function
                                // to override it.

      private:
        std::string a;
        double b;
        
      public:
        s();                  // constructor
        s(const s& x);        // copy constructor (take care of copy object in passing arguments and return value)
        ~s();                 // destructor (function name: ~classname, no return value and no arguments)
                              // it will be called when local variable out of scope or explicitly call delete
        double f1();
        void f2(int) const;   // const means f2 will not change any data members(i.e. a,b) of this object.
        typedef size_t size_type; // define type in class, one can use s::size_type to express a type (i.e. size_t)
        int operator[](int i) { return i; } // define an operator([]). define operator OP, function name: operatorOP
                                            // if defined as a member function in class, the first oeprand of operator
                                            // is the object.

        operator double();    // conversion operator, define the function for how to convert this class object
                              // into a target type variable (operator T()), used where needed a double variable
                              // but provided a class s object.
        static void f5();     // make a function to be "static", means f5 belongs to class, not object.
                              // f5 cannot use any non-static members.
    };
    
    *Constructor is a kind of member function, it has no return type, and the function name is class/struct name.
    *Constructor without argument is called default constructor.
    *if a class needs a destructor, it probably needs a copy constructor and an assignment operator function.
    *polymorphism: we can use a derived type where a pointer or reference to the base type is expected.
    *dynamic binding: for function call, during run-time, accoding to the actual type of object 
                      (!! function must be called via pointer or reference to the object), to select the corresponding 
                      function to call. (work together with virtual function.)
    *static binding: for function call, during compile-time, we already know exactly which function to call.
  
    s::s(): b(0)        // : b(0)
    {

    }

(18).ifstream, ofstream (type)
  the types to read/write file.

(19).new, delete (dynamic allocation)
  new T(...) allocates an object with type T, and returns a pointer to the object.
  new T[] allocates an array of object with type T, using default constructor, and returns a pointer to the first object
  e.g.
  int *p = new int(10);
  char *s = new char[10];

  delete deallocates the object via the pointer.
  e.g.
  delete p;
  delete[] s;

(20).pointer
  a pointer can point to any object.
  e.g.
  vector<int> v;
  vector<int> *p = &v;

(21).reference (T&)
  it is another name for the same object.
  vector<int> a;
  vector<int>& b = a;

  reference as function argument will not copy the whole object,
  if don't want to change the object, use const T&.
  e.g.
  int foo(const vector<int>& v)
  {
    ... // in foo, the members in v cannot be changed.
  } 

(22).auto (c++11)
  the type of variable (the real type of variable is deduced automatically from initializer).
  e.g.
  vector<int> v;
  for(auto it = v.begin(); it != v.end(); it++)
  {
    ...
  }  
  auto x = 1;

(23).range-based for (c++11)
  define for loop over a range.
  variable loops over the element defined in expression (array, object, ...)
  for( variable : expression )
  {
    ...
  } 
  
  e.g.
  vector<int> v;
  for(int i : v)
  {
    ...
  }

(24).lambda function (c++11)
  define function using lambda expression.
  [ captured-variable-list ]( parameter-list )  { ... }
  e.g.
  auto fmax = [](int a, int b) { return a>b ? a:b; };
  int c1 = 1, c2 = 2;
  int c3 = fmax(c1, c2);  // c3 == 2.
*A good rule of thumb is to avoid more than one side effect in a single statement.
* = : (1).class A {...}  A a = b; (call corresponding constructor of class A)
      (2).A a; a = b;   (call operator= function of class A)
