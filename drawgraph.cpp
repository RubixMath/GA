//グラフを描画する



void DrawGraph(struct generation a){



  double r;



	//関数f(x)のグラフ

	ofstream ofsf("fgraph.dat");

	const int DIVISION=1000;

	const double GRAPH_INTERVAL=(RANGE_UP-RANGE_LOW)/DIVISION;

	for(int i=0;i<DIVISION;i++){

		ofsf	<<	(r=RANGE_LOW+i*GRAPH_INTERVAL)	<<	" "	<<	f(r)	<<	endl;	

	}

	ofsf.close();





	//GAで求まった点の描画

	ofstream ofsga("GAgraph.dat");

	for(int i=0;i<POPULATION;i++){

		ofsga	<<	GrayToValue(a.individual[i])	<<	" "	<<	a.individual[i].fitness	<<	endl;

	}

	ofsga.close();



	FILE *fp = popen("gnuplot","w"); 

  	if (fp == NULL) 

    		exit(0); 

  	else{

    		fputs("set terminal postscript eps \n",fp);

		fputs("set output \"~/cpp/others/GA\" \n",fp);



    		fputs("plot \"GAgraph.dat\" with points 3 5 \n",fp);

    		fputs("set output \"GAgraph.eps\" \n",fp);

 

    		fputs("replot \"fgraph.dat\" with lines \n",fp);

    		fflush(fp); 

    		cin.get(); 

    		pclose(fp); 

  	}

	return;
}
