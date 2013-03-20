//個体aの遺伝子を初期化する(set 0)

void InitializeIndividual(struct individual *a){

  for(int i=0;i<GENE_LENGTH;i++){

		(*a).gene[i]=0;

	}

	return;

}



//世代aの個体を全て初期化する

void InitializeGeneration(struct generation *a){

	for(int i=0;i<POPULATION;i++){

		InitializeIndividual(&((*a).individual[i]));		

	}

	return;

}
