#include <iostream>
#include <vector>
#include <sstream>
#include <string>

// Function to merge two sorted arrays
void merge(std::vector<int>& nums1, int m, const std::vector<int>& nums2, int n) {
    int i = m - 1;  // Last index of the initial elements in nums1
    int j = n - 1;  // Last index of nums2
    int k = m + n - 1;  // Last index of nums1

    // Merge nums1 and nums2 in reverse order
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    // Copy remaining elements of nums2 if any
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}


std::vector<int> parseArray(const std::string& input) {
    std::vector<int> result;
    std::string cleanedInput = input.substr(1, input.size() - 2); // Remove brackets
    std::stringstream ss(cleanedInput);
    std::string item;
    while (std::getline(ss, item, ',')) {
        result.push_back(std::stoi(item));
    }
    return result;
}

int main() {
    std::string nums1Input, nums2Input;
    int m, n;

    // Input for nums1
    std::cout << "Enter nums1 (e.g., [1,2,3,0,0,0]): ";
    std::getline(std::cin, nums1Input);
    std::vector<int> nums1 = parseArray(nums1Input);
    std::cout << "Enter m: ";
    std::cin >> m;

    // Input for nums2
    std::cin.ignore(); // Ignore leftover newline character
    std::cout << "Enter nums2 ([2,5,6]): ";
    std::getline(std::cin, nums2Input);
    std::vector<int> nums2 = parseArray(nums2Input);
    std::cout << "Enter n: ";
    std::cin >> n;

    // Adjust size of nums1 to accommodate merged result
    nums1.resize(m + n, 0);

    // Merge arrays
    merge(nums1, m, nums2, n);

    // Output the merged array
    std::cout << "Output: [";
    for (size_t i = 0; i < nums1.size(); ++i) {
        std::cout << nums1[i];
        if (i < nums1.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
//Time Complexity: O(m + n)
//Space Complexity: O(1)
