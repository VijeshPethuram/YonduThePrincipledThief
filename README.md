# Yondu The Principled Thief
Yondu - The Principled Thief Problem (Solved using Linked List in C)

Question:
Mr.Yondu is trying to steal some code from the Code Bank Of
Anonymous. He has a key with an integer value printed on it.
He also has N other keys with each key having its own specific
value. He is trying to break the Lock for which he is supposed
to get to the lock's key value. He can perform one type of
operation. Take his own key and one of the other N keys and
merge them. During merging his Key value changes to product
of both the keys modulus 100000.

For example if his key value was X and he took a key with
value Y the his new key will be (X*Y)%100000. The other key
that was used during the merging process remains along with
other N-1 keys.

This entire process of merging takes 1 second. Now since he is
in a hurry he asks to you to find the minimum time in which he
could reach to the lock’s key value.

Input format

* The first line contains 2 integers, they are Mr. Yondu’s key value and the Lock's key value.

+ The second line contains N indicating the number of other keys Mr. Yondu has.

Note:
Though this program is written in C language, it is complied using C++ compiler. So you don't need to worry about the file extension. 
