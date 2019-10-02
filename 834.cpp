/* 
 * 843. Guess the Word
 * his problem is an interactive problem new to the LeetCode platform.
 *
 * We are given a word list of unique words, each word is 6 letters long, and one word in this list is chosen as 
 * secret.
 * You may call master.guess(word) to guess a word.  The guessed word should have type string and must be from the
 * original list with 6 lowercase letters.
 *
 * This function returns an integer type, representing the number of exact matches (value and position) of your
 * guess to the secret word.  Also, if your guess is not in the given wordlist, it will return -1 instead.
 *
 * For each test case, you have 10 guesses to guess the word. At the end of any number of calls, if you have
 * made 10 or less calls to master.guess and at least one of these guesses was the secret, you pass the testcase.
 *
 * Besides the example test case below, there will be 5 additional test cases, each with 100 words in the word
 * list.  The letters of each word in those testcases were chosen independently at random from 'a' to 'z', such
 * that every word in the given word lists is unique.
 */
 
 /**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
 
class Solution {
public:
    /*
     * Every time wehn we get the result r from guess, then we shrink the
     * candidate set by checking if the word in the set has ==r (position and value)
     * char as the previous guessed number
     *
     * If r==0, the new candidate list contains words has 0 same char as g
     *
     * Note:
     * Why for a set of 100 words, eash words contains 4 chars, it is garenteed to find
     * the secret within 10 guess?
     */
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for(int i=0; i<10; ++i) {
            int r = rand()%wordlist.size();
            string g = wordlist[r];
            int count = master.guess(g);
            cout<<g<<" "<<count<<endl;
            shrink(wordlist, g, count);
        }
    }
    
    void shrink(vector<string>& wordlist, string &g, int count) {
        int c = 0;
        vector<string> n;
        
        for(int i=0; i<wordlist.size(); ++i) {
            c=0;                    // <-------
            for(int j=0; j<6; ++j) {
                if(g[j] == wordlist[i][j]) {
                    ++c;
                }
            }
            if (c == count) {
                //cout<<wordlist[i]<<endl;
                n.push_back(wordlist[i]);
            }
        }
        wordlist = n;
       /* if(wordlist.size()<10) {
            for(auto s:wordlist) {
                cout<<s<<" ";
            }
            cout<<endl;
        }
        cout<<wordlist.size()<<endl;*/
    }
};
