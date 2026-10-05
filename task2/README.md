# Task 2 — Memory Size of Python Tuple and List

## Introduction
This experiment compares the memory size of a tuple and a list in Python with the same values. The difference between two data strutures is found by `__sizeof__()` method.

## Experiment
The experiment was performed using **Python 3.14.6**.

A tuple and list containing same three integer values are created

```python
tpl = (1, 2, 3)
lst = [1, 2, 3]
tpl.__sizeof__()
lst.__sizeof__()
```

## Results and Explanation
The experiment produced the following result:

| Data Structure | `__sizeof__()` |
|---|---:|
| Tuple `(1, 2, 3)` | 56 bytes |
| List `[1, 2, 3]` | 72 bytes |

The reason is basically that a **tuple is immutable**. Meaning that once created, it cannot change its size. So Python can only allocate memory for the tuple and references to its elements.

A **list** is mutable and can grow during program execution in contrast. Python allocates additional memory for lists so that new element can be added without reallocating memory after every insertion. This extra alocated space increases the memory used by the list (GeeksforGeeks, 2025).
The __sizeof__() method returns the memory used by the tuple or list object itself. It does not recursively include the memory used by the integer objects `1`, `2` and `3`. 

## Conclusion
The experiment shows the `tuple` used 56 bytes and `list` used 72 bytes in `Python 3.14.6`. Both had the same values but the list was more memory intensive as it supports dynamic resizing and keep extra space alocated for future elements. Tuple is immutable and of fixed size so it uses less memory for same elements.

## References
GeeksforGeeks. (2025, July 23). *Memory management in lists and tuples using Python*. https://www.geeksforgeeks.org/python/memory-management-in-lists-and-tuples-using-python/
