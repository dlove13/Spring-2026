import random

#Implement Quicksort

def Random_Quicksort(arr,low,high):
    if low < high:
        p = Random_Partition(arr,low,high)
        Random_Quicksort(arr,low,p-1)
        Random_Quicksort(arr,p+1,high)
    
def Random_Partition(arr, low, high):
    random_index = random.randint(low,high)
    arr[random_index], arr[high] = arr[high], arr[random_index]

    return Partition(arr,low,high)

def Partition(arr,low,high):
    pivot = arr[high]
    i = low - 1

    for j in range(low,high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i+1], arr[high] = arr[high], arr[i+1]

    return i+1
        
        
#Implement Heapsort

def Heapsort(arr):
    n = len(arr)

    for i in range(n//2 - 1, -1, -1):
        Max_Heapify(arr,n,i)
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        Max_Heapify(arr,i,0)

def Max_Heapify(arr,n,i):
    
    left = 2 * i + 1
    right = 2 * i + 2
    largest = i

    if left < n and arr[left] > arr[largest]:
        largest = left

    if right < n and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        Max_Heapify(arr,n,largest)

#Quicksort Test cases

test_1 = [2,8,7,1,3,5,6,4]
test_2 = [54,10,27,38,57,51,30,23,26,16,25,12,93,13,43,40
 ,60,7,95,97,58,8,100,96,45,36,74,90,3,62,67]

#Heapsort Test cases
test_3 = [4,1,3,2,16,9,10,14,8,7]
test_4 = [23, 38, 11, 41, 49, 53, 10, 98, 94, 96, 97, 88, 26, 54, 60]

#Output Tests
print(f"Quicksort")
print(f"Original: {test_1}")
Random_Quicksort(test_1, 0, len(test_1) - 1)
print(f"Sorted: {test_1}")

print(f"Original: {test_2}")
Random_Quicksort(test_2, 0, len(test_2) - 1)
print(f"Sorted: {test_2}")

print(f"Heapsort")
print(f"Original: {test_3}")
Heapsort(test_3)
print(f"Sorted: {test_3}")

print(f"Original: {test_4}")
Heapsort(test_4)
print(f"Sorted: {test_4}")

