class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        //sort the array
        
        int l = 0, r = products.size() - 1;
        //initialize the pointer within which our result will lie
        vector<vector<string>> ans;
        
        for(int i=0; i<searchWord.size(); i++){
            char ch = searchWord[i];
            vector<string> temp; //store suggested words for searchWord length i
            
            while(l < products.size() && (i >= products[l].size() || products[l][i] != ch)){
                l++;
            }
            while(r >= 0 && (i >= products[r].size() || products[r][i] != ch)){
                r--;
            }
            
            for(int j = l, count = 0; j<=r && count < 3; j++, count++){
                temp.push_back(products[j]);
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};