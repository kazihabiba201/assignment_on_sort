#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdlib> 

// Function to partition the array for Quickselect
int partition(std::vector<int>& nums, int low, int high) {
    int pivot = nums[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (nums[j] <= pivot) {
            ++i;
            std::swap(nums[i], nums[j]);
        }
    }
    std::swap(nums[i + 1], nums[high]);
    return i + 1;
}

// Quickselect 
int quickselect(std::vector<int>& nums, int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = low + std::rand() % (high - low + 1);
        std::swap(nums[pivotIndex], nums[high]);
        int partitionIndex = partition(nums, low, high);

        if (partitionIndex == k) {
            return nums[partitionIndex];
        } else if (partitionIndex < k) {
            return quickselect(nums, partitionIndex + 1, high, k);
        } else {
            return quickselect(nums, low, partitionIndex - 1, k);
        }
    }
    return -1; // Should not be reached if k is valid
}

// Function to find the kth largest element
int findKthLargest(std::vector<int>& nums, int k) {
    int n = nums.size();
    int kthLargestIndex = n - k; // Convert kth largest to kth smallest index
    return quickselect(nums, 0, n - 1, kthLargestIndex);
}

// Function to parse input and convert to vector of integers
std::vector<int> parseInput(const std::string& input) {
    std::vector<int> nums;
    std::string trimmedInput = input;
    trimmedInput.erase(std::remove(trimmedInput.begin(), trimmedInput.end(), '['), trimmedInput.end());
    trimmedInput.erase(std::remove(trimmedInput.begin(), trimmedInput.end(), ']'), trimmedInput.end());
    trimmedInput.erase(std::remove(trimmedInput.begin(), trimmedInput.end(), ' '), trimmedInput.end());
    
    std::istringstream stream(trimmedInput);
    std::string item;
    while (std::getline(stream, item, ',')) {
        if (!item.empty()) {
            nums.push_back(std::stoi(item));
        }
    }
    return nums;
}

int main() {
    std::string input;
    int k;

    // Input for nums(e.g., [3,2,1,5,6,4]) and k (2)
    std::cout << "Input: ";
    std::getline(std::cin, input);
    std::vector<int> nums = parseInput(input);

    std::cout << "k: ";
    std::cin >> k;

    // Find and output
    int result = findKthLargest(nums, k);
    std::cout << "Output: " << result << std::endl;

    return 0;
}

//Average Time Complexity: O(n)
//Worst-Case Time Complexity: 𝑂(n^2)
//Space Complexity: O(n)

