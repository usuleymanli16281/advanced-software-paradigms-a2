import numpy as np
import time

sizes = [100, 300, 500]
runs = 20

for size in sizes:
    first = np.ones((size, size))
    second = np.ones((size, size))

    np.matmul(first, second)

    total_time = 0

    for _ in range(runs):
        start = time.perf_counter()

        result = np.matmul(first, second)

        end = time.perf_counter()
        total_time += end - start

    average_time = total_time / runs

    print(f"{size}x{size}: {average_time:.6f} seconds")