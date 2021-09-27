class Solution {
public:
    int calculate(string s) {
        vector<int> vt;
        
        int num=0;
        char sign='+';
        for(int i=0;i<=s.length();i++){
            if(s[i]>='0'&&s[i]<='9'){
                num=num*10+(s[i]-'0');
            }
            else if(s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='*'||i==s.length()){
                if(sign=='+'){
                    vt.push_back(num);
                    num=0;
                }else if(sign=='-'){
                    vt.push_back(-1*num);
                    num=0;
                }else if(sign=='/'){
                    vt[vt.size()-1]=vt.back()/num;
                    num=0;
                }else if(sign=='*'){
                    vt[vt.size()-1]=vt.back()*num;
                    num=0;
                }
                
                if(i!=s.length()){
                 sign=s[i];   
                }
            }
        }
        
        int result=0;
        for(int i=0;i<vt.size();i++){
            result+=vt[i];
        }
        
        return result;
    }
};