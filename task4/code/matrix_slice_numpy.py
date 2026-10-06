import numpy as np


def read_matrix(rows, cols):
    matrix = []

    print("Enter matrix elements. Enter each row in one line separated by space:")

    for i in range(rows):
        while True:
            row = list(map(float, input(f"Row {i + 1}: ").split()))

            if len(row) == cols:
                matrix.append(row)
                break

            print(f"Please enter exactly {cols} values.")

    return np.array(matrix)


rows = int(input("Enter number of rows: "))
cols = int(input("Enter number of columns: "))

if rows <= 0 or cols <= 0:
    print("Matrix dimensions must be positive.")
else:
    matrix = read_matrix(rows, cols)

    row_start = int(input("Enter starting row index: "))
    row_end = int(input("Enter ending row index: "))
    col_start = int(input("Enter starting column index: "))
    col_end = int(input("Enter ending column index: "))

    if (
        row_start < 0 or row_end > rows or
        col_start < 0 or col_end > cols or
        row_start >= row_end or
        col_start >= col_end
    ):
        print("Invalid slice boundaries.")
    else:
        sliced_matrix = matrix[row_start:row_end, col_start:col_end]

        print("Original matrix:")
        print(matrix)

        print("Sliced matrix:")
        print(sliced_matrix)