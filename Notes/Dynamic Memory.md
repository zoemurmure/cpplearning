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

Because q is a build-in pointer, it can points to an object that doesn't has a delete operation. So we can set a deleter in reset function.

### 1.4 specific to `unique_ptr`

```c++
unique_ptr<T> u1;		// u1 will use delete to free its pointer
unique_ptr<T,D> u2;		// u2 use a callable object of type D to free its pointer
unique_ptr<T,D> u(d);	// u use d, which must be an object of type D in place of delete

u = nullptr;	// Deletes the object to which u points, makes u null
u.release();	// Relinquishes control of the pinter u had held; returns the pointer u had held and makes u null

u.reset();			// Delete the object to which u points.
u.reset(q);			// make u point to built-in pointer q
u.reset(nullptr;)	// make u null
```

`unique_ptr` does not support ordinary copy or assignment, but we can copy or assign a `unique_ptr` that is about to be destroyed.

### 1.5 `unique_ptr` points to arrays

```c++
unique_ptr<T[]> u;		// u can point to a dynamically allocated array of type T
unique_ptr<T[]> u{p};	// u points to the dynamically allocated array to which the built-in pointer p points. p must be convertible to T*
u[i];					// Returns the object at position i in tha array that u owns. u must point to an array.
```

### 1.6 operations for `weak_ptr`

```c++
weak_ptr<T> w;
weak_ptr<T> w(sp);

w = p;		// p can be a weak_ptr or a shared_ptr.

w.reset();		// make w null
w.use_count();
w.expired();	// return true if w.use_count() is zero
w.lock();		// if expired is true, returns a null shared_ptr; otherwise returns a shared_ptr to the object to which w points.
```

### 1.7 `allocator`

```c++
allocator<T> a;		// Defines an allocator object named a that can allocate memory for objects of type T.
p = a.allocate(n);	// Allocates raw, unconstructed memory to hold n objects of type T.
a.construct(p, args);	// p must be a pointer to type T that points to raw memory; args are passed to a constructor for type T, which is used to construct an object in the memory pointed to by p.
a.destroy(p);		// Runs the destructor on the object pointed to by the T* pointer p.
a.deallocate(p, n);	// Deallocates memory that held n objects of type T starting at the address in the T* pointer p; p must be a pointer previously returned by allocate, and n must be the size requested when p was created. The user must run destroy on any objects that were constructed in this memory before calling deallocate.
```

#### 1.7.1 construct algorithm

```c++
unintialized_copy(b, e, b2);	// copy from (b,e) to b2
unintialized_copy_n(b, n, b2);
uninitialized_fill(b, e, t);	// construct objects in the range of raw memory denoted by iterators b and e as a copy of t
uninitialized_fill_n(b, n, t);	
```

return its (incremented) destination iterator

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

