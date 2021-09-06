# Algorithms

headers: `algorithm`, `numeric`

```c++
find(b, e, val);  // return an iterator
count(b, e, val);
accumulate(b, e, val); // type of val determines which addition operator is used and is the type of return value
fill(b, e, val);
replace(b, e, val1, val2);
sort(b, e);
sort(b, e, predicate); // binary predicate
stable_sort(b, e);
stable_sort(b, e, predicate);  // binary predicate
unique(b, e); // return an iterator that denotes the end of the range of the unique values
partition(b, e, predicate);  // unary predicate
stable_partition(b, e, predicate); // unary predicate
find_if(b, e, predicate);  // unary predicate
for_each(b, e, callable); // unary 
count_if(b, e, predicate); // unary predicate

// using a single iterator denoting a sequence
equal(b1, e1, b2);
fill_n(b, size, val);
copy(sb, se, db);
replace_copy(sb, se, db, val1, val2);
transform(sb, se, db, callable); // unary 
unique_copy(sb, se, db);

```

---

header: `iterator`

```c++
auto it = back_inserter(vec);
```

