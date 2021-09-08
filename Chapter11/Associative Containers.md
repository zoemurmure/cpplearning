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

