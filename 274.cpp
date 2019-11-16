/*
* 274. H-Index
* Given an array of citations (each citation is a non-negative integer) of a researcher,
* write a function to compute the researcher's h-index.
*
* According to the definition of h-index on Wikipedia: "A scientist has index h if h
* of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each." 
*/


class Solution {
public:
    int hIndex(vector<int>& citations) {
        // Sort from large to small
        // H idx is the largest square where x==y in histogram
        
        sort(citations.begin(), citations.end(), greater<int>());
        int res = 0;
        
        for (int i=0; i<citations.size(); ++i) {
            if (citations[i]>=i+1) {
                res = i+1;
            }
        }
        return res;
    }
};
