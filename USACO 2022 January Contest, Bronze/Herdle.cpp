#include <string>
#include <iostream>
using namespace std;

int main() {
  char grid[2][10];
  string input, total;
  int green=0, yellow=0;
  for (int i=0; i<2; i++){
    total="";
    for (int j=0; j<3; j++){
      cin >> input;
      total+=input;
    }
    strcpy(grid[i],total.c_str());
  }

  for(int j=0; j<9; j++){
    if (grid[0][j]==grid[1][j]){
      green++;
      grid[1][j]='a';
      grid[0][j]='b';
    }
  }
  for(int j=0; j<9; j++){
    for(int k=0; k<9; k++){
        if(k!=j){
          if(grid[0][j]==grid[1][k]){
            yellow++;
            grid[1][k]='a';
            grid[0][j]='b';
          }
        }
    }
  }
  cout<<green<<endl;
  cout<<yellow;
}