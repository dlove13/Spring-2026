#Author Davina Love
#EECS 330
#02 Feb 2026



#Recursive Binary Search

def BinarySearch(arr, num, low, high):
    if (low > high):
        return "NIL"
    mid = (low + high) // 2
    if num == arr[mid]:
        return mid
    elif num > arr[mid]:
        return BinarySearch(arr, num, mid + 1, high)
    else:
        return BinarySearch(arr,num, low, mid - 1)
        

#Test Arrays
arr1 = [3,5,7,8,9,12,15]
arr2 = [10,11,12,13,14,15,16,17,18,19,20]

#Test Output
findNine = BinarySearch(arr1, 9, 0, len(arr1) - 1)
findThirteen = BinarySearch(arr2, 13, 0, len(arr2) - 1)

print(f"Index of searched element 9: {findNine}")
print (f"Array: {arr2}\nIndex of 13: {findThirteen}")



#Recursive Matrix Multiplication

def MatrixMultiplication(A, B, n):
    C = [[0 for i in range (0,n)] for j  in range(0,n)]
    for i in range (0, n):
        for j in range (0, n):
            for k in range (0,n):
                C[i][j] += A[i][k] * B[k][j]
    return C

#Test Matrices
mat_1 = [[5,2,6,1],
         [0,6,2,0],
         [3,8,1,4],
         [1,8,5,6]]

mat_2 = [[7,5,8,0],
         [1,8,2,6],
         [9,4,3,8],
         [5,3,7,9]]

mat_3 = [[1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
         [0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
         [0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0],
         [0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0],
         [0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0],
         [0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0],
         [0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0],
         [0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0],
         [0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0],
         [0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0],
         [0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0],
         [0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0],
         [0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0],
         [0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0],
         [0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0],
         [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1]]     

mat_4 = [[4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6],
         [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
         [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
         [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
         [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
         [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
         [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
         [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
         [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
         [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
         [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
         [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
         [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
         [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
         [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
         [9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7]]


#Test Matrix Multiplication
result1 = MatrixMultiplication(mat_1, mat_2, 4);
result2 = MatrixMultiplication(mat_3, mat_4, 16);


print(f"{result1}")
print(f"{result2}")

