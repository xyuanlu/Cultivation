/*
 * 135. Candy
 * There are N children standing in a line. Each child is assigned a rating value.
 *
 * You are giving candies to these children subjected to the following requirements:
 *
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 */
 
class Solution {
public:
    // greedy
    int candy(vector<int>& ratings) {
        // s[i] is the ith number's idx in ratings
        vector<int> s(ratings.size()), res(ratings.size(), 0);
        for(int i=0; i<ratings.size(); ++i) {
            s[i] = i;
        }
        
        // sort 
        sort(s.begin(), s.end(), [&ratings](int a, int b) {
            return ratings[a] < ratings[b];
        });
        
        int ress = 0;
        // assign candies to children
        for(int i=0; i<s.size(); ++i) {
            int idx = s[i];
            int temp = 1;
            if (idx>0 && ratings[idx] > ratings[idx-1]) {
                temp = res[idx-1]+1;
            }
            if (idx+1<ratings.size() && ratings[idx] > ratings[idx+1]) {
                temp = max(res[idx+1]+1, temp);
            }
            res[idx] = temp;
            ress += temp;
            
        }
        return ress;
    }
};
