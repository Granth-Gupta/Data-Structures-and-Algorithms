#include <iostream>
#include <vector>

bool subsetSum(const std::vector<int>& nums, int target) {
    int n = nums.size();

    // Create a 2D vector to store the subset sum states
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(target + 1, false));

    // Base cases
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // Build the subset sum table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
            if (j < nums[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    return dp[n][target];
}

int main() {
    std::vector<int> nums = {3, 34, 4, 12, 5, 2};
    int target = 9;

    bool hasSubsetSum = subsetSum(nums, target);

    if (hasSubsetSum) {
        std::cout << "Subset with the given sum exists." << std::endl;
    } else {
        std::cout << "No subset with the given sum exists." << std::endl;
    }

    return 0;
}
