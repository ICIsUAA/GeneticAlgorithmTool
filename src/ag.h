#include <iostream>
#include <vector>

using namespace std;

class AG{

private:
	vector<int> genes;
	vector<vector<int> > population;

	int MutationProb;
	int genesSize;
	int populationSize;

public:

	//Setters
	void setGenesSize(int sz){
		genesSize = sz;
	}

	void setPopulationSize(int sz){
		populationSize = sz;
	}

	void setMutationProb(int cp){
		MutationProb = cp;
	}

	// Getters 
	int getGenesSize(){
		return genes.size();
	}

	// Methods
	vector<int> generateIndividual(){
		vector<int> individual;

		for(int i=0 ; i<genesSize; i++){
			individual.push_back(rand()%2);
		}
		return individual;
	}

	void generateRandomPopulation(){
		population = vector<vector<int> >();
		
		for(int i=0 ; i<populationSize; i++){
			population.push_back(generateIndividual());
		}
	}

	void printIndividual(vector<int> ind){
		int sz = ind.size();

		for(int i=0 ; i<sz; i++){
			printf("%d", ind[i] );
		}

		printf("\n");
	}

	void printIndividual(int idx){
		vector<int> ind = population[idx];
		int sz = ind.size();

		for(int i=0 ; i<sz; i++){
			printf("%d", ind[i] );
		}

		printf("\n");
	}

	void printPopulation(){
		for(int i=0 ; i<populationSize ; i++){
			printIndividual(population[i]);
		}
	}

	//Constructos
	/*AG(int geneSize){
		genes = vector<int>(geneSize);
		setGenesSize(geneSize);
	}


	AG(int gSize, int pobSize){
		setGenesSize(gSize);
		setPopulationSize(pobSize);
	}*/

	AG(int gSize, int pobSize, int cp){
		setGenesSize(gSize);
		setPopulationSize(pobSize);
		setMutationProb(cp);
		generateRandomPopulation();
	}



};