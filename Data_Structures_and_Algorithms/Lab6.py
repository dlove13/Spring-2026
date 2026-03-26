#Implement collision resolution by open addressing table using
#double hashing

#Hash function
# h(k,i) = (h1((k) + h2(k)) mod m

#Define hash functions
def h1(k,m):
    return k % m
def h2_case1(k):
    return 1 + (k % 11)
def h2_case2(k):
    return 5 - (k % 5)

#Hash-Insert
#T = Hash Table, k = key, m = table size
def Hash_Insert(T, k, m, case = 1):
    for i in range(m):
        if case == 1:
            index = (h1(k,m) + i * h2_case1(k)) % m
        else:
            index = (h1(k,m) + i * h2_case2(k)) % m

        if T[index] is None:
            T[index] = k
            return index
    return "Table is Full"
            

#Hash-Search
# T = Hash Table, k = key, m = table size
def Hash_Search(T, k, m, case=1):
    for i in range(m):
        if case == 1:
            index = (h1(k,m) + i * h2_case1(k)) % m
        else:

            index = (h1(k,m) + i * h2_case2(k)) % m

        if T[index] == k:
            return index

    return "NIL"

#Test Cases
#Case 1: m = 13, h1(k) = k mod 13 and h2(k) = 1 + (k mod 11)
#Insert keys 79, 69, 72, 50, 98, 14 in order
#Print hashtable as array, empty slot = NIL
#Search for keys 14(exists) and 66(DNE) and print indices

Hash_Table_1 = [None] * 13
keys_1 = [79, 69, 72, 50, 98, 14]

for key in keys_1:
    Hash_Insert(Hash_Table_1, key, len(Hash_Table_1), 1)

print(f"Hash Table Case 1: {Hash_Table_1}")
print(f"Index of 14: {Hash_Search(Hash_Table_1, 14, len(Hash_Table_1), 1)}")
print(f"Index of 66: {Hash_Search(Hash_Table_1, 66, len(Hash_Table_1), 1)}")

#Case 2 m = 7, h1(k) = k mod 7 and h2(k) = 5 - (k mod 5)
#Insert keys 10, 82, 40, 35, 15, 21, 52 in order
#Print hashtable as array, empty slot = NIL
#Search for keys 52(exists) and 11 (DNE) and print indices


Hash_Table_2 = [None] * 7
keys_2 = [10, 82, 40, 35, 15, 21, 52]

for key in keys_2:
    Hash_Insert(Hash_Table_2, key, len(Hash_Table_2) , 2)

print(f"Hash Table Case 2: {Hash_Table_2}")
print(f"Index of 52: {Hash_Search(Hash_Table_2, 52, len(Hash_Table_2), 2)}")
print(f"Index of 11: {Hash_Search(Hash_Table_2, 11, len(Hash_Table_2), 2)}")
