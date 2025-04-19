#include<iostream>
#include<vector>
#include<iterator>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
public:
    // APPROACH 1 : USING SET DS, T.C. O(NlogN) | S.C. O(N)
    static int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int count = 1, length = 1;
        set<int> s;
        for(int i : nums) { s.insert(i); }
        set<int> :: iterator i = s.begin(), j = next(i, 1);
        while(j != s.end()){
            if((*j)-(*i) == 1){
                count+=1;
                length = (count > length) ? count : length;
            }
            else
                count = 1;
            i++, j++;
        }
        return length;
    }

    // APPROACH 2 : USING unordered_set DS, T.C. O(N) | S.C. O(N)
    static int longestConsecutive2(vector<int>& nums) {
        if(!nums.size()) return 0;
        int longest = 1;
        unordered_set<int> s;
        for(int i : nums) { s.insert(i); }
        unordered_set<int> :: iterator it = s.begin();
        for(auto it : s){
            if(s.find(it-1) == s.end()){
                int x = it;
                int count = 1;
                while(s.find(x+1) != s.end())
                    count++, x++;
                longest = max(longest, count);
            }
        }
        return longest;
    }
};
int main() {
    int range;
    vector<int> nums;
    cout << "Enter range : ";
    cin >> range;
    for(int i = 0; i<range; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    int ans = Solution :: longestConsecutive2(nums);
    cout << "Ans is : " << ans << endl;
}