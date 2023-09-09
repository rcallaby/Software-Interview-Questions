# This is an example of a tournament sort algorithm

def tournament_sort(arr):
    n = len(arr)
    for i in range(0, n, 2):
        if i+1 < n and arr[i] > arr[i+1]:
            arr[i], arr[i+1] = arr[i+1], arr[i]
    if n > 2:
        tournament_sort(arr[:n//2])
        tournament_sort(arr[n//2:])
    return arr

arr = [3, 4, 2, 1, 6, 5, 7, 8]
print(tournament_sort(arr)) # [1, 2, 3, 4, 5, 6, 7, 8]

