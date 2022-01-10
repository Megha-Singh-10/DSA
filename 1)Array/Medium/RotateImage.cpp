2) Rotate Image(#48)

/* You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation. */

TC-> O(N^2)
SC->O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& a) { //Part-1 & Part-2 order can be vice versa
        int first,last,row,col;
        int n=a[0].size();
        int m=a.size();
        for(int i=0;i<n;i++) //part-1
        {
            for(int j=0;j<i;j++)
            {                              
                int temp;
                temp=a[i][j];
                a[i][j]=a[j][i];
                a[j][i]=temp;
            }
        }
        int half=abs(m/2);
        for(int j=0;j<half;j++) //part-2
        {
             first=j;
             last=n-j-1;                    
           for(int i=0;i<n;i++)
            {
            int temp=a[i][first];
            a[i][first]=a[i][last];
            a[i][last]=temp;
            }                     
        }             
    }
};