class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reserved;

        for(const auto& seat : reservedSeats){
            int row = seat[0];
            int col = seat[1];

            if (col > 1 && col < 10){
                reserved[row] |= (1 << col);
            }
        }

        int maxFamilies = (n - reserved.size()) * 2;

        for(const auto& [row, bitmask] : reserved){
            bool leftFree = (bitmask & 60) == 0;
            bool rightFree = (bitmask & 960) == 0;
            bool middleFree = (bitmask & 240) == 0;

            if (leftFree && rightFree){
                maxFamilies += 2;
            } else if (leftFree || rightFree || middleFree){
                maxFamilies += 1;
            }
        }

        return maxFamilies;
    }
};