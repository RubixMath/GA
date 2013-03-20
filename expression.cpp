//グレイ表現をバイナリ表現に直す

struct individual GrayToBinary(struct individual gray){

  struct individual binary;

	binary.gene[GENE_LENGTH-1]=gray.gene[GENE_LENGTH-1];

	for(int i=GENE_LENGTH-2;i>=0;i--){

		binary.gene[i]=(binary.gene[i+1] ^ gray.gene[i]);

	}

	return binary;

}



//バイナリ表現をグレイ表現に直す

struct individual BinaryToGray(struct individual binary){

	struct individual gray;

	gray.gene[GENE_LENGTH-1]=binary.gene[GENE_LENGTH-1];	

	for(int i=GENE_LENGTH-2;i>=0;i--){

		gray.gene[i]=(binary.gene[i] ^ binary.gene[i+1]);

	}

	return gray;

}



//バイナリ表現の遺伝子を表現型に

double BinaryToValue(struct individual binary){

	double tmp=RANGE_LOW;

	for(int i=0;i<GENE_LENGTH;i++){

		tmp+=INTERVAL*binary.gene[i]*pow(2,i);

	}

	return tmp;

}



//グレイ表現の遺伝子を表現型に

double GrayToValue(struct individual gray){

	struct individual binary=GrayToBinary(gray);

	return BinaryToValue(binary);

}



//個体aの遺伝子を表示する

void ShowIndividual(struct individual a){

	for(int i=GENE_LENGTH-1;i>=0;i--){

		cout<<a.gene[i]<<",";

	}

	return;

}



//世代aの個体の遺伝子を全て表示する

void ShowGeneration(struct generation a){

	for(int i=0;i<POPULATION;i++){

		cout	<<	"individual "	<<	i	<<	":"	;

		ShowIndividual(a.individual[i]);

		cout	<<	"\t"	<<	"(GTYPE:"	<<	GrayToValue(a.individual[i])	<<	","

			<<	"fitness:"	<<	a.individual[i].fitness	<<	")"	<<	endl;

	}

	return;

}
