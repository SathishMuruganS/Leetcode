/**
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        
        int arr1_length = nums1.size();
        int arr2_length = nums2.size();
        int j = 0;
        int i = 0;
        
        while (i < arr1_length && j < arr2_length){
			if (nums1[i] < nums2[j]) {
				ans.push_back(nums1[i]);
				i++;
			} else if (nums1[i] > nums2[j]) {
				ans.push_back(nums2[j]);
				j++;
			} else {
				ans.push_back(nums1[i]);
				ans.push_back(nums2[j]);
				i++;
				j++;
			}
		}
		
		while (i < arr1_length){
			ans.push_back(nums1[i]);
			i++;
		}
		
		while (j < arr2_length){
			ans.push_back(nums2[j]);
			j++;
		}
		
		int n = ans.size()/2;
		
		if ((n > 0) && (ans.size()%2) == 0){
			double val = ((ans[n-1] + ans[n])/2.0);
			return  (double) val;
		} else {
			return double(ans[n]/1.0);
		}
		
        
    }
};

int main()
{
	Solution s;
	vector<int> nums1{1, 3};
	vector<int> nums2{2};
	vector<int> nums3{1, 2};
	vector<int> nums4{3,4};
	vector<int> nums5{};
	vector<int> nums6{1};
	vector<int> nums7{};
	vector<int> nums8{2,3};
	
	cout<<s.findMedianSortedArrays(nums1, nums2)<<endl;
	cout<<s.findMedianSortedArrays(nums3, nums4)<<endl;
	cout<<s.findMedianSortedArrays(nums5, nums6)<<endl;
	cout<<s.findMedianSortedArrays(nums7, nums8)<<endl;
	
	return 0;
}


