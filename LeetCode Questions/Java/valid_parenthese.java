// 20. Valid Parentheses

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
//Link- https://leetcode.com/problems/valid-parentheses/

//Explanation
// we will iterate from 1st character to last charcter
//if the character is opening bracket like '(','{', or '[', push it into stack
//if the character is not opening bracket and stack is empty, so its invalid.  we return false
//if the character is not opening bracket and stack is not empty, we will check stacks top char is opening bracket(stack only contain opening bracket) of same type as 
//closing character found while iteration, if yes, pop it from stack
//else return false
//once the iteration completes, we will check if stack is empty or not.
// if stack empty return true, else false
 

class Solution {
    public boolean isValid(String s) {
        char [] ch= s.toCharArray();
        Stack<Character> st=new Stack<>();
        for(int i=0;i<ch.length;i++){
            if(ch[i]=='(' || ch[i]=='[' || ch[i]=='{'  ){
                st.push(ch[i]);
            }
            else if (st.isEmpty()) return false;
            else if (ch[i]==')' && st.peek()=='(' ) st.pop();
             else if (ch[i]=='}' && st.peek()=='{' ) st.pop();
             else if (ch[i]==']' && st.peek()=='[' ) st.pop();
            else return false;
        }
        if(st.isEmpty())
        return true;
        
        return false;
    }
}

