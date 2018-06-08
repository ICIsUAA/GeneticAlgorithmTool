#include <iostream>
#include <vector>

using namespace std;


struct Individual{
	vector<int> genes;
	int fitness = 0;
};

typedef int (*Fitness) (Individual &ind);

class AG{

private:
	vector<Individual> population;

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
		return genesSize;
	}

	// Methods
	Individual generateIndividual(){
		vector<int> individual;

		for(int i=0 ; i<genesSize; i++){
			individual.push_back(rand()%2);
		}

		Individual ind;
		ind.genes = individual;
		return ind;
	}

	void generateRandomPopulation(){
		population = vector<Individual>();
		
		for(int i=0 ; i<populationSize; i++){
			population.push_back(generateIndividual());
		}
	}

	void printIndividual(Individual ind){
		int sz = ind.genes.size();

		for(int i=0 ; i<sz; i++){
			printf("%d", ind.genes[i] );
		}

		printf(" | Fitness: %d\n",ind.fitness);
	}

	void printIndividual(int idx){
		printIndividual(population[idx]);
	}

	void printPopulation(){
		for(int i=0 ; i<populationSize ; i++){
			printIndividual(population[i]);
		}
	}

	Fitness ftn;

	void evalPopulation(){
		for(int i=0 ; i < populationSize ; i++){
			population[i].fitness = ftn(population[i]);
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