/**
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
**/




#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;

        for(int i = 0; i< n; i++){
            if(s[i] == '[' || s[i] == '(' || s[i] == '{'){
                st.push(s[i]);
            }else {
                if(!st.empty() &&
                  ((s[i] == ']' &&  st.top() == '[') ||
                   (s[i] == ')' && st.top() == '(') ||
                   (s[i] == '}' && st.top() == '{'))){
                    st.pop();
                } else {
                    return false;
                }
            }
        }
		
        if (st.empty()){
            return true;
        }

        return false;
    }
};

int main()
{
	Solution s;
	cout<<s.isValid("()")<<endl;
	cout<<s.isValid("()[]{}")<<endl;
	cout<<s.isValid("([)]")<<endl;
	cout<<s.isValid("(]")<<endl;
	cout<<s.isValid("{[]}")<<endl;
	
	return 0;
}
