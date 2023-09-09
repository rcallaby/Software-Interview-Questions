
def selectionSort(list):
    for i in range(len(list)):
        # Find the minimum element in the list
        min_index = i
        for j in range(i+1, len(list)):
            if list[min_index] > list[j]:
                min_index = j
        # Swap the minimum element with the first element
        list[i], list[min_index] = list[min_index], list[i]
    return list


list = [3, 6, 8, 2, 1, 10, 4]
print("List before sorting: ", list)
sorted_list = selectionSort(list)
print("List after sorting: ", sorted_list)