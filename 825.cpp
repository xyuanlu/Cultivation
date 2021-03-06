/*
 * 825. Friends Of Appropriate Ages
 *
 * Some people will make friend requests. The list of their ages is given and ages[i] is the age of the ith person. 
 * Person A will NOT friend request person B (B != A) if any of the following conditions are true:
 * age[B] <= 0.5 * age[A] + 7
 * age[B] > age[A]
 * age[B] > 100 && age[A] < 100
 * Otherwise, A will friend request B.
 * Note that if A requests B, B does not necessarily request A.  Also, people will not friend request themselves.
 * How many total friend requests are made?
 */
 
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        /*
         * For each person A, 
         * Find all people before him 
         * person B's age whouls be with in (0.5*age[A]+7, A]
         * The begining point should be found using binary search
         */
        int res = 0;
        sort(ages.begin(), ages.end());
        for (int i=0; i<ages.size(); ++i) {
            int count = 1;
            while(i<ages.size()-1 && ages[i] == ages[i+1]){
                ++count;
                ++i;
            }
            if(i==0)
                continue;
            double b = 0.5*ages[i] + 7;
            int l=-1, r=i-1, m;
            if(ages[i-1] <= b)
                continue;
            while(l<r-1) {
                m = l+(r-l)/2;
                if (ages[m]>b)
                    r = m;
                else
                    l = m;
            }
            //cout<<i<<" "<<b<<" "<<r<<endl;
            res += (i-r)*count;
        }
        return res;
        
    }
};
