class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xi=max(x1,min(x2,xCenter));
        int yi=max(y1,min(yCenter,y2));
        int dx =xi-xCenter;
        int dy =yi-yCenter;
        return dx*dx+dy*dy <=radius*radius;
    }
};
