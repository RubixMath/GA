//xwindowはstartxwin"で起動

#include<iostream>
#include<fstream>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

//=========最適化する関数=========
#define f(x) sin(x)/(x)
//==========================


//============定数============
const int MAX_GENERATION  =50;		//世代数
const int POPULATION		=10;	//各世代の個体数

const int GENE_LENGTH		=15;	//遺伝子の長さ
const double RANGE_LOW	=-10;		//探索範囲の下限
const double RANGE_UP	=10;	//探索範囲の上限

const double INTERVAL=(RANGE_UP-RANGE_LOW)/pow(2,GENE_LENGTH);	//探索する幅

const double COPY_RATE		=0.5;	//そのまま次世代にコピーする割合
const double CROSS_RATE		=0.3;	//交叉率
const double MUTATION_RATE	=0.05;	//突然変異率
//===========================


//=========遺伝情報=============
//各個体
struct  individual{
	int gene[GENE_LENGTH];	//遺伝子
	double fitness;			//適合度
};

//各世代(現世代、次世代)
struct generation{
	struct individual individual[POPULATION];
}current,next;
//===========================


//=========初期化==============

//===========================

#include"initialize.cpp"
#include"random.cpp"
#include"expression.cpp"
#include"evolution.cpp"
#include"drawgraph.cpp"
