/*
 * 158. Read N Characters Given Read4 II - Call multiple times
 *
 * Given a file and assume that you can only read the file using a given method read4,
 * implement a method read to read n characters. Your method read may be called multiple times.
 *
 */


// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    
    /*
     * This is a 'cheated' version
     * We are reading max(n, 4*k) in buf and it may leads to accessing
     * invalid memory address
     */
    /*char buff[4];
    int buffEnd = 0;
    int buffStart = 0;
    int read(char *buf, int n) {
        //char[] buf = new char[n];
        int idx=0;  
        while(idx<n) {
            //cout<<idx<<" "<<n<<endl;
            if(buffStart<buffEnd) {
                buf[idx++] = buff[buffStart++];
                continue;
            }
            int t = read4(buf+idx);
            idx+=t;
            //cout<<"after read "<<t<<" "<<idx<<endl;
            if(t<4)
                break;
        }
        // caller reads more than 4 chars. Thus, whatever in buff must already be used
        if(idx>n) {
            buffStart = 0;
            buffEnd = 0;
            while(n+buffEnd<idx) {
                buff[buffEnd] = buf[n+buffEnd];
                buffEnd++;
            }
        }
        buf[n] = '\0';
        return min(idx, n);
    }*/
    
    char buff[4];
    int buffEnd = 0;
    int buffStart = 0;
    int read(char *buf, int n) {
        //char[] buf = new char[n];
        int idx=0; 
        while(buffStart<buffEnd && idx<n) {
            buf[idx++] = buff[buffStart++];
        }
        while(idx+4<n) {
            //cout<<idx<<" "<<n<<endl;
            int t = read4(buf+idx);
            idx+=t;
            //cout<<"after read "<<t<<" "<<idx<<endl;
            if(t<4)
                break;
        }
        if(idx<n) {
            buffEnd = 0;
            buffStart = 0;
            buffEnd = read4(buff);
        }
        while(buffStart<buffEnd && idx<n) {
            buf[idx++] = buff[buffStart++];
        }
            
        buf[n] = '\0';
        return min(idx, n);
    }
};
