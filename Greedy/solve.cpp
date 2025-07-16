#include<bits/stdc++.h>

using namespace std ;

int main(){
    // taking input
    int n , b, m;
    cin >> n >> b;
    int seating[n];
    for( int i = 0; i < n ; i++){
        cin >> seating[i];
    }
    cin >> m ;
    int count_blocked = 0, count_free = 0;
    for( int i = 0 ; i < n ; i ++){
        if(seating[i]== 0) count_free ++ ;
        if(seating[i] == 1){
            if((i+1) < n and (i+1)%(n/b)!= 0  and seating[i+1]==0)
                count_blocked ++ ; 
        }
        else if(seating[i] == 2){
            if((i+1) < n and (i+1)%(n/b)!= 0)
                count_blocked ++ ;
            if((i-1) > 0 and (i-1)%(n/b)!= ((n/b)-1) and seating[i-1]==0)
                count_blocked ++ ;
        }
    }

    int ans = count_free - count_blocked ;
    if( ans >= m)cout <<"True\n";
    else cout <<"False\n";

    


}