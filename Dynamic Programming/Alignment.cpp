
#include <bits/stdc++.h>
using namespace std ;

// opt(i,j) = optimal of ith prefix ofs s1 and jth prefix of s2 

void SetUpSolution(int** dpTable, char** rec, string s1, string s2 ,int match, int gap , int miss){
    for( int i = 1 ; i < s1.size()+1 ; i++){
        for(int j = 1 ; j < s2.size()+1; j++){
            int cost ;
            if(s1[i-1]== s2[j-1]){
                dpTable[i][j] = match + dpTable[i-1][j-1];
                rec[i][j] = 'M';
            }
            else{
                int cost1 = gap + dpTable[i][j-1];
                int cost2 = gap + dpTable[i-1][j];
                int cost3 = miss + dpTable[i-1][j-1];
                int m = max(cost1, max(cost2, cost3));
                dpTable[i][j] = m ;
                if(m == cost1)rec[i][j]='G';
                else if ( m == cost2)rec[i][j]='g';
                else rec[i][j]='x';
                
            }
        }
    }

}


int main(){
    int match , mismatch , gap ;
    cout <<"Enter points for match , deduction for mismatch and gap\n";
    cin >> match >> mismatch >> gap ;
    cout << "Enter first sequence : "<<endl ;
    string s1 ; cin >> s1 ;
    cout<< "Enter Second Sequence\n";
    string s2 ; cin >> s2 ;
    int n1 = s1.length();
    int n2 = s2.length();

    int** dp_table;
    dp_table = new int*[n1+1];
    for( int i = 0 ; i < n1+1 ; i++)
        dp_table[i] = new int[n2+1];
    
    for( int i = 0 ; i < n1 + 1; i ++){
        for(int j = 0 ; j < n2 + 1 ; j++){
            dp_table[i][j] = -1 ;
            if(i == 0)
                dp_table[i][j] = gap * j ;
            if(j == 0)
                dp_table[i][j] = gap*i ;
                
        }
    }

    char** reConstruct;
    reConstruct = new char*[n1+1];
    for( int i = 0 ; i < n1+1 ; i++)
        reConstruct[i] = new char[n2+1];

    SetUpSolution(dp_table, reConstruct, s1, s2,match,gap, mismatch);

    int ans = dp_table[n1][n2];
    cout <<"Global Alignment Problem :"<<endl ;
    cout<< "_______________________________\n";
    cout <<"Maximum possible points : "<< ans << endl ;
    cout << "Reconstructing the Solution :\n" ;
    int i = n1, j = n2 ;
    string b1, b2 ;
    
    while(i or j){
        if(!j){
            b1 += s1[i-1];
            b2 += '-';
            i-- ;
        }
        else if(!i){
            b1 += '-';
            b2 += s2[j-1];
            j-- ;
        }
        else if (reConstruct[i][j] == 'M' or reConstruct[i][j]=='x'){
            b1+=s1[i-1];
            b2+=s2[j-1];
            i--; j-- ;
        }
        else if(reConstruct[i][j]=='G'){
            b1 += '-';
            b2+=s2[j-1];
            j-- ;
        }
        else if(reConstruct[i][j]=='g'){
            b1+= s1[i-1];
            b2+='-';
            i-- ;
        }

    }
    reverse(b1.begin(),b1.end());
    reverse(b2.begin(),b2.end());
    cout << b1 << endl ;
    cout <<b2 << endl ;

    cout <<"Local ALignment Problem \n";
    cout <<"________________________________"<<endl ;

    int max = 0 ;
    int target = -1 ;
    int count = 0 ;
    int size = b1.size();
    int local_target=-1 ;
    for(int i = 0 ; i < size ; i++){
        if(b1[i]==b2[i]){
            if(count == 0)
                local_target = i ;
            count++ ;
            if(count > max){
                max = count ;
                target = local_target ;
            }
        }
        else {
            count = 0 ;
        }
      
    }
    if(max == 0)cout <<"No matches\n";
    else{
        string s3 ;
        for( int i = target;i <target + max ; i++)
            s3.push_back(b1[i]);
        cout <<"ALignment : ";
        cout << s3 ;
        ans = s3.size();
        cout <<"Score :"<<ans*match << endl ;
    }




}