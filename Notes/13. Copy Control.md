# Copy Control

## 1. Definition

**copy constructor**: first parameter is a reference to the class type and any additional parameters have default values

**copy-assignment operator**

**destructor**

**move constructor**

**move-assignment operator**

## 2. Copy Constructor

A constructor is the copy constructor if its first parameter is a reference to the class type and any additional parameters have default values.

```c++
class Foo {
public:
    Foo();
    Foo(const Foo&);
    ...
};
```

almost always a reference to `const`, usually should not be explicit

### 2.1 copy initialization

**direct initialization**: use ordinary function matching to select the constructor

**copy initialization**: copy the right hand operand into the object being created, converting that operand if necessary
Requires either *copy constructor* or the *move constructor*

**Happens**:

1. Define variables using an `=`
2. Pass an object as an argument to a parameter of nonreference type
3. Return an object from a function that has nonreference return type
4. Brace initialize the elements in an array or the members of an aggregate class

Can not use a copy initialization when the constructor is `explicit`

## 3. Copy-assignment operator

The copy-assignment operator takes an argument of the same type as the class.

```c++
class Foo {
public:
	Foo& operator= (const Foo&);
    ...
};
```

## 4. Destructor

Destructor is a member function with the name of the class prefixed by a tilde(~). It has no return value and takes no parameters

```c++
class Foo {
public:
    ~Foo();
    ...
};
```

## 5. The rule of three/five

1. Classes that need destructors need copy and assignment

2. If a class needs a copy constructor, it almost surely needs a copy-assignment operator and vice versa. 

   Needing either the copy constructor or the copy-assignment operator does not (necessarily) indicate the need for a destructor.

## 6. Preventing Copies

### 6.1 Deleted function

`= delete`

The destructor should not be a deleted member

#### 6.1.1 Synthesized deleted function

1. Synthesized deleted destructor:
   - a member with a deleted or inaccessible **destructor**
2. Synthesized deleted copy constructor:
   - a member with a deleted or inaccessible **copy constructor**
   - a member with a deleted or inaccessible **destructor**
3. Synthesized deleted copy-assignment operator:
   - a member has a deleted or inaccessible **copy-assignment operator**
   - a `const` or reference member
4. Synthesized deleted default constructor:
   - a member with a deleted or inaccessible **destructor**
   - a reference member that does not have an in-class initializer
   - a `const` member whose type does not explicitly define a default constructor and doesn't have an in-class initializer
5. Synthesized deleted move operation:
   - a member defines its own copy constructor but does not also define a move constructor
   - a member doesn't define its own copy operations and for which the compiler is unable to synthesize a move constructor
   - a member whose own move constructor or move-assignment operator is deleted or inaccessible
   - **move constructor**: the destructor is deleted or inaccessible
   - **move-assignment operator**: has a `const` or reference membet

## 7. `swap`

`friend` declaration

`using std::swap`, then use `swap`

## 8. moving objects

### 8.1 rvalue reference

1. return lvalue:

   Functions that return lvalue reference, assignment, subscript, dereference, prefix increment/decrement operators, examples of expressions

2. return rvalue:

   Functions that return a nonreference type, arithmetic, relational, bitwise, postfix increment/decrement operators

using `std::move` to obtain an rvalue reference bound to an lvalue.

`move` function in header `utility`

### 8.2 move iterator

move iterator adapts its given iterator by changing the behavior of the iterator's deference operator.

the dereference operator of a move iterator yields an rvalue reference

`make_move_iterator(begin())`

### 8.3 rvalue and lvalue reference member functions

`Foo &oerator=(const Foo&) const &;`
