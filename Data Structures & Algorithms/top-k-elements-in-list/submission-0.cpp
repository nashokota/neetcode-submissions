class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>minHeap;
        for(auto& i : nums){
            cnt[i]++;
        }
        for(auto& i: cnt){
            minHeap.push({i.second, i.first});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }

        vector<int>res(k);
        for(int i=k-1;i>=0;i--){
            res[i] = minHeap.top().second;
            minHeap.pop();
        }
        return res;
    }
};
