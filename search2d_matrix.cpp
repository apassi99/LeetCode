class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        return searchMatrix(matrix, 0, matrix.size() - 1, target);
    }
    
private:
    
    bool searchMatrix(vector<vector<int>> &matrix, int startRow, int endRow, int target)
    {
        if (startRow > endRow)
        {
            return false;
        }
        
        int midRow = (startRow + endRow) / 2;
        
        if (matrix[midRow].empty())
            return false;
        
        if (matrix[midRow].front() <= target && matrix[midRow].back() >= target)
        {
            bool found = searchVector(matrix[midRow], 0,
                                      matrix[midRow].size() - 1, target);
            
            if (found)
            {
                return true;
            }
            
            return searchMatrix(matrix, startRow, midRow - 1, target) ||
                   searchMatrix(matrix, midRow + 1, endRow, target);
        }
        else if (target > matrix[midRow].back())
        {
            return searchMatrix(matrix, midRow + 1, endRow, target);
        }
        else
        {
            return searchMatrix(matrix, startRow, midRow - 1, target);
        }
    }
    
    bool searchVector(vector<int> &nums, int s, int e, int target)
    {
        if (s > e)
            return false;
        
        if (nums[s] > target || nums[e] < target)
            return false;
        
        int mid = (s + e)  / 2;
        
        if (nums[mid] == target)
            return true;
        else if (target > nums[mid])
            return searchVector(nums, mid+1, e, target);
        else
            return searchVector(nums, s, mid-1, target);
    }
};