class Solution {
public:
    int partitionFirst(vector<int>& nums, int low, int high) {
        int pivot = nums[low];
        int i = low + 1;
        int j = high;

        while (i <= j) {
            while (i <= high && nums[i] <= pivot) i++;
            while (nums[j] > pivot) j--;
            if (i < j) swap(nums[i], nums[j]);
        }
        swap(nums[low], nums[j]);
        return j;
    }

    void quickSortFirst(vector<int>& nums, int low, int high) {
        if (low < high) {
            int p = partitionFirst(nums, low, high);
            quickSortFirst(nums, low, p - 1);
            quickSortFirst(nums, p + 1, high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSortFirst(nums, 0, nums.size() - 1);
        return nums;
    }
};


//middle element
class Solution {
public:
    int partitionMiddle(vector<int>& nums, int low, int high) {
        int mid = low + (high - low) / 2;
        swap(nums[low], nums[mid]);

        int pivot = nums[low];
        int i = low + 1;
        int j = high;

        while (i <= j) {
            while (i <= high && nums[i] <= pivot) i++;
            while (nums[j] > pivot) j--;
            if (i < j) swap(nums[i], nums[j]);
        }
        swap(nums[low], nums[j]);
        return j;
    }

    void quickSortMiddle(vector<int>& nums, int low, int high) {
        if (low < high) {
            int p = partitionMiddle(nums, low, high);
            quickSortMiddle(nums, low, p - 1);
            quickSortMiddle(nums, p + 1, high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSortMiddle(nums, 0, nums.size() - 1);
        return nums;
    }
};
