/**
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
**/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()){
            return "";
        }

        if (strs.size() == 1){
            return strs[0];
        }

        int max_size = strs[0].size();
        string max_str = "";

        for(auto ii: strs){
            max_size = min(max_size, (int)ii.size());
        }

        for(int i = 0; i < max_size; i++){
            string sub_str1 = strs[0].substr(0,i+1);
            int count = 0;
            for(int j = 1; j < (int)strs.size(); j++){
                string sub_str2 = strs[j].substr(0,i+1);
                if(sub_str1 == sub_str2){
                    count++;
                }
            }

            if (count == ((int)strs.size()-1)){
                max_str = sub_str1;
            }
        }
        return max_str;
    }
};

int main()
{
    Solution s;
    vector<string> strs{"flower","flow","flight"};
    vector<string> strs2{"dog","racecar","car"};
    vector<string> strs3{""};
    vector<string> strs4{"a"};
    vector<string> strs5{"a","a"};
    vector<string> strs6{"a","b"};
	
    cout<<s.longestCommonPrefix(strs)<<endl;
    cout<<s.longestCommonPrefix(strs2)<<endl;
    cout<<s.longestCommonPrefix(strs3)<<endl;
    cout<<s.longestCommonPrefix(strs4)<<endl;
    cout<<s.longestCommonPrefix(strs5)<<endl;
    cout<<s.longestCommonPrefix(strs6)<<endl;
    return 0;
}
