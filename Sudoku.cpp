// Sudoku.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <ObjectArray.h>
#include <cmath>
using namespace std;
struct Sudoku{
	int broj;
	bool proba;
} matrica[9][9];

void sudoku_tablica() {
	matrica[0][1].broj = 2;
	matrica[1][3].broj = 8;
	matrica[2][8].broj = 7;
	matrica[3][7].broj = 5;
	matrica[4][4].broj = 4;
	matrica[6][8].broj = 3;
	matrica[7][1].broj = 6;
	
   for(int i=0;i<9;i++){
	for(int j=0;j<9;j++){
		cout << matrica[i][j].broj << " ";
	}
	cout << endl;
}
}
bool pregled_retka(int redak,int stupac){
	for(int j=0;j<9;j++){
	if(j!=stupac)
		if(matrica[redak][j].broj == matrica[redak][stupac].broj)
		return false;
	}
	return true;
}
bool pregled_stupca(int redak,int stupac){
	for(int i=0;i<9;i++){
	if(i!=redak)
	if(matrica[i][stupac].broj == matrica[redak][stupac].broj)
		return false;
	}
	return true;
}
bool pregled_kocke(int redak,int stupac){
	int kocka_redak = redak/3;
	int kocka_stupac = stupac/3;
		for (int i = kocka_redak*3; i < (kocka_redak*3 + 3); i++){
		for (int j = kocka_stupac*3; j < (kocka_stupac*3 + 3); j++){
			if (!(i == redak && j == stupac)){
				if (matrica[redak][stupac].broj == matrica[i][j].broj)
				return false;
			}
		}
		}
	return true;
}
bool rijesi(int redak, int stupac){
		while (matrica[redak][stupac].proba == true) //provjera redaka i stupaca matrice
{
		stupac++;
		if(stupac > 8){
			stupac = 0;
			redak++;
		}
		if (redak > 8){
			return true;
		}
	}
	for (int n = 1; n < 10; n++){ //upis brojeva u 2d matricu
		int nextredak, nextstupac;
		matrica[redak][stupac].broj = n;
		if ( pregled_retka(redak, stupac) && pregled_stupca(redak, stupac) && pregled_kocke(redak,stupac)){
			nextredak = redak;
			nextstupac = stupac;
			nextstupac++;
			if(nextstupac > 8){
			nextstupac = 0;
			nextredak++;
			}
			if(nextstupac==0 && nextredak ==9){
			return true;
			}
			if(rijesi(nextredak,nextstupac)){
				return true;
			}
		}
	}
	matrica[redak][stupac].broj = 0;
	return false;	
}


int main() {
cout << " Sudoku tablica prije rijesavanja: " << endl;
sudoku_tablica();
cout << " Sudoku tablica nakon rijesavanja " << endl;
rijesi(0,0);
sudoku_tablica();
}
