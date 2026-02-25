#Author: Davina Love
#EECS 330
#02-24-2026
#Source Disclaimer: Geeksforgeeks.org was used as reference for the implementation and debugging
#of the structures listed below


#Implement Stack

def push_Stack(arr, n):
    if len(arr) >= 7:
        print("Error stack overflow!")              #Throw error if stack is full
                                                    #isFull if length is greater than 7 elements
    else: 
        arr.append(n)
        
    
def pop_Stack(arr):
    if len(arr) == 0:
        print("Error stack empty!")                 #Throw error if stack is empty
    else:
        del arr[len(arr) - 1]
       

#Implement Queue

def enqueue(arr, n):
    if len(arr) >= 7:
            print("Error queue overflow")           #Throw error if queue is full
    else:                                           #isFull if length is greater than 7 elements
        arr.append(n)

def dequeue(arr):
    if len(arr) == 0:
        print("Error queue empty!")                 #Throw error if queue is empty
    else:
        del arr[0]

#Implement Linked List
class Node:                                         #Instatiate node class
        def __init__(self, data = None):
            self.data = data    
            self.next = None                        #Ptr to next linked node
            self.prev = None                        #Ptr to previous linked node

class DoublyLinkedList:

    def __init__(self):
        self.head = None
        
    def List_Search(self, n):
        x = self.head                  #Init head of list

        while x is not None and x.data != n:
            x = x.next
        return x

    def List_Prepend(self, n):          #Insert element at the beginning of list
                                        #New element becomes the head
        node = Node(n)

        node.next = self.head
        node.prev = None

        if self.head is not None:
            L.head.prev = node
        self.head = node

    def List_Insert(self, n, y):              #Inserts element n into list after existing element y
        node = Node(n)

        node.next = y.next
        node.prev = y

        if y.next is not None:
            y.next.prev = node
        y.next = node

    def List_Delete(self, n):              #Remove element n from list L
        if n.prev is not None:
            n.prev.next = n.next
        else: L.head = n.next

        if n.next is not None:
            n.next.prev = n.prev

    def Print_List(self):                   #Print list starting from head
        if self.head is None:               #Check if list is empty
            print("Empty List")
            return
        
        curr = self.head
        
        while curr:
            print(f"{curr.data} <->", end=" ")      #Formatting
            curr = curr.next
        print("None")


#Stack Test Cases

S = []

print("Start Stack Test Cases\n")
pop_Stack(S)                #Throw underflow error
push_Stack(S,15)
push_Stack(S,6)
push_Stack(S,2)
push_Stack(S,9)
push_Stack(S,17)
push_Stack(S,3)
push_Stack(S,8)

print(f"{S}")

push_Stack(S,4)             #Throw overflow error

pop_Stack(S)
pop_Stack(S)

print(f"{S} \n")

#Queue Test Cases

Q = []                      #Create new Queue

print("Start Queue Test Cases\n")

dequeue(Q)                  #Throw underflow error
enqueue(Q,15)
enqueue(Q,6)
enqueue(Q,9)
enqueue(Q,8)
enqueue(Q,4)
enqueue(Q,7)
enqueue(Q,3)

print(f"{Q}")                 

dequeue(Q)
dequeue(Q)
enqueue(Q,5)
enqueue(Q,2)
enqueue(Q,12) #overflow error

print(f"{Q}\n")

#Linked List Test Cases

L = DoublyLinkedList()

print("Start Linked List Test Cases")

L.List_Prepend(1)
L.List_Prepend(4)
L.List_Prepend(16)
L.List_Prepend(9)
L.List_Prepend(25)

L.Print_List()

L.List_Insert(36, L.List_Search(9))
L.List_Insert(12, L.List_Search(1))

L.Print_List()

L.List_Delete(L.List_Search(4))
L.List_Delete(L.List_Search(12))
L.List_Delete(L.List_Search(25))

L.Print_List()


