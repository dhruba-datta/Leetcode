class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        
        sort(v.begin(),v.end());
        vector<vector<int>>ans;
   
        ans.push_back(v[0]);

        int first = ans[0][0];
        int last = ans[0][1];
        int k=0;

        for(int i=1;i<v.size();i++)
        {

            if(v[i][0]<=last)
            {
                ans[k][1] = max(v[i][1],last);
                ans[k][0] =  min(v[i][0],first);
                first = ans[k][0];
                last = ans[k][1];
               // cout<<" -> "<<first<<" "<<last<<endl;
            }
            else{

                vector<int>temp;
                temp.push_back(v[i][0]);
                temp.push_back(v[i][1]);

                ans.push_back(temp);

                k++;
                first =  ans[k][0];
                //cout<<"D";
                last =  ans[k][1];

            }
    }
            return ans;
    }

};
//credit goes to dhruba