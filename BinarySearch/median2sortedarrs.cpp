#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
class Solution{
public:
    // APPROACH 1 : brute force
    static void merge(std :: vector<int>& nums1, std :: vector<int>& nums2, std :: vector<int>& comb, int& s1, int& s2){
        int i = 0, j = 0;
        while(i < s1 && j < s2){
            if(nums1[i] <= nums2[j]){
                comb.push_back(nums1[i]);
                i++;
            }
            else{
                comb.push_back(nums2[j]);
                j++;
            }
        }
        while(i < s1){
            comb.push_back(nums1[i]);
            i++;
        }
        while(j < s2){
            comb.push_back(nums2[j]);
            j++;
        }
    }

    static double findMedainSortedArrays(std :: vector<int>& nums1, std :: vector<int>& nums2){
        int s1 = nums1.size(), s2 = nums2.size(), ts = s1 + s2, mid = ts/2;
        double median = 0;
        std :: vector<int> comb;
        std :: cout << "Going to merge array" << std :: endl;
        merge(nums1, nums2, comb, s1, s2);
        std :: cout << "Merged array is : " << std :: endl;
        for(const auto& it : comb){
            std :: cout << it << " ";
        }
        std :: cout << std :: endl;
        if(ts % 2 == 0){
            median = (comb[mid] + comb[mid - 1])/2.0;
        }
        else{
            median = comb[mid];
        }
        return median;
    }
    static double findMedainSortedArrays2(std :: vector<int>& nums1, std :: vector<int>& nums2){
        int n1 = nums1.size(), n2 = nums2.size(), leftLen = (n1 + n2 + 1)/2;
        int low = 0, high = std :: min(n1, n2);
        while(low <= high){
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            int mid1 = high - (high - low)/2;
            int mid2 = leftLen - mid1;
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];
            if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];
            if(l1 <= r2 && l2 <= r1)
                return ((n1 + n2)%2 == 0)? (double)((std :: max(l1, l2) + std :: min(r1, r2))/2.0) : std :: max(l1, l2);
            
            else if(l1 > r2 && l2 < r1)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
    }
};
int main(){
    int s1, s2;
    std :: vector<int> nums1, nums2;
    std :: cout << "Enter range of nums1 : ";
    std :: cin >> s1;
    std :: cout << "Enter range of nums2 : ";
    std :: cin >> s2;
    std :: cout << "Enter elements in Array1 : " << std :: endl;
    for(int i = 0; i<s1; i++){
        int num;
        std :: cin >> num;
        nums1.push_back(num);
    }
    std :: cout << "Enter elements in Array2 : " << std :: endl;
    for(int i = 0; i<s2; i++){
        int num;
        std :: cin >> num;
        nums2.push_back(num);
    }

    double ans = Solution :: findMedainSortedArrays2(nums1, nums2);
    std :: cout << "Ans is : " << ans;
}