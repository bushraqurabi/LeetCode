#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++; 
        }

        vector<vector<int>> b(nums.size() + 1);
        for (auto& p : freq) {
            b[p.second].push_back(p.first);
        }

       
        vector<int> result;
        for (int i = b.size() - 1; i >= 0 && result.size() < k; i--) {
            for (int num : b[i]) {
                result.push_back(num);
                if (result.size() == k)
                    break;
            }
        }

        return result;
    }
};
