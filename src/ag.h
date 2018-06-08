#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;


struct Individual{
	vector<int> genes;
	int fitness = 0;

	bool operator< (Individual other)const{
		return fitness < other.fitness;
	}

	bool operator> (Individual other)const{
		return fitness > other.fitness; 
	}
};

typedef int (*Fitness) (Individual ind);

class AG{

private:
	vector<Individual> population;

	int MutationProb;
	int genesSize;
	int populationSize;
	int crossPoint = 0;

public:

	//Setters
	void setGenesSize(int sz){
		genesSize = sz;
	}

	void setPopulationSize(int sz){
		populationSize = sz;
	}

	void setMutationProb(int mp){
		MutationProb = mp;
	}

	void setCrossPoint(int cp){
		crossPoint = cp;
	}

	// Getters 
	int getGenesSize(){
		return genesSize;
	}

	int getPopulationSize(){
		return populationSize;
	}

	int getMutationProb(){
		return MutationProb;
	}

	int getCrossPoint(){

		return (crossPoint != 0 ) ? crossPoint : rand() % (genesSize-2) + 1; //greater than 0 || lower than genesize
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

	//Delegate function for fitness calculation
	Fitness ftn;

	void evalPopulation(){
		for(int i=0 ; i < populationSize ; i++){
			population[i].fitness = ftn(population[i]);
		}
	}

	void sortPopulation(bool great){
		
		// If greater == true, sort from greater to lower

		if(great){
			sort(population.begin(),population.end(), greater<Individual>());
		}else{
			sort(population.begin(),population.end());
		}
	}

	Individual CrossOver(Individual a, Individual b){
		Individual c;
		int cp = getCrossPoint();

		for(int i=0 ; i< genesSize; i++){
			if(i < cp)
				c.genes.push_back(a.genes[i]);
			else
				c.genes.push_back(b.genes[i]);


			//Get random number for mutation
			int mutNumber = random() % 101;

			if(mutNumber < MutationProb){
				c.genes[i] = (c.genes[i] == 0) ? 1 : 0;
			}
		}
		return c;
	}

	void crossTopIndividuals(int n){

		if(n > populationSize){
			printf("n is bigger than population size\n");
			return;
		}

		//priority_queue<Individual, vector<Individual>, greater<Individual> > pq;
		priority_queue<Individual> pq;
		// Introduce top original individuals to priority queue
		for(int i=0 ; i<n ; i++){
			pq.push(population[i]);
		}

		// Crossover all top n individuals
		for(int i=0 ; i<n-1; i++){
			for(int j=i+1; j<n ; j++){
				Individual newInd = CrossOver(population[i],population[j]);
				
				//Calculate and set fitness
				newInd.fitness = ftn(newInd);
				printIndividual(newInd);
				
				//add to Priority queue
				pq.push(newInd);
			}
		}

		// Replace old with new best individuals
		for(int i=0 ; i<populationSize; i++){
			population[i] = pq.top();
			pq.pop();
		}
	}

	AG(int gSize, int pobSize, int mp){
		setGenesSize(gSize);
		setPopulationSize(pobSize);
		setMutationProb(mp);
		generateRandomPopulation();
	}



};