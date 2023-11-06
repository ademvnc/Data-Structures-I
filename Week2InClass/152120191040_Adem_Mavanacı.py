import time
import numpy as np


def measure_time_and_complexity(func):
    def wrapper(*args, **kwargs):
        start_time = time.time()
        result = func(*args, **kwargs)
        end_time = time.time()
        elapsed_time = end_time - start_time
        print(f"Complexity: O(n)")
        print(f"Elapsed time: {elapsed_time} seconds")
        return result
    return wrapper


@measure_time_and_complexity
def generate_and_display_array(dimensions):
    arr = np.random.rand(*dimensions)
    print("Array elements:")
    print(arr)

# Question 1.A
generate_and_display_array((np.random.randint(1, 1000),))

# Question 1.B
generate_and_display_array((np.random.randint(1, 1000),))

# Question 2.A
generate_and_display_array((np.random.randint(1, 1000), np.random.randint(1, 1000)))

# Question 2.B
generate_and_display_array((np.random.randint(1, 1000), np.random.randint(1, 1000)))

# Question 3.A
generate_and_display_array((np.random.randint(1, 100), np.random.randint(1, 100), np.random.randint(1, 100)))

# Question 3.B
generate_and_display_array((np.random.randint(1, 100), np.random.randint(1, 100), np.random.randint(1, 100)))
