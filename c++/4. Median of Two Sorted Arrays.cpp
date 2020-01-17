class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n){
            //互换nums1和nums2方法1
            //return findMedianSortedArrays(nums2, nums1);
            //互换nums1和nums2方法2
            vector<int>vtmp = nums1; nums1 = nums2; nums2 = vtmp;
            int itmp = m; m = n; n = itmp;
        }
        //m+n+1的1是因为保证m+n为奇数时中位数在左边
        int iStart = 0, iEnd = m, halfLen = (m + n + 1) / 2;
        while(iStart <= iEnd){
			//i是数组1的割，j是数组2的割
            int i = (iStart + iEnd) / 2;
            int j = halfLen - i;
            
			
            //对于判断条件nums1[i] < nums2[j-1]，应该保证nums1[i]和nums2[j-1]存在
            //所以i应小于iEnd，由于i、j间的制约，可推出j此时必大于0
            if(i < iEnd && nums1[i] < nums2[j-1])//i is too small
				//二分法求割，这里表示割必在数组1右边
                iStart = i + 1;
            else if(i > iStart && nums1[i-1] > nums2[j])//i is too big
                iEnd = i - 1;
            else{//此时i已经是要求的i了
				//处理特殊情况，即数组1全被划到左边数组或者右边数组了
                int maxLeft = 0;
                if(i == 0) //表示nums1没有元素划到左边的集合
                    maxLeft = nums2[j-1];
                else if(j == 0)
                    maxLeft = nums1[i-1];
                else
                    maxLeft = max(nums1[i-1], nums2[j-1]);
                if((m + n) % 2 == 1)
                    return maxLeft;
                
                int minRight = 0;
                if(i == m)
                    minRight = nums2[j];
                else if(j == n)
                    minRight = nums1[i];
                else
                    minRight = min(nums1[i], nums2[j]);
                return (maxLeft + minRight) / 2.0;
                    
            }
        }
        return 0.0;
    }
};


//错误version
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { 
        return dc(nums1, nums2, 0, nums1.size()-1, 0, nums2.size()-1);
    }
    double dc(vector<int>& nums1, vector<int>& nums2, int s1, int e1, int s2, int e2){
        int size1 = e1-s1+1;
        int size2 = e2-s2+1;

        if(size1==0)
            return size2%2==0?(double)(nums2[size2/2] + nums2[size2/2-1])/2:(double)nums2[size2/2];
        if(size2==0)
            return size1%2==0?(double)(nums1[size1/2] + nums1[size1/2-1])/2:(double)nums1[size1/2];
        if(size1==1 && size2==1)
            return (double)(nums1[s1]+nums2[s2])/2;
        double median1 = 0.0;
        double median2 = 0.0;
        median1 = size1%2==0?(double)(nums1[size1/2] + nums1[size1/2-1])/2:(double)nums1[size1/2];
        median2 = size2%2==0?(double)(nums2[size2/2] + nums2[size2/2-1])/2:(double)nums2[size2/2];

        if(median1==median2)
            return median1;
        else if(median1>median2)
            return dc(nums1, nums2, s1, (s1+e1)/2, (s2+e2)/2, e2);
        else
            return dc(nums1, nums2, (s1+e1)/2+1, e1, s2, (s2+e2)/2);

    }
};