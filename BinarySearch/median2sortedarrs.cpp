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

    double ans = Solution :: findMedainSortedArrays(nums1, nums2);
    std :: cout << "Ans is : " << ans;
}