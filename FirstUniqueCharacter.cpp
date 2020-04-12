/**
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.


**/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
		int result = -1;
        int n = s.size();
        
        if (n == 1) return 0; 
        for(int i =0;i<n-1;i++){
			bool flag = true;
			for(int j = 0; j<n; j++){
				if(i == j) continue;
				if (s[i] == s[j]){
					flag = false;
					break;
				}
			}
			if (flag){
				return i;
			}
		}
        return result;
    }
};


int main()
{
	Solution s;
	cout<<s.firstUniqChar("leetcode")<<endl;
	cout<<s.firstUniqChar("loveleetcode")<<endl;
	cout<<s.firstUniqChar("cc")<<endl;
	cout<<s.firstUniqChar("c")<<endl;
	cout<<s.firstUniqChar("aadadaad")<<endl;
	
	
	return 0;
}
