class Solution {
public:

    int getnumbers(string &s){
        int d[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int month=stoi(s.substr(0,2));
        int date=stoi(s.substr(3,2));

        for(int i=0;i<month-1;i++){
            date+=d[i];
        }
        return date;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int startA=getnumbers(arriveAlice);
        int endA=getnumbers(leaveAlice);
        int startB=getnumbers(arriveBob);
        int endB=getnumbers(leaveBob);

        int l=max(startA,startB);
        int r=min(endA,endB);

        return max(0,r-l+1);
    }
};