str1=input("Enter a text")
vowel_count=0
for ch in str1:
    if ch in ['a','e','i','o','u','A','E','I','O','U']:
        vowel_count+=1
print(vowel_count,end=' ')
