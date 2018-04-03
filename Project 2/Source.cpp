//Alfred Albizures
//assignment 2 
//computer security class
//7/28/16


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int index = 0;
	int jindex = 0;

	int Alfa[256];
	//int permutated[256];
	char keyarr[256];

	char key[6] = { 'b','l','a','n','c','a' };
	//char key[3] = { 'K','E','Y' };
	int keysize = 6;

	//Created an array of numbers 255 of them starting from zero
	for (index = 0; index < 256; index++)
	{
		Alfa[index] = index;
		keyarr[index] = key[index%keysize];
	}

	//permuted run and swap 
	int j = 0;

	for (index = 0; index < 256; index++)
	{
		j = ((j + Alfa[index] + (static_cast<char>(keyarr[index]))) % 256);

		int temp;
		temp = Alfa[index];
		Alfa[index] = Alfa[j];
		Alfa[j] = temp;
	}

	string input;
	cout << "Please input the text" << endl;
	getline(cin, input);

	int TempNumOne = input.size();
	char Filename[1000];

	for (int index = 0; index < TempNumOne; index++)
	{
		Filename[index] = input[index];
	}

	 int ind = 0;
	 int jo = 0;
	int k;
	int counter = 0;
	while (TempNumOne>0)
	{

		
		ind = (ind + 1) % 256;
		jo = (jo + Alfa[ind]) % 256;

		int tempo;
		tempo = Alfa[ind];
		Alfa[ind] = Alfa[jo];
		Alfa[jo] = tempo;

		k = Alfa[(Alfa[ind] + Alfa[jo]) % 256];

		//cout << k  << endl;

		int t;

		t = k ^ Filename[counter];

		//cout << t << endl;

		std::cout << std::hex << t <<" "<< std::dec ;


		TempNumOne = TempNumOne - 1;
		counter++;
	}




	/*for (index = 0; index < 256; index++)
	{
		cout << Alfa[index]<< endl;
		
	}*/


	

  

	system("pause");

	return 0;

}