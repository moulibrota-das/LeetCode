We can apporoach this is in a better way if we know a very interesting behaviour of bits i.e
for any number n
n&(n-1) will clear the last setbit of n.
eg: 5 = 101 5&4= 100
7 = 111 7&6= 110
6 = 110 6&5= 100
​
Algorithm:
Let the answer be stored in count vector
​
We know answer for 0 is 0
Traverse for all elements from 1 to n and for each element number of bits will be 1 + count[i&(i-1)];
But how?
Reason: on i&(i-1) we counted the last set bit of i , now we just need to count the setbits in i&(i-1).
And we know i&(i-1) < i which means we have already calculated the result earlier.