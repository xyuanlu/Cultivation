/*
 * 1041. Robot Bounded In Circle
 * 
 *  On an infinite plane, a robot initially stands at (0, 0) and faces north. 
 * The robot can receive one of three instructions:
 *
 * "G": go straight 1 unit;
 * "L": turn 90 degrees to the left;
 * "R": turn 90 degress to the right.
 * The robot performs the instructions given in order, and repeats them forever.
 * 
 * Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.
 */
 
 class Solution {
public:
    bool isRobotBounded(string instru) {
        // when run the instruction 4 times, the orintation mist be the same as begin
        // we just need to check if the point is the same
        
        // only need to compute the diff x anfd diff y, faceing, for one set on instruction
        
        // face up, left, down, right
        int orirn[] = {0, 1, 2, 3};
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        
        // key = x*100 + y;
        unordered_set<int> visited;
        
        // facing 0, turn left+1, right-1, face = (face+4)%4
        int f = 0, x=0, y=0;

        for(int i=0; i<instru.size(); ++i) {
            if (instru[i] == 'G') {
                x+=dx[f];
                y+=dy[f];
            } else if (instru[i] == 'L') {
                f = (f+1)%4;
            } else { // 'R'
                f = f-1;
                if (f<0) {
                    f = (f+4) %4;
                }
            }
        }
        int diffx = x-0;
        int diffy = y-0;
        x=0; y=0; int ff = f; f=0;
        
        // run instruction 4 times
        for(int i=0; i<4; ++i) {
            int xx = diffx, yy=diffy;
            if (f==1) {
                xx = diffy;
                yy = -diffx;
            } else if (f == 2) {
                xx = -diffx;
                yy = -diffy;
            } else if (f == 3) {
                xx = -diffy;
                yy = diffx;
            }
            x += xx;
            y += yy;
            f = f+ff;
            f = (f+4)%4;
        }
        return x==0 && y==0;
        
    }
};
