import numpy as np


def read_matrix(rows, cols, name):
    matrix = []

    print(f"Enter elements of {name}. Enter each row in one line separated by space:")

    for i in range(rows):
        while True:
            row = list(map(float, input(f"Row {i + 1}: ").split()))

            if len(row) == cols:
                matrix.append(row)
                break

            print(f"Please enter exactly {cols} values.")

    return np.array(matrix)


rows_first = int(input("Enter number of rows for first matrix: "))
cols_first = int(input("Enter number of columns for first matrix: "))

rows_second = int(input("Enter number of rows for second matrix: "))
cols_second = int(input("Enter number of columns for second matrix: "))

if rows_first <= 0 or cols_first <= 0 or rows_second <= 0 or cols_second <= 0:
    print("Matrix dimensions must be positive.")
elif cols_first != rows_second:
    print("Matrix multiplication is not possible.")
else:
    first_matrix = read_matrix(rows_first, cols_first, "first matrix")
    second_matrix = read_matrix(rows_second, cols_second, "second matrix")
    result = np.matmul(first_matrix, second_matrix)
    print("First matrix:")
    print(first_matrix)

    print("Second matrix:")
    print(second_matrix)

    print("Result:")
    print(result)