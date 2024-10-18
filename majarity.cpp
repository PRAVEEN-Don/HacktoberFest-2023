#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate = nums[0], count = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == candidate) {
            count++;
        } else {
            count--;
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            }
        }
    }

    // Phase 2: Verify the candidate
    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }

    return count > nums.size() / 2 ? candidate : -1;
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

    int result = majorityElement(nums);
    if (result != -1) {
        cout << "The majority element is: " << result << endl;
    } else {
        cout << "No majority element found." << endl;
    }

    return 0;
}
