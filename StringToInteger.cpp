/**
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
Example 1:

Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.
**/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
    void left_trim(string& s){
        if (s[0] == '+' || s[0] == '-'){
            return;
        }

        for(int i =0; i< (int)s.size(); i++){
            if(s[i] == ' '){
                s.erase(i, i+1);
                i--;
            }else{
                break;
            }
        }
    }

public:
    int myAtoi(string str) {
        int n = str.size();
        left_trim(str);

        int sign = 1; 
        bool sign_flag = false;
        int start_index = 0;

        if (str[0] == '-' || str[0] == '+'){
            start_index++;
            sign_flag = true;
            if(str[0] == '-'){
                sign *= -1;
            }
        }

        if (!sign_flag && 
           (str[start_index] > '9' || str[start_index] < '0')){
            return 0;
        }

        long long sum = 0;
        for (int i = start_index; i<n; i++){
            if (str[i] > '9' || str[i] < '0'){
                break;
            }

            sum *= 10;
            sum += str[i] - '0';
			
            if (sum > INT_MAX){
                break;
            }
        }

        if (sum*sign < INT_MIN){
            return INT_MIN;
        } else if (sum*sign > INT_MAX){
            return INT_MAX;
        } else {
            return sign * sum;
        }
    }
};

int main()
{
    Solution s;

    cout<<s.myAtoi("42")<<endl;
    cout<<s.myAtoi("   -42")<<endl;
    cout<<s.myAtoi("4193 with words")<<endl;
    cout<<s.myAtoi("words and 987")<<endl;
    cout<<s.myAtoi("-91283472332")<<endl;
    cout<<s.myAtoi("91283472332")<<endl;
    cout<<s.myAtoi("   +0 123")<<endl;
    cout<<s.myAtoi("20000000000000000000")<<endl;
    
    return 0;
}
