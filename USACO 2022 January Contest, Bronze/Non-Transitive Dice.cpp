#include <stdio.h>
#include <iostream>
using namespace std;


int pointsAgainstOtherDice(int value, int* diceB) {
  int points=0;

  for (int j=0; j<4; j++) {
    if (value>diceB[j]) points+=2;
    else if (value==diceB[j]) points++;
  }
  return points;
}

int beats(int* diceA, int* diceB) {
  int points=0;
  for (int i=0; i<4; i++) {
    points += pointsAgainstOtherDice(diceA[i],diceB);
  }
  if (points>16) return 1;
  else if (points==16) return 0;
  else return -1;
}

int findDiceInBetween(int* diceA, int* diceB, int* diceC, int ind, int points) {
  int newpoints;
  int upperLimit;

  if (ind<0) { // evaluate match
    if (points>16) {
      if (beats(diceA,diceC)>0) { // we found a dice
        //for (int i=0; i<4; i++) printf("%d ",diceC[i]); printf("\n");
        return 1;
      }
      else return 0;
    }
    else return 0;
  }

  if (ind<3) upperLimit = diceC[ind+1]; else upperLimit = 10;

  for (int i=1;i<=upperLimit;i++) {
    newpoints=pointsAgainstOtherDice(i,diceB);
    diceC[ind] = i;
    if (findDiceInBetween(diceA,diceB,diceC,ind-1,points+newpoints))
      return 1;
  }
  return 0;
}

int main()
{
  int num;
  cin >> num;
  for (int i=0; i<num; i++){
    int diceA [4];
    int diceB [4];
    for (int i = 0; i < 4; i++) {
      cin >> diceA[i];
    }
    for (int i = 0; i < 4; i++) {
      cin >> diceB[i];
    }
    int diceC [4];

    int compareDie = beats(diceA,diceB);
    if (compareDie==0) { printf("no\n"); return 0; } // no winner
    if (compareDie>0) { // A beats B and we swap die
      //printf("A won\n");
      int temp;
      for (int i=0; i<4; i++) {
        temp = diceA[i]; diceA[i] = diceB[i]; diceB[i] = temp;
      }
    }
    // now B beats A
    if (findDiceInBetween(diceA,diceB,diceC,3,0)) {
      printf("yes\n");
    }
    else {
      printf("no\n");
    }
  }
  return 0;
 }