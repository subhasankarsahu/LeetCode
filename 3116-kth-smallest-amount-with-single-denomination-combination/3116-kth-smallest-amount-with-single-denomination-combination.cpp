class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        
        vector<pair<long long, int>> lcm_list;
        for (int i = 1; i < (1 << n); ++i) {
            long long current_lcm = 1;
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    current_lcm = std::lcm(current_lcm, (long long)coins[j]);
                    count++;
                }
            }
            lcm_list.push_back({current_lcm, count});
        }
        
        auto count_amounts = [&](long long x) {
            long long res = 0;
            for (const auto& p : lcm_list) {
                if (p.second % 2 == 1) { 
                    res += x / p.first;
                } else {                 
                    res -= x / p.first;
                }
            }
            return res;
        };
        
        long long low = 1;
        long long high = (long long)*min_element(coins.begin(), coins.end()) * k;
        long long ans = high;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (count_amounts(mid) >= k) {
                ans = mid;       
                high = mid - 1;
            } else {
                low = mid + 1;   
            }
        }
        
        return ans;
    }
};