class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = nums[0];
        int times = 1;
        for(int i=1; i<nums.size(); ++i){
            if(times == 0){
                result = nums[i];
                times = 1;
            }
            else if(nums[i] == result)
                times++;
            else
                times--;
        }
        return result;
    }
};


class Solution {
public:
    int partion(vector<int>& nums,int start,int end){
        int s = start;
        int e = end;
        int pivot = nums[s];
        while(s<e){
            while(s<e && nums[e]>=pivot)
                e--;
            nums[s] = nums[e];
            while(s<e && nums[s]<=pivot)
                s++;
            nums[e] = nums[s];
        }
        nums[s]=pivot;
        return s;
    }
    int majorityElement(vector<int>& nums) {
        
        int length = nums.size();
        int middle = length/2;
        int start = 0;
        int end = length-1;
        int index = 0;
        while(start<end){
            index = partion(nums,start,end);
            if(index==middle)
                return nums[index];
            else if(index>middle)
                end = index-1;
            else if(index<middle)
                start = index+1;
        }
        return 0;
    }
};

class Solution {
public:
    int partion(vector<int>& nums,int start,int end){
        int s = start;
        int e = end;
        int pivot = nums[s];
        while(s<e){
            while(s<e && nums[e]>=pivot)
                e--;
            nums[s] = nums[e];
            while(s<e && nums[s]<=pivot)
                s++;
            nums[e] = nums[s];
        }
        nums[s]=pivot;
        return s;
    }
    int majorityElement(vector<int>& nums) {
        
        int length = nums.size();
        int middle = length/2;
        int start = 0;
        int end = length-1;
        int index = partion(nums,start,end);
        while(index!=middle){
            if(index>middle){
                end = index-1;
                index = partion(nums,start,end);
            }
            else{
                start = index+1;
                index = partion(nums,start,end);
            }
        }
        return nums[index];
    }
};