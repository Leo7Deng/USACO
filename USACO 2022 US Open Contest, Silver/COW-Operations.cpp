#include <bits/stdc++.h>
using namespace std;

int twoNum(int a, int b){
  if(a==b){
    return 0;
  }
  if(a==0){
    return b;
  }
  if (b==0){
    return a;
  }
  if(a==1||b==1){
    if(a==2||b==2){
      return 3;
    }
    if(a==3||b==3){
      return 2;
    }
  }else{
    return 1;
  }
}

int main() {
  string str;
  char letter;
  int repeat, newSum=0, previous, current, first, second;
  cin >> str >> repeat;
  int prefix[str.length()];

  //first index
  letter=str.at(0);
    if(letter=='C'){
      prefix[0]=1;
    } else if(letter=='O'){
      prefix[0]=2;
    } else if(letter=='W'){
      prefix[0]=3;
    }
  //create prefix
  for (int i=1; i<str.length(); i++){
    previous = prefix[i-1];
    letter = str.at(i);
    if(letter=='C'){
      current=1;
    } else if(letter=='O'){
      current=2;
    } else if(letter=='W'){
      current=3;
    }
    //setting newSum
    newSum = twoNum(previous, current);
    prefix[i]=newSum;
    //prefix sum complete
  }
  //q rows
  for (int i=0; i<repeat; i++){
    cin >> first >> second;
    if (first==1){
      if (prefix[second-1]==1){
        cout<<"Y";
      } else{
        cout<<"N";
      }
      //cout << prefix[second-1] << endl << endl;
    } else{
      if(twoNum(prefix[first-2], prefix[second-1])==1){
        cout<<"Y";
      } else{
        cout<<"N";
      }
      //cout << twoNum(prefix[first-2], prefix[second-1]) << endl << endl;
    }
  }
}