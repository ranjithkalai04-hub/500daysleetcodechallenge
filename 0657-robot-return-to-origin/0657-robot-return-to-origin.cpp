class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0,y=0;
        for(int i=0;moves[i]!='\0';i++){
            if(moves[i]=='U'){
                y++;
            }
            else if(moves[i]=='D'){
                y--;
            }
            else if(moves[i]=='L'){
                x--;
            }
            else {
                x++;
            }
        }
        return (x==0 && y==0);
    }
};

// UP(0,1)
// DOWN(0,-1)
// LEFT(-1,0)
// RIGHT(1,0)         (Y)
//                     1
//                     |
//                 -1--0--1(X)
//                     |
//                     -1