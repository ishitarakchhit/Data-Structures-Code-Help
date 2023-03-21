/*
Minimum Time Difference
Medium
1.5K
237
Companies
Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 

Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1
Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
*/

class Solution {
public:

    int timediff(string& a, string& b){
        int time1= ((a[0]-'0')*10 + a[1]-'0')* 60 + ((a[3]-'0')*10 + a[4]-'0');
        int time2= ((b[0]-'0')*10 + b[1]-'0')* 60 + ((b[3]-'0')*10 + b[4]-'0');
        cout<<time1<<" "<<time2<<endl;
        int diff1;
        int diff2;
        diff1= abs(time1-time2);
        diff2= 1440 - max(time1, time2) + min(time1, time2);
        int diff3= abs(time2-time1);
        cout<<"difference"<<diff1<<" "<<diff2<<" "<<diff3;
        cout<<min(diff1, min(diff2, diff3));
        return min(diff1, min(diff2, diff3));
    }

    int findMinDifference(vector<string>& timePoints) {
        int mini=INT_MAX;
        for(int i=0; i<timePoints.size(); i++){
            for(int j=i+1; j<timePoints.size(); j++){
                mini = min(mini, timediff(timePoints[i], timePoints[j]));
                if(mini==0)
                    return mini;
            }
        }
        return mini;
    }
};