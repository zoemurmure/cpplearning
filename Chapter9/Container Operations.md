# Container Operations

## 1. Access

### 1.1 Iterator

`iterator`: Type of the iterator for this container type

`const_iterator`: Iterator type that can read but not change its elements

`c.begin()`, `c.end()`: Return iterator to the first, one past the last element in `c`

`c.cbegin()`, `c.cend()`: Return `const_iterator`

---

**not valid for `forward_list`**

`reverse_iterator`: Iterator that addresses elements in reverse order

`const_reverse_iterator` Reverse iterator that cannot write the elements

`c.rbegin()`, `c.rend()`: Return iterator to the last, one past the first element in `c`

`c.crbein()`, `c.crend()`: Return `const_reverse_iterator`

### 1.2 access

`c.back()`: Returns a reference to the last element in `c`. **not valid for `forward_list`**

`c.front()`: Returns a reference to the first element in `c`

---

**not valid for `list`, `forward_list`**

`c[n]`: Returns a reference to the element indexed by the unsigned integral value `n`.

`c.at(n)`: Returns a reference to the element indexed by `n`.

## 2. Type Aliases

`size_type`: **Unsigned** integral type big enough to hold the size of the largest possible container of this container type.

`difference_type`: **Signed** integral type big enough to hold the distance between two iterators

`value_type`: Element type

`reference`: Element's lvalue type; synonym for `value_type&`

`const_reference`: Element's const lvalue type(i.e., `const value_type&`)

## 3. Construction

`C c`: Default constructor, empty container

`C c1(c2)`

`C c1 = c2`: Construct `c1` as a copy of `c2`

`C c{a,b,c...}`

`C c = {a,b,c...}`: `c` is a copy of the elements in the initializer list

`C c(b, e)`:  Copy elements from the range denoted by iterators `b` and `e`. **not valid for array**

---

**valid for sequential containers(not including array) only**

`C seq(n)`

`C seq(n, t)`

## 4. Change Content

**most of them not valid for `array`**

### 4.1 assignment and swap

`c1 = c2`: Replace elements in `c1` with those in `c2`

`c1 = {a,b,c...}`: Replace elements in `c1` with those in the list **(not valid for array)**

`a.swap(b)`: Swap elements in `a` with those in `b`

`swap(a, b)`: Equivalent to `a.swap(b)`

### 4.2 `assign`

*not valid for associative containers or **array***

`seq.assign(b, e)`: Replaces elements in `seq` with those in the range denoted by iterators `b` and `e`. The iterators `b` and `e` must not refer to elements in `seq`.

`seq.assign(il)`: Replaces the elements in `seq` with those in the initializer list `il`.

`seq.assign(n, t)`: Replaces the elements in `seq` with `n` elements with value t.

### 4.3 Add elements

`c.push_back(t)`: append an element to the back of a sequential container 

`c.emplace_back(args)`

**not valid for `array` and `forward_list`**

---

`c.push_front(t)`: insert a new element at the front of the container

`c.emplace_front(args)`

**not valid for `array`, `vector`, `string` **

---

`c.insert(p, t)`   `c.emplace(p, args)`

`c.insert(p, n, t)`

`c.insert(p, b, e)`

`c.insert(p, il)`

Insert element(s) before the position denoted by the `p` iterator.

**`forward_list`** has special versions, **not valid for `array`**

### 4.4 Erasing elements

`c.pop_back(t)`: remove last element of a sequential container 

**not valid for `array` and `forward_list`**

---

`c.pop_front(t)`: remove first element of the container

**not valid for `array`, `vector`, `string` **

---

`c.erase(p)`: Remove element denoted by the iterator `p`.

`c.erase(b, e)`: Removes the range of elements denoted by the iterators `b` and `e`.

`c.clear()`: Remove all elements from `c`; returns `void`

## 5. size & capacity

### 5.1 size

`c.size()`: Number of elements in `c` (**not valid for forward_list**)

`c.max_size()`: Maximum number of elements `c` can hold

`c.empty()`: `false` if `c` has any elements, `true` otherwise

### 5.2 resize

`c.resize(n)`: Resize `c` so that it has `n` elements

`c.resize(n ,t)`

### 5.3 capacity

**valid for `vector`, `string`, `deque`**

`c.shrink_to_fit()`: Request to reduce `capacity()` to equal `size()`

---

**valid for `vector`, `string`**

`c.capacity()`: Number of elements `c` can have before reallocation is necessary

`c.reserve(n)`: Allocate space for at least `n` elements

## 6. Equality and Relational Operations

`==`, `!=`: Equality valid for all container types

`<`, `<=`, `>`, `>=`: Relational (**not valid for unordered associative containers**)

## 7. Specialized `forward_list` Operations

```c++
lst.before_begin();
lst.cbefore_begin();

lst.insert_after(p, t);
lst.insert_after(p, n, t);
lst.insert_after(p, b, e);
lst.insert_after(p, il);

emplace_aftert(p, args);

lst.erase_after(p);
lst.erase_after(b, e);
```

## 8. Additional `string` Operations

### 8.1 construct

```c++
string s(cp, n);  // s is a copy of the first n characters in the array to which cp points
string s(s2, pos2); // s is a copy of the characters in the string s2 starting at the index pos2
string s(s2, pos2, len2);
```

### 8.2 `substr`

`s.substr(pos, n)`

Return a `string` containing `n` characters from `s` starting at `pos`.

`pos` defaults to 0. `n` default to a value that causes the library to copy all the characters in `s` starting from `pos`.

### 8.3 Change contents

```c++
s.erase(pos, len);

s.assign(args);  // can use all forms of args
s.append(args);  // can use all forms of args

s.insert(pos, args);
s.insert(iter, args);
s.replace(pos, len, args)
s.replace(b, e, args);
```

```text
args:
str
str, pos, len
cp
cp, len
n, c
b, e
initialize list
```

### 8.4 search

```c++
s.find(args);
s.rfind(args);
s.find_first_of(args);   // Find the first occurrence of any character from args in s
s.find_last_of(args);
s.find_first_not_of(args); // Find the first character in s that is not in args
s.find_last_not_of(args);
```

```text
args:
c, pos
s2, pos
cp, pos
cp, pos, n
```

### 8.5 compare

```text
s.compare(args)

args:
	s2
	pos1, n1, s2
	pos1, n1, s2, po2, n2
	cp
	pos1, n1, cp
	pos1, n1, cp, n2
```

### 8.6 Numeric conversions

```c++
// 需要加std::
to_string(val);  // Return the string representation of val
stoi(s, p, b);   // Return the initial substring of s that has numeric content as an int
// p: a point to a size_t in which to put the index of the first nonnumeric character in s
// b: numeric base to use for the conversion
stol(s, p, b);   // long
stoul(s, p, b);  // unsigned long
stoll(s, p, b);  // longlong
stoull(s, p, b); // unsigned long long

stof(s, p);		// float
stod(s, p);		// double
stold(s, p);	// long double

```

## 9. Container Adaptors

`stack`, `queue`, `priority_queue`

### 9.1 common operations and types

```text
size_type	
value_type
container_type	Type of the underlying container on which the adaptor is implemented
A a;		Create a new empty adaptor named a
A a(c);		Create a new adaptor named a with a copy of the container c
relational operators	
a.empty()	
a.size()
swap(a, b)
a.swap(b)
```

### 9.2 specific operations

`stack`:  default implemented in terms of `deque`

can use any containers except from `array` and `forward_list`

```c++
s.pop();
s.push(item);
s.emplace(args);
s.top();
```

`queue`: default implemented in terms of `deque`, can also use `list`, `vector`

`priority_queue`:  default implemented in terms of `vector`, can also use `deque`

```c++
q.pop();
q.front();  // only for queue
q.back();   // only for queue
q.top();    // only for priority_queue
q.push(item);
q,emplace(args);
```

