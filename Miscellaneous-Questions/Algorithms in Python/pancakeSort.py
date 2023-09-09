# Here is an example in Python of the pancake sorting algorithm.

def pancake_sort(arr):
    for i in range(len(arr), 1, -1):
        max_index = arr.index(max(arr[:i]))
        if max_index+1 != i:
            arr = arr[:max_index+1][::-1] + arr[max_index+1:]
            arr = arr[:i][::-1] + arr[i:]
    return arr

print(pancake_sort([3, 2, 1, 5, 4]))
