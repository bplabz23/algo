class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        int mid;

        // While our search does not go out-of-bounds
        while (hi >= lo)
        {
            // Calculate middle index of [sub]array
            mid = (hi + lo) / 2;

            // if our target is greater than what is at the middle of the array
            if (target > nums[mid])
            {
                lo = mid + 1;                   // reduce the array to include only possible values
            }

            // If our target is less  than what is at the middle
            else if (target < nums[mid])
            {
                hi = mid - 1;                   // reduce the array to include only possible values
            }
            
            // otherwise, if the middle of the array equals the target
            else
            {
                return mid;
            }
        }

        // Otherwise, if not found, return -1
        return -1;

    }
};
