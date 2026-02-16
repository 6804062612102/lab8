#include <stdio.h>

void addthree(int *, int (*)[2], int);


int main(){
	
	int number[] = {5,10,15,20,25,30,35};
	int pos[][2] = {{1,3},{2,7},{3,5},{4,12}};
	
	addthree(number, pos, sizeof(pos)/sizeof(pos[0]));
	
	for(int i=0; i<sizeof(number)/sizeof(number[0]); i++){
		printf("%d ",number[i]);
	}
	
	return 0;
}

void addthree(int *array, int (*pos)[2], int size){
	
	for(int i=0; i<size; i++){
		array[pos[i][0]] += pos[i][1];
	}
	
}
