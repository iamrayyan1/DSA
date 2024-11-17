// It is a technique which is used in data structure to store and retrieve data effectively

// insert, search, delete

/*
Search(worst case)
    Array: O(n)
    Linked List: O(n)
    Stack/Queue: O(n)
    Binary Tree: O(n)
    BST: O(n)
    AVL: O(logn)

Through Hashing concept we can search, insert and delete data in constant time(on average) - O(1)

Unordered map and Unordered set use this technique
*/

/*
Concept Behind Hashing:
Hashing is a process of mapping data of arbitrary size to fixed-size values (hashes) using a mathematical function called a hash function.
These hashes act as unique identifiers or "keys" for the input data, making data retrieval faster and more efficient.

Key Features of Hashing
    Hash Function:
    A hash function maps input data (called keys) to a fixed-size output (hash value).
    Example: h(x) = x % table_size
    This means that the key x is mapped to the index x % table_size in the hash table.

    Hash Table:
    A data structure used to store key-value pairs where the hash function determines the index for each key.

    Efficient Lookup:
    Hashing enables quick  data access in O(1) time on average for operations like search, insert, and delete.
*/

/*
### **Hashing: Comprehensive Notes**

---

### **What is Hashing?**
Hashing is a technique used to map large data to smaller data of fixed size (called a hash value or hash code) using a function known as a **hash function**. It enables efficient data storage, retrieval, and organization by reducing the size of the data being worked with while maintaining its uniqueness.

---

### **Key Components of Hashing**

#### 1. **Hash Function**:
- A mathematical function that converts input data (keys) into a fixed-size numerical value (hash value).
- The hash value is used as an index in a data structure like a hash table.

#### 2. **Hash Table**:
- A data structure used to store key-value pairs.
- The hash table uses the hash function to calculate the index where each key-value pair should be stored.

#### 3. **Buckets**:
- Each index in a hash table is called a bucket, which may store one or more values, especially in the case of collisions.

#### 4. **Collisions**:
- When two keys produce the same hash value, they are mapped to the same index in the hash table.
- Collisions must be handled efficiently to maintain performance.

---

### **Properties of a Good Hash Function**
1. **Deterministic**: A hash function must always produce the same hash value for the same input.
2. **Uniform Distribution**: The function should distribute keys uniformly across the hash table to minimize collisions.
3. **Fast Computation**: Hash functions should be quick to compute.
4. **Minimize Collisions**: The function should avoid mapping different keys to the same hash value.

---

### **Steps in Hashing**
1. **Data Input**: A key or value is provided.
2. **Hash Value Calculation**: The hash function computes the hash value (index).
3. **Data Storage**: The value is stored in the hash table at the calculated index.
4. **Collision Handling**: If a collision occurs, a predefined mechanism is used to resolve it.
5. **Data Retrieval**: When retrieving data, the same hash function is applied to compute the index, allowing direct access.

---

### **Collision Handling Techniques**

#### 1. **Chaining (Separate Chaining)**:
- Each bucket in the hash table contains a linked list.
- If multiple keys map to the same index, they are stored in the list.

**Advantages**:
- Simple and effective.
- Handles high load factors well.

**Disadvantages**:
- May degrade to O(n) time complexity if chains are too long.

**Example**:
```cpp
hashTable[2] -> [12] -> [22] -> [32]
```

---

#### 2. **Open Addressing**:
- All data is stored within the hash table itself.
- If a collision occurs, the next available bucket is used (based on a probing strategy).

**Probing Strategies**:
1. **Linear Probing**: Search sequentially for the next available bucket.
   - Formula: `index = (hash(key) + i) % table_size`
2. **Quadratic Probing**: Use quadratic increments to find the next bucket.
   - Formula: `index = (hash(key) + i^2) % table_size`
3. **Double Hashing**: Use a secondary hash function to determine the probing sequence.
   - Formula: `index = (hash1(key) + i * hash2(key)) % table_size`

**Advantages**:
- Eliminates the need for linked lists.

**Disadvantages**:
- Clustering can reduce performance.
- Requires careful handling when the table is nearly full.

---

#### 3. **Rehashing**:
- When the hash table becomes too full (load factor exceeds a threshold), it is resized and rehashed.
- All keys are reinserted into the new table.

**Load Factor Formula**:
\[ \text{Load Factor} = \frac{\text{Number of Elements}}{\text{Table Size}} \]

---

### **Types of Hashing**

#### 1. **Static Hashing**:
- Hash table size is fixed and does not change.
- Simple and efficient for a small, predictable dataset.

#### 2. **Dynamic Hashing**:
- Hash table size grows or shrinks dynamically as data is inserted or deleted.
- Example: Extendible Hashing and Linear Hashing.

---

### **Applications of Hashing**
1. **Data Storage and Retrieval**:
   - HashMaps, HashSets, and Dictionaries in programming.
   - Database indexing for fast query lookups.
2. **Cryptography**:
   - Hash functions like SHA-256 and MD5 are used for secure data encryption.
3. **File Systems**:
   - Hashing is used in file indexing for fast access.
4. **Load Balancing**:
   - Distribute tasks or data evenly across servers using consistent hashing.
5. **Caches**:
   - Hashing is used in cache implementations (e.g., LRU cache).

---

### **Advantages of Hashing**
1. **Fast Data Access**:
   - Provides average-case time complexity of O(1) for search, insert, and delete operations.
2. **Efficient Memory Use**:
   - Keys are distributed across the hash table, preventing clustering in memory.
3. **Versatility**:
   - Works with a wide range of data types (strings, integers, etc.).

---

### **Disadvantages of Hashing**
1. **Collisions**:
   - Poor hash functions can lead to excessive collisions and degraded performance.
2. **Memory Overhead**:
   - Space is often allocated for the entire hash table, even if not fully utilized.
3. **Complexity in Resizing**:
   - Rehashing during resizing can be computationally expensive.

---

### **Hashing in Cryptography**
- Cryptographic hash functions (e.g., SHA, MD5) are designed to ensure data integrity and security.
- Key properties:
  1. **Pre-image Resistance**: Given a hash, it should be computationally infeasible to find the original data.
  2. **Collision Resistance**: No two distinct inputs should produce the same hash.
  3. **Avalanche Effect**: A small change in input should produce a vastly different hash.

---

### **Examples of Hash Functions**

#### 1. **Modulo-Based Hashing**:
```cpp
int hashFunction(int key, int tableSize) {
    return key % tableSize;
}
```

#### 2. **Polynomial Hashing** (For Strings):
```cpp
int polynomialHash(string key, int tableSize) {
    int hash = 0;
    int p = 31; // A prime number
    int power = 1;

    for (char ch : key) {
        hash = (hash + (ch - 'a' + 1) * power) % tableSize;
        power = (power * p) % tableSize;
    }
    return hash;
}
```

---

### **Practical Hash Table Example in C++**
```cpp
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable {
    int tableSize;
    vector<list<int>> table;

public:
    HashTable(int size) : tableSize(size), table(size) {}

    int hashFunction(int key) {
        return key % tableSize;
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (int val : table[index]) {
            if (val == key) return true;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < tableSize; i++) {
            cout << "Bucket " << i << ": ";
            for (int val : table[i]) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(7);
    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);

    cout << "Hash Table: " << endl;
    ht.display();

    cout << "Searching for 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;

    ht.remove(15);
    cout << "After removing 15: " << endl;
    ht.display();

    return 0;
}
```

**Output**:
```
Hash Table:
Bucket 0:
Bucket 1:
Bucket 2:
Bucket 3: 10 20
Bucket 4:
Bucket 5:
Bucket 6: 15 7
Searching for 15: Found
After removing 15:
Bucket 0:
Bucket 1:
Bucket 2:
Bucket 3: 10 20
Bucket 4:
Bucket 5:
Bucket 6: 7
```

This example demonstrates a hash table implementation using separate chaining to handle collisions.
*/
