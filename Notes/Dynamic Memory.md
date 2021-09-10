# Dynamic Memory

## 1. Operations

### 1.1 Common to `shared_prt` and `unique_ptr`

```c++
shared_ptr<T> sp; 	
unique_ptr<T> up;	// Null smart pointer that can point to objects of type T
p;		// Use p as a conditon, true if p points to an object
*p;		// Dereference p to get the object to which p points
p->mem;	// Synonym for (*p).mem
p.get();	// Return the pointer in p. Use with caution; the object to which the returned pointer points will disappear when the smart pointer delete it
swap(p, q);	// Swaps the pointers in p and q
p.swap(q);
```

Notice the difference between `p.get()` and `p`. `p.get()` is a pointer, `p` is a `shared_ptr`/`unique_ptr`.

### 1.2 Specific to `shared_ptr`

```c++
make_shared<T>(args);	// Returns a shared_ptr pointing to a dynamically allocated object of type T. Uses args to initialize that object
shared_ptr<T> p(q);		// p is a copy of shared_ptr q; increments the count in q. The pointer in q must be convertible to T*
p = q;		// p and q are shared_ptrs holding pointers that can be converte to one another. Decrements p's existing memory if p's count goes to 0;
p.unique();	// Returns true if p.use_count() is one; false otherwise
p.use_count();		// Returns the number of objects sharing with p; may be a slow operation, intended primarily for debugging purpose
```

**Q: When does reference count increase?**

A: 1. use a `shared_ptr` to initialize another `shared_ptr`; 2. use it as the right-hand operand of an assignment; 3. pass it to or return it from a function by value.

**Q: Why use dynamic memory?**

A: 1. don't know how many objects they'll need; 2. don't know the precise type of objects the need; 3. want to share data between several objects.

### 1.3 other ways to define and change `shared_ptr`

```c++
shared_ptr<T> p(q);		// p manages the object to which the build-in pointer q points; q must point to memory allocated by new and must be convertible to T*;
shared_ptr<T> p(u);		// p assumes ownership from the unique_ptr u; make u null.
shared_ptr<T> p(q, d);	// p assumes ownership for the object to which the built-in pointer q points. p will use the callable object d in place of delete to free q.
shared_ptr<T> p(p2, d);	// p is a copy of shared_ptr p2. p uses the callable object d in place of delete

p.reset();		// p.use_count()==1 -> free;  make p null
p.reset(q);		// make p point to q, use delete to free q
p.reset(q, d);	// call d to free q
```



## 2. new & delete

### 2.1 initialize

1. default initialize: `int *pi = new int;`
2. direct initialize: `int *pi = new int(1024);`
3. value initialize: `int *pi = new int();`

### 2.2 placement new

header: `new`

A placement new expression lets us pass additional arguments to `new`

Prevent `new` from throwing an exception: `new (nothrow) int`, if fails, return null pointer.

### 2.3 three common problems

1. Forgetting to `delete` memory;
2. Using an object after it has been deleted;
3. Deleting the same memory twice.
