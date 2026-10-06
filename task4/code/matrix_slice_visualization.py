import numpy as np
import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle


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

        fig, axes = plt.subplots(1, 2, figsize=(12, 6))

        axes[0].imshow(matrix)

        for i in range(rows):
            for j in range(cols):
                axes[0].text(j, i, matrix[i, j], ha="center", va="center")

        rectangle = Rectangle(
            (col_start - 0.5, row_start - 0.5),
            col_end - col_start,
            row_end - row_start,
            fill=False,
            linewidth=3,
            edgecolor="black"
        )

        axes[0].add_patch(rectangle)

        axes[0].set_xticks(range(cols))
        axes[0].set_yticks(range(rows))
        axes[0].set_xlabel(f"Selected columns: {col_start}:{col_end}")
        axes[0].set_ylabel(f"Selected rows: {row_start}:{row_end}")
        axes[0].set_title(f"Original Matrix\nSlice: matrix[{row_start}:{row_end}, {col_start}:{col_end}]")

        axes[1].imshow(sliced_matrix)

        for i in range(sliced_matrix.shape[0]):
            for j in range(sliced_matrix.shape[1]):
                axes[1].text(j, i, sliced_matrix[i, j], ha="center", va="center")

        axes[1].set_xticks(range(sliced_matrix.shape[1]))
        axes[1].set_yticks(range(sliced_matrix.shape[0]))
        axes[1].set_title("Sliced Matrix")

        plt.tight_layout()
        plt.savefig("matrix_slice_result.png")
        plt.show()