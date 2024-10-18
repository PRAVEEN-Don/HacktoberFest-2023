#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end()); // Sort the array to use two-pointer technique

    for (int i = 0; i < nums.size(); i++) {
        // Avoid duplicates for the first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1; // Start pointer
        int right = nums.size() - 1; // End pointer
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                // Move left and right to the next different numbers
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                left++;
                right--;
            } else if (sum < 0) {
                left++; // We need a larger sum
            } else {
                right--; // We need a smaller sum
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums;
    int n, input;

    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> input;
        nums.push_back(input);
    }

    vector<vector<int>> triplets = threeSum(nums);

    cout << "Unique triplets that sum to zero are:\n";
    for (const auto& triplet : triplets) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
    }

    return 0;
}
