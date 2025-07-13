#include<bits/stdc++.h>
using namespace std ;

   int merge(vector<int>& v,vector<int>& v1,vector<int>& v2 ){
        int n1 =0, n2=0 , count=0 ;
        v.clear();
        while( n1 != v1.size() or n2!= v2.size()){
            if( n1 == v1.size()){
                v.push_back(v2[n2++]);
            }
            else if( n2 == v2.size()){
                v.push_back(v1[n1++]);
            }
            else if(v1[n1] < v2[n2]){
                count += v2.size()-n2 ;
                v.push_back(v1[n1++]);
            }
            else {
                
                v.push_back(v2[n2++]);
            }
        } 
        return count ;
    }
    int sort_and_count(vector<int> &v){
        if(v.size()== 1){return 0;}
        int count = 0 ;
        int m = v.size()/2 ;
        vector<int> left(m), right(v.size()-m);
        for( int i = 0 ; i < m ; i++)
            left[i]= v[i];
        for ( int i = 0 ; i < (v.size()-m);i++)
            right[i]=v[i+m];
        count+= sort_and_count(left);
        count+= sort_and_count(right);
        count += merge(v,left,right);
        return count ;
    }




    int main() {
    vector<int> v = {0,4,2,1,0,-1,-3};
    cout << sort_and_count(v) << endl; // Should output 3
}
