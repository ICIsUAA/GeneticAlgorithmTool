#include <iostream>
#include "ag.h"

using namespace std;

int fitCalc(Individual &ind){
	int ones = 0;

	for(int i=0 ; i< ind.genes.size(); i++){
		ones += ind.genes[i];
	}

	return ones;
}

int main(){
	AG ag(2, 10, 20);
	ag.ftn = &fitCalc;
	ag.evalPopulation();
	ag.printPopulation();

	return 0;
}