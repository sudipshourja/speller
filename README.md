# Enhancing a Spell Checker using Hash Tables

## Abstract

This project is a development of a spell-checking program, "Speller," leveraging the efficiency of hash tables. The project aims to implement a high-performance spell checker with optimized loading, checking, and unloading processes. The report details the methodologies employed, the impact of hash table size on performance, and the achieved efficiency.

## 1. Introduction

### 1.1 Background

Spell checking is a fundamental task in text processing, integral to various applications such as word processors and web browsers. The objective of this project is to design a spell-checking program that not only ensures correctness but also emphasizes speed and memory efficiency.

### 1.2 Objectives

- Implement a spell checker using hash tables.
- Optimize the loading, checking, and unloading processes.
- Evaluate the performance impact of hash table size on the spell checker.

## 2. Methodology

### 2.1 Hash Table Implementation

A hash table is employed to store the dictionary efficiently. A robust hash function is designed to minimize collisions and distribute words evenly across the table.

### 2.2 Loading Process

The `load` function reads the dictionary file, calculates hash values, and inserts words into the hash table. The number of buckets (`N`) is a configurable parameter for balancing space and time complexity.

### 2.3 Checking Process

The `check` function utilizes a case-insensitive search to determine whether a word is correctly spelled. This function ensures the spell checker is versatile and user-friendly.

### 2.4 Unloading Process

The `unload` function efficiently frees memory, addressing any potential memory leaks and ensuring the program's reliability.

### 2.5 Performance Analysis

Performance metrics are obtained using the `getrusage` function. Various hash table sizes are tested using a large dictionary file (`dictionaries/large`) and a substantial text file (`texts/holmes.txt`).

## 3. Results

### 3.1 Load, Check, and Unload Times at Different Hash Table Sizes

| Hash Table Size (N) | Load Time (s) | Check Time (s) | Unload Time (s) |
|----------------------|---------------|-----------------|------------------|
| 100                | 0.09          | 101.75          | 0.03             |
| 1000               | 0.13          | 12.56           | 0.02             |
| 10000              | 0.09          | 4.23            | 0.03             |

## 4. Discussion

### 4.1 Optimization Strategies

- A carefully designed hash function for efficient distribution.
- Adjustment of the hash table size (`N`) to find an optimal balance.
- Implementation of a case-insensitive search for user-friendly spell checking.

### 4.2 Performance Analysis

The results demonstrate the trade-offs between hash table size and load/check times. Smaller tables show quicker load times but slower checks, while larger tables strike a balance between the two.

## 5. Conclusion

The Speller project successfully achieves an efficient spell checker through the use of hash tables and optimization strategies. The performance analysis underscores the impact of hash table size on overall efficiency, providing valuable insights for real-world applications.

## 6. Acknowledgments

We extend our gratitude to the course instructors for their guidance and support. Special thanks to online resources that contributed to the understanding of hash table implementations.
