class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> counter;
        for (int num : nums) {
            counter[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
            minHeap;
        for (auto& entry : counter) {
            minHeap.push({entry.second, entry.first});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // Step 3: Extract k most frequent elements
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};