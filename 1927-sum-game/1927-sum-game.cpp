class Solution {
public:
    bool sumGame(string num) {
        int ls = 0;
        int rs = 0;
        int lb = 0;
        int rb = 0;
        int n = num.size();
        for(int i = 0; i < n/2; i++){
            if (num[i]!= '?'){
                ls+= num[i]-'0';
            }else{
                lb++;
            }
        }
        for(int i = n/2; i<n; i++){
            if(num[i]!='?'){
                rs+=num[i]-'0';
            }else{
                rb++;
            }
        }
        if(lb+rb==0){
            return ls!=rs;
        }
        if((lb+rb)%2==1){
            return true;
        }
        int mini = min(lb, rb);
        lb-=mini;
        rb-=mini;
        if(lb>0){
            if(ls>rs){
                return true;
            }
            if(9*(lb/2) == rs-ls){
                return false;
            }else{
                return true;
            }
        }else{
            if(rs>ls) return true;
            if(9*(rb/2) == ls-rs){
                return false;
            }else{
                return true;
            }
        }

    }
};