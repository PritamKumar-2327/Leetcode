class Solution {
public:
 int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
 for(int i=0;i<queries.size();i++){
 vector<int>q=queries[i];
 int idx=q[0];
 while(idx<=q[1]){
 // if 1e9*1e9, int will overflow, convert into long
 nums[idx]=(1ll*nums[idx]*q[3]) % int(pow(10,9)+7);
 idx+=q[2];
 }
 }

 int XOR=nums[0];
 for(int i=1;i<nums.size();i++){
 XOR=XOR^nums[i];
 }
 return XOR;
 }
};