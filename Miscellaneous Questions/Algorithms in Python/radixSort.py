# Radix Sort Algorithm

# Function to get the max number in the list
# TODO: This has some errors that need to be corrected
def getMax(arr): 
	maxNum = arr[0] 
	for i in range(1, len(arr)): 
		if arr[i] > maxNum: 
			maxNum = arr[i] 
	return maxNum 

# Function to do counting sort of the array according to the digit represented by the exp (10^exp)
def countingSort(arr, exp): 

	# Create a count array to store the count of each unique object
	count = [0] * (10) 

	# Store the count of each unique object
	for i in range(0, len(arr)): 
		index = ( (arr[i]/exp) ) 
		count[ (index)%10 ] += 1

	# Change count[i] so that count[i] now contains actual 
	# position of this digit in output array 
	for i in range(1,10): 
		count[i] += count[i-1] 

	# Build the output array 
	output = [0] * (len(arr)) 
	for i in range(len(arr)-1, -1, -1): 
		index = (arr[i]/exp) 
		output[ count[ (index)%10 ] - 1] = arr[i] 
		count[ (index)%10 ] -= 1

	# Copying the output array to arr[], 
	# so that arr now contains sorted numbers 
	for i in range(0,len(arr)): 
		arr[i] = output[i] 

# Function to do Radix Sort
def radixSort(arr): 

	# Get maximum number in arr[] 
	maxNum = get(arr) 

	# Do counting sort for every digit. Note that instead 
	# of passing digit number, exp is passed. exp is 10^i 
	# where i is current digit number 
	exp = 1
	while maxNum/exp > 0: 
		countingSort(arr,exp) 
		exp *= 10


arr = [170, 45, 75, 90, 802, 24, 2, 66] 
radixSort(arr) 

print("Sorted array is") 
for i in range(len(arr)): 
	print(arr[i]),

# Output:
# Sorted array is
# 2 24 45 66 75 90 170 802