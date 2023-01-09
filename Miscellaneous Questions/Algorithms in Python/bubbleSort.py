# This is a demonstration of the bubblesort algorithm in Python without using any libraries.
# TODO: This needs more test cases to confirm this is the best solution

def bubblesort (arr):
	# loop through entire array
	for i in range(len(arr)):
		# loop through array up to the i-th element
		for j in range(len(arr)-1):
			# compare elements
			if arr[j] > arr[j+1]:
				# swap elements
				temp = arr[j]
				arr[j] = arr[j+1]
				arr[j+1] = temp
	return arr

# testing
my_array = [3,2,1,5,4]
print(bubblesort(my_array))