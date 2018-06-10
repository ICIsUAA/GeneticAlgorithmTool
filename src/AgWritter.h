#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
//#include "ag.h"

using namespace std;

class AgWritter{

private:
	AG* geneticAlgorithm;
	string fileName;

public:

	AgWritter(AG *ag, string fname){
		geneticAlgorithm = ag;
		fileName = fname;
	}

	void writePopulation(bool append){
		printf("I will write to a file\n");

		// Open file with name fileName

		ofstream file;

		if(append)
			file.open(fileName, std::ios_base::app);
		else
			file.open(fileName);

		int sz = (*geneticAlgorithm).getPopulationSize();
		int gsz = (*geneticAlgorithm).getGenesSize();
		vector<Individual> pop = (*geneticAlgorithm).getPopulation();

		for(int i=0 ; i<sz ; i++){
			ostringstream ind;

			for(int j=0 ; j<gsz; j++){
				ind << pop[i].genes[j];
				
			}

			ind << " | " << pop[i].fitness;
			cout << ind.str() << endl;

			file << ind.str() << "\n";
			/*fprintf(file, "asdasd");
			fflush(file);*/
		}

		file.close();
	}

};