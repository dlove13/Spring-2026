# Author: Davina Love
# Date: 02-04-2026
# EECS 330

# AI Disclaimer: Copilot and Gemini were utilized in the debugging of this document,
#     specifically to prevent unncessary recursion calls that were causing infinite loops
#     and crashing the program.

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

    while i < len(left) and j < len(right):     #compares values and determines which one is lesser than
        if left[i] <= right[j]:                 #then appends to the merged list
            merged.append(left[i])              
            i += 1
        else:
            merged.append(right[j])
            j += 1

    merged.extend(left[i:])                     #safeguard to make sure all elements have been
    merged.extend(right[j:])                    #accounted for

    return merged                               #output sorted halves

def merge_sort(arr):

    if len(arr) <= 1:   #base case once the list is already sorted
        return arr
    
    mid = len(arr) // 2 #find the mid point of the array
    left_half = merge_sort(arr[:mid])    #recursively call the merge_sort to keep dividing the array
                                            #in half 
    right_half = merge_sort(arr[mid:])

    return merge(left_half, right_half)  #output fully sorted list

# #Insertion Sort Test Cases
test_1 = [5, 2, 4, 6, 1, 3]
test_2 = [6, 7, 81, -96, 77, 101, -1000, 58, 66, 6.5, 13]

# #Merge Sort Test Cases
test_3 = [12, 3, 7, 9, 14, 6, 11, 2]
test_4 = [4, 1, 2, 3, 0, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]

# #Run Insertion Sort
insertion_sort(test_1)
insertion_sort(test_2)

#Run Merge Sort
test_3 = merge_sort(test_3)
test_4 = merge_sort(test_4)

# #Print results to console
print(f"Test 1 sorted: {test_1}")
print(f"Test 2 sorted: {test_2}")

print(f"Test 3 sorted: {test_3}")
print(f"Test 4 sorted: {test_4}")

