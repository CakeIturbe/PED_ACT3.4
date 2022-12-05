// =================================================================
//
// File: main.cpp
// Author: DIEGO ITURBE BRAVO
// Date: 4/DEC/2022
//
// =================================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "heap.h"
using namespace std;

void openFile(ifstream& inFile,string fname){
	inFile.open(fname);
	if (inFile.is_open()){
		// cout << "Successfully opened file"<<endl;
	}
	else{
		cout << "Failed to open file" << endl;
		exit(-1);
	}
}

vector<string> processFile(ifstream& inFile,int i, int limit){
	//read line by line
	vector<string> content;
	string line;
	int cont=0;
	
	while (!inFile.eof() && i < limit){
		i++;
		getline(inFile,line);
		// bool found = line.find('.');
		//found == 1 == No se encontro punto
		if(inFile.good()){
			content.push_back(line);
			
		}
		cont++;

	} 
	return content;
}

int main(int argc, char* argv[]) {
	ifstream inFile;
	openFile(inFile,"input1.txt");
	//obtener linea 1
	vector<string> linea1 = processFile(inFile,0,1);
	stringstream nP(linea1[0]);
	int n;
    nP >> n;
    // cout<< n; 
    //print numero de entradas

	//numeros enteros=tamaños de las listas
    string linea;
    char delimiter= ' ';
    vector<string> linea2 = processFile(inFile,1,2);
	vector<string> nums;
	for (int i = 0; i < linea2.size(); i++){
		stringstream x(linea2[i]);
		while (getline(x, linea, delimiter)) {
        nums.push_back(linea);
		}
    
	}

    // for (int i = 0; i < nums.size(); i++)
    //     cout<<nums[i]<<" ";

    //inicializamos y emepzamos a añadir las entradas
    Heap<int> heap(n);
    int num;
    for (int i = 0; i < n; i++){
        stringstream x(nums[i]);
        x >> num;
        heap.add(num);
    }

    //suma de comparaciones
    int sum = 0;
    int comp = 0;
    for(int i = 0; i < n && heap.length() > 1; i++){
		sum = heap.remove() + heap.remove();
		heap.add(sum);
		comp = comp + sum - 1;
	}
    // comp= numero de comparaciones minimas, despliegue 
	cout << endl<< comp << endl;
	return 0;
}
