class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
       int totaltime=0;
       for(int i=1;i<points.size();i++)
       {
        int x1=points[i-1][0];
        int y1=points[i-1][1];

        int x2=points[i][0];
        int y2=points[i][1];

        int dx=abs(x1-x2);
        int dy=abs(y1-y2);

        totaltime+=max(dx,dy);
       }
       return totaltime;
    }
};