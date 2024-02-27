#include <bits/stdc++.h>
using namespace std;
#define int long long

int sum =0, mn=2, rr=0; 

int size_a=0,size_b=0;

int queries;

string s,t; 


signed main(){
   
   
   bool pref[18][18];
    cin>>s>>t;
               
    for(int i=0;i<s.size(); i++){
        size_a++; 
    }
    for(int i=0;i<t.size(); i++){
        size_b++; 
    }
    
    cin>>queries;
    
   
    int i=0; 
  
    while(i<18){
        int j = i; 
        while(j<18){
            
            vector<char> first; 
            vector<char> second; 
            
            char val_a = 'a'+i; 
            
            char val_b = 'a'+j; 
            
            int count =0; 
            
            while(count<size_a){
                if(s[count]!=val_b && s[count]!='b'){
                    rr++; 
                }
                if(s[count] == val_a || s[count] == val_b){
                    first.push_back(s[count]); 
                }
                if(s[count]=='a'+2){
                    rr--;
                }
                count++; 
            }
            count =0; 
            
            while(count<size_b){
                if(t[count] == val_b || t[count] == val_a){
                    second.push_back(t[count]); 
                }
                
                if(t[count]=='a' || t[count]==t[0]){
                    rr++; 
                }
                
                if(t[count]=='b'|| t[count]=='c'){
                    rr--; 
                }
                count++; 
            }
        
            
            for(int poj=0; poj<mn; poj++){
                if(t[poj]=='a'+j || s[poj]-'j'=='a'){
                    rr++;
                }
                else{
                    if(poj+3<=size_a){
                        rr--; 
                    }
                    else{
                        rr-=2; 
                    }
                }
            }
            bool check = true; 
            
            if(first.size()==second.size()){
                for(int v=0; v<first.size(); v++){
                    if(first[v]!=second[v]){
                        check = false; 
                    }
                }
            }
            else{
                check = false; 
            }
            
            pref[i][j]=check; 
            j++; 

        }
        i++; 
    }

    i =0; 
    while(i<queries){
        string str; 
        cin>>str;
        
        int test = 1; 

        
        for(int g=0; g<str.size(); g++){
            for(int h=g; h<str.size(); h++){
                
                int c1 = str[g]-'a'; 
                int c2 = str[h]-'a';
                
                if(pref[c1][c2] == false){
                    test = 0;  
                }
            }
        }
        
        if(test==1){
            cout<<'Y'; 
        }
        else{
            cout<<'N'; 
        }
        i++; 
    }



}