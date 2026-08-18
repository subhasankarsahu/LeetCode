#include<vector>
#include<unordered_map>
#include<algorithm>

class Solution {
public:
    int largestInteger(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> freq;
        for(int num : nums) {
            freq[num]++;
        }

        if(k==1) {
            int ans = -1;
            for(const auto& [num, count] : freq) {
                if(count == 1) {
                    ans = std::max(ans, num);
                }
            }
            return ans;
        }

        if(k == n) {
            return *std::max_element(nums.begin(), nums.end());
        }

        int ans = -1;
        if(freq[nums[0]] == 1) {
            ans = std::max(ans, nums[0]);
        }
        if(freq[nums[n - 1]] == 1) {
            ans = std::max(ans, nums[n - 1]);
        }
        return ans;
    }
};