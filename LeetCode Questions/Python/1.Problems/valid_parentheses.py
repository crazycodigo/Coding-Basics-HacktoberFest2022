# https://leetcode.com/problems/valid-parentheses/

class Solution:
  def isValid(self, s: str) -> bool:
    parentheses = []
    for i in s: 
      if i in '({[':
        parentheses.append(i)
      elif parentheses == [] and i in '}])':
        return False
      elif (i == '}' and parentheses[-1] == '{') or \
          (i == ']' and parentheses[-1] == '[') or \
          (i == ')' and parentheses[-1] == '('):
        parentheses.pop()
      else:
        return False
    if parentheses == []:
      return True
    return False
        
