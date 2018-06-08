#include <iostream>
#include "ag.h"

using namespace std;

int fitCalc(Individual ind){
	int ones = 0;

	for(int i=0 ; i< ind.genes.size(); i++){
		ones += ind.genes[i];
	}

	return ones;
}

void setSeed(){
	srand(time(NULL));
}

int main(){
	setSeed();

	AG ag(5, 5, 20);
	ag.ftn = &fitCalc;
	ag.evalPopulation();
	ag.sortPopulation(1);
	printf("---------------------------------------------\n");
	ag.printPopulation();


	int x = 4;

	while(x--){
		printf("--------Crossing top individuals--------\n");
		ag.crossTopIndividuals(4);


		printf("-----Printing new population-------\n");
		ag.printPopulation();		
	}

	return 0;
}