class Solution {
public:
    static bool compare(int a,int b){
        return a<b;
    }
    int longestConsecutive(vector<int>& arr) {
        if(arr.size()==0){
            return 0;
        }
       int n=arr.size();
     sort(arr.begin(),arr.end(),compare);
     int maxcount=1;
     int count=1;
     for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]){
            continue;
        }
        if(arr[i]==arr[i-1]+1){
            count++;
        }
        else{
            count=1;
        }
        maxcount=max(maxcount,count);
     }
     return maxcount;
    }

};