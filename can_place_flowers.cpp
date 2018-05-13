class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0 && canPlant(flowerbed, i)) {
                n--;
                flowerbed[i] = 1;
            }
        }
        
        return n <= 0;
    }
    
private:
    
    bool canPlant(vector<int> &flowerbed, int i) {
        int left = (i == 0) ? 0 : flowerbed[i-1];
        int right = (i == flowerbed.size() - 1) ? 0 : flowerbed[i+1];
        
        return left == 0 && right == 0;
    }
};