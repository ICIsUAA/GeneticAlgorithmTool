#include <iostream>
#include <fstream>
#include "ag.h"
#include "AgWritter.h"

using namespace std;

int fitCalc(Individual ind){ // Define your own fitness calculator and set it to a delegate
	// one max fitness function
	// Count the number of ones the gene vector contains.

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

	AG ag(10, 5, 20); // Gene size - population size - mutation probability
	ag.ftn = &fitCalc; // Set our fitness function
	ag.evalPopulation(); // Evaluate the whole population
	ag.sortPopulation(1); // Sort the population from greatest to lowest fitness

	printf("---------------------------------------------\n");
	ag.printPopulation(); // Print the population


	int x = 4; // Iterate 4 times
	while(x--){
		printf("--------Crossing top individuals--------\n");
		ag.crossTopIndividuals(4); // Cross the top n individuals


		printf("-----Printing new population-------\n");
		ag.printPopulation(); // Print the population
	}


	//AG Writter
	AgWritter agw(&ag, "writeme.txt");
	agw.writePopulation(1);
	agw.writeTopIndividual(1);
	return 0;
}