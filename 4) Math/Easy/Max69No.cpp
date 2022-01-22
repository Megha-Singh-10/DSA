1323. Maximum 69 Number
/*You are given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).*/

TC->O(NlogN)
SC->O(1)

class Solution {
public:
    int maximum69Number (int num) {
        int rem=num,q=num,div=pow(10,(int)log10(rem));//logn time
        
        q=rem/div;  
        rem=rem%div;
        cout<<"p "<<rem<<" k "<<q<<"div "<<div<<endl;
        while(q!=6 && rem!=0)
        {
            // if(p!=0)
            div=pow(10,(int)log10(rem));
           
            q=rem/div;
             rem=rem%div;
            cout<<"p "<<rem<<" k "<<q<<"div "<<div<<endl;
        }
        if(q==6)
        num+=3*div;
        else
            return num;
        return num;
    }
};

b) TC->O(N)
SC->O(1)

class Solution {
public:
    int maximum69Number (int num) {
        string s_num = to_string(num);
        for (auto &c : s_num) {
            if (c == '6') {
                c = '9';
                break;
            }
        }
        return stoi(s_num);
    }
};