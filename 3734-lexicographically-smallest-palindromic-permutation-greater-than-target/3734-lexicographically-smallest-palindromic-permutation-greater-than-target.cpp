#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        vector<int> count(26, 0);
        for(char c : s) {
            count[c - 'a']++;
        }
        
        int oddCount = 0;
        string mid_char = "";
        vector<int> half_count(26, 0);
        
        for(int i = 0; i < 26; ++i) {
            if(count[i] % 2 != 0) {
                oddCount++;
                mid_char = string(1, i + 'a');
            }
            half_count[i] = count[i] / 2;
        }
        
        if(oddCount > 1) return "";
        
        int n = s.length();
        int L = n / 2;
        
        for(int i = L; i >= 0; --i) {
            vector<int> pref_count(26, 0);
            bool possible = true;
            
            for(int j = 0; j < i; ++j) {
                pref_count[target[j] - 'a']++;
            }
            
            for(int c = 0; c < 26; ++c) {
                if(pref_count[c] > half_count[c]) {
                    possible = false;
                    break;
                }
            }
            
            if(!possible) continue;
            
            vector<int> rem_count(26, 0);
            for(int c = 0; c < 26; ++c) {
                rem_count[c] = half_count[c] - pref_count[c];
            }
            
            if(i == L) {
                string P = target.substr(0, L);
                string rev_P = P;
                reverse(rev_P.begin(), rev_P.end());
                string pal = P + mid_char + rev_P;
                
                if(pal > target) return pal;
            } else {
                char best_c = 0;
                for(int c = target[i] - 'a' + 1; c < 26; ++c) {
                    if(rem_count[c] > 0) {
                        best_c = c + 'a';
                        rem_count[c]--;
                        break;
                    }
                }
                
                if(best_c != 0) {
                    string P = target.substr(0, i) + best_c;
                    for(int c = 0; c < 26; ++c) {
                        P += string(rem_count[c], c + 'a');
                    }
                    string rev_P = P;
                    reverse(rev_P.begin(), rev_P.end());
                    
                    return P + mid_char + rev_P;
                }
            }
        }
        
        return "";
    }
};