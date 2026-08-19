class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> seats;
        // Store reserved seats row-wise
        for (auto &x : reservedSeats) {
            int row = x[0];
            int pos = x[1];
            seats[row].push_back(pos);
        }
        int count = 2 * n;
        for (auto &p : seats) {
            bool left = true;
            bool middle = true;
            bool right = true;

            for (int pos : p.second) {
                // left = seats 2-5
                if (pos >= 2 && pos <= 5) {
                    left = false;
                }
                // middle = seats 4-7
                if (pos >= 4 && pos <= 7) {
                    middle = false;
                }
                // right = seats 6-9
                if (pos >= 6 && pos <= 9) {
                    right = false;
                }
            }
            // Initially this row was counted as 2
            if (left && right) {
                continue;
            }
            else if (left || middle || right) {
                // Only 1 family possible
                count--;
            }
            else {
                // No family possible
                count -= 2;
            }
        }
        return count;
    }
};