#include <iostream>
using namespace std;
int cow[100000];
int main() {
  
  int num, num2, max=0, ind=0, input, low=9999, lowCount=0, count=0, run=0;
  cin >> num;
  for (int i=0; i<num; i++){
    max =0, ind =0, count=0, lowCount=0, run=0;
    cin>>num2;
    
    for (int j=0; j<num2; j++){
      cin >> input;
      cow[j]=input;
      if (input>max){
        max=input;
        ind=j;
      }
    }
    if(num2==1){
      cout<<"0"<<endl;
    } else {
      if (cow[0]>cow[1]){
        cout<<"-1"<<endl;
        continue;
      }
      else if(cow[num2-1]>cow[num2-2]){
        cout<<"-1"<<endl;
        continue;
      }
    }
    while (lowCount!=num2){
      if(cow[ind-1]>cow[ind+1]){
        cow[ind-1]--;
        cow[ind]--;
        count++;
      }
      else{
        cow[ind+1]--;
        cow[ind]--;
        count++;
      }
      max=0;
      low=9999;
      lowCount=0;
      for (int a=0; a<num2; a++){
        if (cow[a]>max){
          max=cow[a];
          ind=a;
          
        }
        if(cow[a]<low){
          low=cow[a];
        }
      }
      if (low<0){
        cout<<"-1"<<endl;
        run=1;
        break;
      }
      for (int b=0; b<num2; b++){
        if(cow[b]==low){
          lowCount++;
        }
      }
    }
    if(run==0){
      cout<<count*2<<endl;
    }
  }
}
