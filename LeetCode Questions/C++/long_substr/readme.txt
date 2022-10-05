This solution is of problem :
https://leetcode.com/problems/longest-substring-without-repeating-characters/

Here the idea is whenever we find any character which is repeating itself then just take the previous position where it was and find the difference of those two place... maximum of those distances is your answer

And how can we find previous position? just use something like hashmap function...