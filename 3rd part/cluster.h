#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <cmath>
#include <random>
#include <ctime>
#include <climits>
#include <unordered_map>


using namespace std;

#define COINSIZE 100


class myvector{
public:
	int id;
	int* points;
	long double* pointsd;
	long double* Cpointsd;
	long double Sa;
	long double Sb;
	long double mid;
	long double dis2;
	int d;
	bool type;
	int cluster;
	int ncluster;
	myvector(int,int*,int,bool);
	myvector(int,long double*,int,bool);
	~myvector();
};

struct listnode{
	myvector* ptr;
	listnode* next;
	int *g;
	listnode();
	~listnode();
};

class List{
private:
	int size;
public:
	listnode* head;
	List();
	~List();
    void insert(myvector*,int,int);
    void insertend(myvector*);
    bool is_empty();
    void display(ofstream&);
    int length();
    myvector* pointsum();
    myvector* medoid(int);
    long double Silhouette(myvector*,int);
    long double averageSilhouette();

};

long double euclidean_dist(long double*,long double*,int);

long double cosine_similarity(long double*,long double*,int);

long double inner_product(myvector*,myvector*);

myvector** RandomInit(int,myvector**,int);

myvector** Kmeansplusplus(int,myvector**,int,int);

List** LloydsAssign(int,myvector**,myvector**,int,int);

List** LSHrangeassign(int,myvector**,myvector**,int,int,int,int,int);

//List** CUBErangeassign(int,myvector**,myvector**,int,int,int,int,int);

myvector** Kmeansupdate(int,myvector**,int,List**);

myvector** PAMupdate(int,myvector**,int,List**,int);

long double* aSilhouette(int,myvector**,List**,int);

long double* bSilhouette(int,myvector**,List**,int);

long double* cSilhouette(List**,int);

void ClusteringRecommendation(myvector**,int,string names[COINSIZE],ofstream&,int,int);

