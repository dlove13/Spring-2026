#Insertion Sort

def insertion_sort(arr):

    for i in range(0, len(arr)):
        key = arr[i]

        j = i-1

        while j >= 0 and key < arr[j]:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key

#Merge Sort

def merge(left, right):
    merged = [] #put sorted halves here

    i = j = 0 #initialize iterators

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            merged.append(left[i])
            i += 1
        else:
            merged.append(right[j])
            j += 1

    merged.extend(left[i:])
    merged.extend(right[j:])

    return merged

def merge_sort(arr):

    if len(arr) <= 1:
        return arr
    
    mid = len(arr) // 2 #find the mid point of the array
    left_half = merge_sort(arr[:mid])
    right_half = merge_sort(arr[mid:])

    left_sort = merge_sort(left_half)
    right_sort = merge_sort(right_half)

    return merge(left_sort, right_sort)

#Insertion Sort Test Cases
test_1 = [5, 2, 4, 6, 1, 3]
test_2 = [6, 7, 81, -96, 77, 101, -1000, 58, 66, 6.5, 13]

#Merge Sort Test Cases
test_3 = [12, 3, 7, 9, 14, 6, 11, 2]
test_4 = [4, 1, 2, 3, 0, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]

#Run Insertion Sort
insertion_sort(test_1)
insertion_sort(test_2)

#Run Merge Sort
merge_sort(test_3)
merge_sort(test_4)

#Print results to console
print("Test 1 sorted: ", test_1)
print("Test 2 sorted: ", test_2)

print("Test 3 sorted: ", test_3)
print("Test 4 sorted: ", test_4)

