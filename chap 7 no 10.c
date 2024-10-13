#include <stdio.h>


#define PRECINCT 5
#define CANDIDATE 4

void displayVotes(int votes[PRECINCT][CANDIDATE]){
  printf("\nPrecinct Candidate A Candidate B Candidate C Candidate D\n");
  for(int i = 0; i < PRECINCT; i++){
    printf("   %d       ", i + 1);
    for(int j = 0; j < CANDIDATE; j++){
      printf("%d          ", votes[i][j]);
    }
    printf("\n");
  }
}

void hitungTotalVote(int votes[PRECINCT][CANDIDATE], int totals[CANDIDATE], int *totalVotes){
  *totalVotes = 0;
  for(int j = 0; j < CANDIDATE; j++){
    totals[j] = 0;
    for(int i = 0; i < PRECINCT; i++){
      totals[j] += votes[i][j];
    }
    *totalVotes += totals[j];
  }
}

void hasilVote(int totals[CANDIDATE], int totalVotes){
  printf("\nVotes Received:\n");
  for(int i = 0; i < CANDIDATE; i++){
    printf("Candidate %c: %d votes (%.2lf%%)\n", 'A' + i, totals[i], (totals[i] * 100.0) / totalVotes);
  }
}

void menangAtauDuaPutaran(int totals[CANDIDATE], int totalVotes){
  int maxVotes = 0;
  int secondMaxVotes = 0;
  int winner = -1;
  int secondWinner = -1;

  for(int i = 0; i < CANDIDATE; i++){
    if(totals[i] > maxVotes){
      maxVotes = secondMaxVotes;
      winner = secondWinner;
      maxVotes = totals[i];
      winner = i;
    } else if(totals[i] > secondMaxVotes){
      secondMaxVotes = totals[i];
      secondWinner = i;
    }
  }
   if((maxVotes * 100.0) / totalVotes > 50.0){
      printf("\nThe Winner is Candiate %c with over 50%% of the votes\n", 'A' + winner);
    } else {
      printf("\nThere is No Candiate received more than 50%% of the votes\n");
      printf("Runoff will be be held between Candidate %c and %c\n", 'A' + winner, 'A' + secondWinner);
    }
}



int main(){
  int votes[PRECINCT][CANDIDATE] = {
    {192, 48, 206, 37},
    {147, 90, 312, 21},
    {186, 12, 121, 38},
    {114, 21, 408, 39},
    {267, 13, 382, 29},
  };

  int totals[CANDIDATE];
  int totalVotes = 0;

  displayVotes(votes);
  hitungTotalVote(votes, totals, &totalVotes);
  hasilVote(totals, totalVotes);
  menangAtauDuaPutaran(totals, totalVotes);

 
  printf("\n-------------------------------------------------------\n");
  printf("\nif candidate C, precinct 4 receiving only 108 votes:\n");
  votes[3][2] = 108;
  hitungTotalVote(votes, totals, &totalVotes);
  hasilVote(totals, totalVotes);
  menangAtauDuaPutaran(totals, totalVotes);
  printf("\n");

  return 0;
}