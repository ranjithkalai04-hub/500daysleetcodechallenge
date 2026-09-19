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
/*
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        // Find the closest X coordinate of the rectangle
        int closestX;

        if (xCenter < x1) {
            closestX = x1;
        }
        else if (xCenter > x2) {
            closestX = x2;
        }
        else {
            closestX = xCenter;
        }

        // Find the closest Y coordinate of the rectangle
        int closestY;

        if (yCenter < y1) {
            closestY = y1;
        }
        else if (yCenter > y2) {
            closestY = y2;
        }
        else {
            closestY = yCenter;
        }

        // Difference between circle center and closest point
        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        // Distance squared
        int distanceSquared = dx * dx + dy * dy;

        // Compare with radius squared
        int radiusSquared = radius * radius;

        if (distanceSquared <= radiusSquared) {
            return true;
        }
        else {
            return false;
        }
    }
};
*/
