class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;
        for(auto& n : s){
            if(!s.count(n-1)){
                int cur = n;
                int len =1;
                while(s.count(cur+1)){
                    cur++;
                    len++;
                }
                longest = max(len,longest);
            }
        }    
        return longest;
    }
};
