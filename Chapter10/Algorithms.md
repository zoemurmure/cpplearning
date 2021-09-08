# Algorithms

headers: `algorithm`, `numeric`

Parameter Patterns:

```c++
alg(beg, end, other args);
alg(beg, end, dest, other args);
alg(beg, end, beg2, other args);
alg(beg, end, beg2, end2, other args);
```



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
unique(b, e, predicate); // binary predicate
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

---

## List-specific algorithm

```c++
lst.merge(lst2);
lst.merge(lst2, comp);

lst.remove(val);
lst.remove_if(pred);

lst.sort();
lst.sort(comp);

lst.unique();
lst.unique(pred);

lst.splice(p, lst2);
lst.splice(p, lst2, p2);
lst.splice(p, lst2, b, e);
flst.splice(args)
```

