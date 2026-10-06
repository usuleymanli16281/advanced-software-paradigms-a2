# Task 3 — Matrix Multiplication

## Introduction
This task implements the matrix multiplication using two approaches: **NumPy arrays in Python** and **C++** . Both implementation allow different sizes of matrices. The user enters the size of the matrix as well as the elements of the matrix. The C++ implementation does matrix multiplication manually while the Python implementation uses the numpy function matmul(). Unit tests are used also to check the correctness of the C++ implementation. The comparison of the two implementations is made considering **code size** and **execution time**.

## Implementation

### NumPy Implementation
In the Python implementation, the matrices are stored in NumPy arrays. Before multiplication, the program checks that the dimensions are positive and that the number of columns of the first matrix equals the number of rows of the second matrix.
The multiplication is performed using:
```python
result = np.matmul(first_matrix, second_matrix)
```
### C++ Implementation
The C++ code uses vector<vector<double>> to allow the matrix size to change based on what the user enters. This makes the program flexible since the size is not fixed. Matrix multiplication is done manualy with three loops. For each position in the result matrix we take one row from the matrix and one column from the second matrix. We multiply the matching elements from that row and column then add all those products to get the final value.

## Unit Testing
Unit tests were written for the C++ implementation to verify that the multiplication function correctly works  for different type of matrices.
There were three cases tested:
- **Rectangular matrices:** verifies that the implementation handles non-square matrices.
- **Negative and decimal values:** tests that the function handles correcly negative and floating point numbers.
- **Identity matrix:** checks that multiplying a matrix by an identity matrix gives the original matrix.

The tests use the same `multiplyMatrices()` function as the main C++ program.

## Code Size Analysis
The code size of the NumPy and C++ implementations was compared using the number of source-code lines and the source file size. The number of lines was obtained directly from the source files in the editor. The file size was measured using the following PowerShell commands:

```powershell
(Get-Item matrix_numpy.py).Length
(Get-Item matrix_cpp.cpp).Length
```
The results were:

| Implementation | Lines of Code | File Size |
|---|---:|---:|
| NumPy | 43 | 1338 bytes |
| C++ | 97 | 2495 bytes |

The NumPy implementation has fewer lines of code and is smaller in file size. The main reason is that matrix multiplication can be done using the built in `np.matmul()` function, so most of the multiplication logic is taken care of internally by the NumPy library.
C++ implementation requires more code because matrix storage, input, multiplication and output are handled explicitly. Multiplication can be done manually with nested loops as well.
Thus, the NumPy solution is more concise while C++ implementation has more explicit control over the multiplication process.

## Execution Time Analysis
The execution time of both implementations was tested using square matrices of sizes `100×100`, `300×300`, and `500×500`.
For each matrix size, one multiplication was performed before measurement as a warm-up. The multiplication was then executed 20 times, and the average execution time was calculated. Matrix creation, user input, and output were not included in the measured time.
The results were:
| Matrix Size | NumPy Average Time | C++ Average Time |
|---|---:|---:|
| 100 × 100 | 0.000190 s | 0.000948192 s |
| 300 × 300 | 0.001252 s | 0.0347309 s |
| 500 × 500 | 0.004450 s | 0.124797 s |
In this experiment, the NumPy implementation produced lower execution times than the manual C++ implementation for all three matrix sizes. The main reason is that `np.matmul()` uses optimized numerical routines internally, while the C++ implementation performs matrix multiplication directly using three nested loops.
As the matrix size increased, the execution time of both implementations also increased. This is expected because standard matrix multiplication using three nested loops has approximately cubic time complexity, `O(n³)`.


## ChatGPT Implementation and Prompting
After completing my own implementation, I asked ChatGPT to implement the same task with NumPy and C++. In the first prompt, ChatGPT provided me with NumPy and C++ implementations with unit tests. However, the matrices and their dimensions were hard coded. I asked ChatGPT to check if the number of columns of the first matrix is equal to the number of row of the second matrix. It added and explained this validation for both implementations. Then I asked to validate matrix dimensions so that rows and columns cannot be negative or zero. It explained that matrix dimensions should be greater than zero and added the necessary validation. C++ solution was still using fixed matrices so I asked to make the implementation dynamic so that the user could enter both matrix dimensions and matrix values. ChatGPT updated C++ implementation so that the user could enter the matrix dimensions and values and validted them before calculating the product. Finally, I asked to update the NumPy implementation in the same way. The final NumPy solution allowed user to enter the dimensions and values of both matrices checked that all dimensions are greater than zero that the matrices are compatible for multiplication and used `np.matmul()` to calculate the result. The prompting process allowed me to update the initial solution step by step until it met the requirements of the task.
ChatGPT conversation:  
https://chatgpt.com/share/6ac4c1e1-f69c-83ed-80c0-1d65b213618d

## How to Run
All programs can be run from the `task3/code` directory.
### NumPy Implementation
```powershell
pip install numpy
```
Then run the program:
```python
python matrix_numpy.py
```
### C++ Implementation
Compile the C++ program:
```powershell
g++ matrix_cpp.cpp -o matrix_cpp
```
Then run it
```powershell
.\matrix_cpp.exe
```
### C++ Unit Tests
Compile the unit tests:
```powershell
g++ matrix_tests.cpp -o matrix_tests
```
Then run it
```powershell
.\matrix_tests.exe
```
### Benchmarks
Run the NumPy benchmark:

```powershell
python benchmark_numpy.py
g++ -O2 benchmark_cpp.cpp -o benchmark_cpp
.\benchmark_cpp.exe
```

## Conclusion
In this task, matrix multiplication was implemnted using NumPy and C++. Both implementations allow the user to enter different matrix size and value and check whether the matrices are compatible for multiplication.
The NumPy implementation required less code because the multiplication is performed using `np.matmul()` while C++ implementation perform the multiplication manually using three nested loops. The execution time results also showed that the NumPy implementation was faster than manual C++ implemenation in the performed experiments.
Unit tests were used to verify the correctness of the C++ implementation with rectangular matrices, negative and decimal values and an identity matrix. Overall, this task showed the differences between using a optimized numerical library and implementing matrix multiplication manualy.

## References
Visual Studio Marketplace. (n.d.). *C++ Unit Test*.  
https://marketplace.visualstudio.com/items?itemName=AutumnMoon.cpp-unit-test

GeeksforGeeks. (n.d.). *Measure execution time of a function in C++*.  
https://www.geeksforgeeks.org/cpp/measure-execution-time-function-cpp/