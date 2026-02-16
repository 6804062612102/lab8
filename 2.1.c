#include <stdio.h>
int checkscore(char keys[], char std[]);

int main() {
    int i,j;
    char ans[8][10]={
        	{'A','B','A','C','C','D','E','E','A','D'},//7
			{'D','B','A','B','C','A','E','E','A','D'},//6
			{'E','D','D','A','C','B','E','E','A','D'},//5
			{'C','B','A','E','D','C','E','E','A','D'},//4
			{'A','B','D','C','C','D','E','E','A','D'},//8
			{'B','B','E','C','C','D','E','E','A','D'},//7
			{'B','B','A','C','C','D','E','E','A','D'},//7
			{'E','B','E','C','C','D','E','E','A','D'}};//7

	char charkeys[10]={'D','B','D','C','C','D','A','E','A','D'};
   	for(int i=0; i<8; i++)
    	printf("std %d => %d\n", (i+1), checkscore(charkeys, ans[i]));
    	
    return 0;
}

int checkscore(char keys[], char std[]){
	int score = 0;
	for(int i=0; i<10; i++){
		if(keys[i] == std[i]){
			score++;
		}
	}
	return score;
}

