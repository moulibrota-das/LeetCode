```
class Solution {
public:
vector<string> summaryRanges(vector<int>& nums) {
vector<string> ans;
if(nums.size() == 0) return ans;
int start = nums[0], end = nums[0];
for(int i=1; i<nums.size(); i++){
if(nums[i] - 1 != nums[i-1]){
if(start == end) ans.push_back(to_string(start));
else{
string temp = to_string(start) + "->" + to_string(end);
ans.push_back(temp);
}
start = end = nums[i];
}
else{
end = nums[i];
}
}
if(start == end) ans.push_back(to_string(start));
else{
string temp = to_string(start) + "->" + to_string(end);
ans.push_back(temp);
}
return ans;
}
};
```