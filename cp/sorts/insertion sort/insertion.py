def insertion_sort(arr):
    for i in range(1, len(arr)):
        j = i-1
        key = arr[i]
        while j >= 0 and arr[j] > key:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key


arr = [3, 21, 6, 35, 7, 0]
print(arr)
insertion_sort(arr)
print(arr)
