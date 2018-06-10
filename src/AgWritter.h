#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

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

			file << pop[i].toString();
		}

		file.close();
	}

	void writeTopIndividual(bool append){

		// Open file with name fileName
		ofstream file;

		if(append)
			file.open(fileName, std::ios_base::app);
		else
			file.open(fileName);


		Individual ind = (*geneticAlgorithm).getTopIndividual(true);

		file << "Top: " << ind.toString();
		file.close();
	}

};