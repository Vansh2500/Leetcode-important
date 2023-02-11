class Solution {
public:

int merge(int low, int mid ,int high,vector<int>&nums){

int j=mid+1 ;
int count =0;
for(int i =low;i<=mid;i++)
{
while(j<=high && nums[i]>2LL*nums[j])
{
j++;
}
count+=(j-mid-1);


}
vector<int >v;
int left = low ,right= mid+1 ;
while(left<=mid && right <=high)
{
    if(nums[left]<=nums[right])
    {
v.push_back(nums[left]);
left++;
    }
    else
    {v.push_back(nums[right]);
           right++;
    }
}

while(left<=mid)
{
v.push_back(nums[left]);
left++;
}
while(right<=high)
{
 v.push_back(nums[right]);
 right++;
}
for(int i =low ;i<=high ;i++)
{
    nums[i]=v[i-low];
}
return count ;
}
int mergesort(int low ,int high,vector<int> &nums){
if(low>=high)
return 0;
int mid=(low+high)/2;
int inv =mergesort(low,mid,nums);
inv+=mergesort(mid+1 ,high,nums);
inv+=merge(low ,mid,high,nums);
    return inv;
}
    int reversePairs(vector<int>& nums) {
        
       return  mergesort(0,nums.size()-1,nums);
    }
};