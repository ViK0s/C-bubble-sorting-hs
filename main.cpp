#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
using namespace std;

void sortowaniebabelkowe(int tab[], int dl) {
	for(int h = 0; h < dl; h++){
		for(int j = 0; j < dl; j++)
		if(tab[j] < tab[j+1]) {
			int tmp = tab[j];
			tab[j] = tab[j+1];
			tab[j+1] = tmp;
		}
	}
}
void sortowanie(int tab[], int prawy, int lewy) {
	if(prawy <= lewy) return;
	int i = lewy-1;
	int j = prawy+1;
	int pivot = tab[(lewy+prawy)/2];
	while(1){
		while(pivot>tab[++i]);
		while(pivot<tab[--j]);
		if(i<=j){
			int tmp=tab[i];
			tab[i]=tab[j];
			tab[j]=tmp;
		}
		else break;
	}
	if(j>lewy)sortowanie(tab, j, lewy);
	if(i<prawy)sortowanie(tab, prawy, i);
}



int main(int argc, char** argv) {
	int dl = 10;
	int t[dl];
	srand(time(NULL));
	for(int b = 0; b < dl; b++){
		t[b] = rand() % 100;
	}
	cout<<"Tablica przed posortowaniem"<<endl;
	for(int a = 0; a < dl; a++){
		cout<<t[a]<<endl;
	}
	
	sortowanie(t, dl, 0);
	
	cout<<"Tablica po posortowaniu"<<endl;
	for(int l = 0; l < dl; l++) {
		cout<<t[l]<<endl;
	}
	
	
	return 0;
}
