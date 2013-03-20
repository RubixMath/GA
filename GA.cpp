#include"GA.h"

int main(void){

  srand((unsigned) time(NULL));	//乱数の初期化

	InitializeGeneration(&current);	//現世代の初期化
	InitializeGeneration(&next);		//次世代の初期化

	DesignateRanking();			//ランキング選択の比率を作成する

	for(int i=0;i<MAX_GENERATION;i++){
		cout	<<	"=====generation ["	<<	i	<<	"]====="	<<endl;
		ShowGeneration(current);

		next=Evolution(current);		//進化
		current=next;
	}

	DrawGraph(current);	//グラフの描画

	return 0;
}
