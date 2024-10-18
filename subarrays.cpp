#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subarraysDivByK(vector<int>& A, int K) {
    unordered_map<int, int> remainderCount;
    remainderCount[0] = 1; 
    int count = 0;
    int prefixSum = 0;

    for (int num : A) {
        prefixSum += num;
        int remainder = ((prefixSum % K) + K) % K; 

        
        if (remainderCount.find(remainder) != remainderCount.end()) {
            count += remainderCount[remainder];
        }

        
        remainderCount[remainder]++;
    }

    return count;
}

int main() {
    vector<int> A = {4, 5, 0, -2, -3, 1}; 
    int K = 5; // Example K value
    int result = subarraysDivByK(A, K);
    cout << "Number of subarrays divisible by " << K << " is: " << result << endl;
    return 0;
}
