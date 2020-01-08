/*
 * 605. Can Place Flowers
 */
 
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=0; i<flowerbed.size(); ++i) {
            if ((i==0 || flowerbed[i-1]==0) && 
                flowerbed[i]==0 && 
                (i==flowerbed.size()-1 || flowerbed[i+1]==0)) {
                flowerbed[i] = 1;
                ++i;
                --n;
            }
            if (n==0)
                return true;
        }
        return n<=0;
    }
};
