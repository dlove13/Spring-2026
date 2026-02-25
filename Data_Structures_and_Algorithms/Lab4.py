#Author: Davina Love
#EECS 330
#02-24-2026


#Implement Stack

def push_Stack(arr, n):
    if len(arr) >= 7:
        print("Error stack overflow!")
        
    else: 
        arr.append(n)
        
    
def pop_Stack(arr):
    if len(arr) == 0:
        print("Error stack empty!")
    else:
        del arr[len(arr) - 1]
       

#Implement Queue

def enqueue(arr, n):
    if len(arr) >= 7:
            print("Error queue overflow")
    else:
        arr.append(n)

def dequeue(arr):
    if len(arr) == 0:
        print("Error queue empty!")
    else:
        del arr[0]

#Implement Linked List

def search_List(arr, n):
    for i in range(len(arr)):
        if arr[i] == n:
            return n
        

def prepend_List(arr, n):
    arr.insert(0,n)

def insert_List(arr, n, m):          #n = value to be inserted 
    index_m = search_List(arr,m)        #m = prepend at value
    arr.insert(index_m, n)

def delete_List(arr, n):
    index_n = search_List(arr,n)
    del arr[index_n]

#Stack Test Cases

S = []

push_Stack(S,15)
push_Stack(S,6)
push_Stack(S,2)
push_Stack(S,9)
push_Stack(S,17)
push_Stack(S,3)
push_Stack(S,8)
push_Stack(S,4) #overflow error

pop_Stack(S)
pop_Stack(S)

print(S)

#Queue Test Cases

Q = []

enqueue(Q,15)
enqueue(Q,6)
enqueue(Q,9)
enqueue(Q,8)
enqueue(Q,4)
enqueue(Q,7)
enqueue(Q,3)
dequeue(Q)
dequeue(Q)
enqueue(Q,5)
enqueue(Q,2)
enqueue(Q,12) #overflow error

print(Q)

#Linked List Test Cases

L = []

prepend_List(L,1)
prepend_List(L,4)
prepend_List(L,16)
prepend_List(L,9)
prepend_List(L,25)
search_List(L,25)
search_List(L,9)
insert_List(L,36,9)
search_List(L,25)
delete_List(L,25)

print(L)
