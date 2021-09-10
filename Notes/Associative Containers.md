# Associative Containers

## 1. Types

### 1.1 Elements Ordered by Key

`map`: Associative array; holds key-value pairs

`set`: Container in which the key is the value

`multimap`: `map` in which a key can appear multiple times

`mulset`: `set` in which a key can appear multiple times

### 1.2 Unordered Collections

`unordered_map`: `map` organized by a hash function

`unordered_set`: `set` organized by a hash function

`unordered_multimap`: Hashed `map`; keys can appear multiple times

`unordered_multiset`: Hashed `set`; keys can appear multiple times

## 2. Key Types

Using a comparison function for the key type

```c++
multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);
```

## 3. `pair` Type

header: `utility`

```c++
pair<T1, T2> p;
pair<T1, T2> p(v1, v2);
pair<T1, T2> p = {v1, v2};

make_pair(v1, v2);

p.first;
p.second;
p1 relop p2;  // > >= < <=
p1 == p2;
```

## 4. Additional Type Aliases

`key_type`: Type of the key for this container type

`mapped_type`: Type associated with each key; **map types only**

`value_type`: For `sets`, same as the `key_type`; for `maps`, `pair<const key_type, mapped_type>`

## 5. `insert` operation

```c++
c.insert(v);   		// value_type v or construct arguments
c.emplace(args);	// for map and set, return a pair; for multi- version, return an iterator

c.insert(b, e);		// return void
c.insert(il);

c.insert(p, v);
c.emplace(p, args);	 // Using iterator p as a hint for where to begin the search for where the new element should be stored. Returns an iterator
```

## 6. `erase` operation

```c++
c.erase(k); 	// Removes every element with key k from c. Returns size_type indicating the number of elements removed;
c.erase(p);		// Removes the element denoted by the iterator p from c. Return an iterator to the element after p;
c.erase(b, e);	// Removes the elements in the range denoted by the iterator pair b, e. Return e.
```

## 7. subscripting

**Only for `map` and `unordered_map` that are not const**

```c++
c[k];
c.at(k); // Checked access to the element with key k; throw an out_of_range exception if k in not in c
```

## 8. find elements

**`lower_bound` and `upper_bound` not valid for the unordered containers**

**ATTENTION: unordered container can use `equal_range`**

**Because: Elements with the same key are stored adjacent to one another in both the ordered and unordered containers.**

```c++
c.find(k);		// Returns an iterator to the first element with key k, or the off-the-end iterator
c.count(k);		// Returns the number of elements with key k.

// If k is not present, both will refer to the point at which the key can be inserted without disrupting the order
c.lower_bound(k);	// Returns an iterator to the first element with key not less than k
c.upper_bound(k); 	// Returns an iterator to the first element with key greater than k

c.equal_range(k);	// Returns a pair of iterators denoting the elements with key k. If k is not present, both members are c.end()
```

# 9. unordered container management

```c++
// Bucket Interface
c.bucket_count();		// Number of buckets in use
c.max_bucket_count();	// Largest number of buckets this container can hold
c.bucket_size(n);		// Number of elements in the nth bucket
c.bucket(k);			// Bucket in which elemetns with key k would be found

// Bucket iteration
local_iterator;			// Iterator type that can access elements in a bucket
const_local_iterator;
c.begin(n), c.end(n);	// Iterator to the first, one past the last element in bucket n
c.cbegin(n), c.cend(n);

// Hash policy
c.load_factor();		// Average number of elements per bucket. Return float.
c.max_load_factor();	// Average bucket size that c tries to maintain. c adds buckets to keep load_factor <= max_load_factor. Return float.
c.rehash(n);			// Reorganize storage so that bucket_count >= n and bucket_count > size/max_load_factor
c.reserve(n);			// Reorganize so that c can hold n elements without a rehash
```

