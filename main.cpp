#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

#include "spellstable.h"
#include "itemstable.h"
#include "customerstable.h"

int settablesize(string tfile, string tname); //function declaration

int main()
{
	ifstream fin;
	ofstream fout;
	string filename;
	string tfile; //variable for the table file name
	string tname; //variable for the table name
	string temp; //string variable used for reading in lines from user defined file
	int sts; //spells tablesize value
	int its; //items tablesize value
	int cts; //customers tablesize value
	
	fout.open("output.dat"); //opens a file named output.dat if it does not already exist, for displaying/storing hashtable data values
	fout.close();
	fout.open("spells_output.dat"); //opens a file named spells_output.dat if it does not already exist, for storing spells table data values
	fout.close();
	fout.open("items_output.dat"); //opens a file named items_output.dat if it does not already exist, for storing items table data values
	fout.close();
	fout.open("customers_output.dat"); //opens a file named customers_output.dat if it does not already exist, for storing customers table data values
	fout.close();
	
	cout << endl << "Please enter file name: ";
	getline(cin, filename);
	
	fin.open(filename.c_str());
	if(fin.fail())
	{
		cout << endl << "File does not exist." << endl << endl;
		return 0;
	}
	
	for(int i = 0; i < 3; ++i)
	{
		getline(fin, tfile, ' ');
		getline(fin, tname);
		if(tname == "spells")
		{
			sts = settablesize(tfile, tname); //set tablesize variable for spells
		}
		else if(tname == "items")
		{
			its = settablesize(tfile, tname); //set tablesize variable for items
		}
		else if(tname == "customers")
		{
			cts = settablesize(tfile, tname); //set tablesize variable for customers
		}	
	}
	fin.close();
	
	Spellstable spells(sts); //object created/parameterized constructor for spells, sets tablesize of spells hashtable
	Itemstable items(its); //object created/parameterized constructor for items, sets tablesize of items hashtable
	Customerstable customers(cts); //object created/parameterized constructor for customers, sets tablesize of customers hashtable
	
	fin.open(filename.c_str());
	for(int i = 0; i < 3; ++i) //sets filename and table name for spells,customers,items hashtables
	{
		getline(fin, tfile, ' ');
		getline(fin, tname);
		if(tname == "spells")
		{
			spells.setinfo(tfile, tname); //set spells filename and table name
		}
		else if(tname == "items")
		{
			items.setinfo(tfile, tname); //set items filename and table name
		}
		else if(tname == "customers")
		{
			customers.setinfo(tfile, tname); //set customers filename and table name
		} 
	}
	fin.close();
	
	spells.filltable(); //fills hashtable with initial data values
	items.filltable(); //fills hashtable with initial data values
	customers.filltable(); //fills hashtable with initial data values
	
	fin.open(filename.c_str());
	for(int i = 0; i < 4; ++i)
	{
		getline(fin, temp); //dummy lines that read in the first for rows of the input file
	}
	
	while(getline(fin, temp)) //now reads in the queries
	{
		if(temp.find("DISPLAY") != string::npos) //if display query is found in the input file
		{
			fout.open("output.dat", ios::app);
			fout << endl;
			fout.close();
			spells.display(); //display current state of spells table
			items.display(); //display current state of items table
			customers.display(); //display current state of customers table
		}
		else if(temp.find("INSERT") != string::npos) //if insert query is found in the input file
		{
			if(temp.find("spells") != string::npos)
			{
				spells.insert(temp); //calls insert function, passing the tuple
			}
			else if(temp.find("items") != string::npos)
			{	
				items.insert(temp); //calls insert function, passing the tuple
			}
			else if(temp.find("customers") != string::npos)
			{
				customers.insert(temp); //calls insert function, passing the tuple
			}
		}
		else if(temp.find("UPDATE") != string::npos) //if update query is found in the input file
		{
			if(temp.find("spells") != string::npos)
			{
				spells.update(temp); //calls update function, passing the tuple
			}
			else if(temp.find("items") != string::npos)
			{	
				items.update(temp); //calls update function, passing the tuple
			}
			else if(temp.find("customers") != string::npos)
			{
				customers.update(temp); //calls update function, passing the tuple
			}
		}
		else if(temp.find("SELECT") != string::npos) //if select query is found in the input file
		{
			if(temp.find("spells") != string::npos)
			{
				spells.select(temp); //calls select function, passing tuple
			}
			else if(temp.find("items") != string::npos)
			{	
				items.select(temp); //calls select function, passing tuple
			}
			else if(temp.find("customers") != string::npos)
			{
				customers.select(temp); //calls select function, passing tuple
			}
		}
		else if(temp.find("DELETE") != string::npos) //if delete query is found in the input file
		{
			if(temp.find("spells") != string::npos)
			{
				spells.deletet(temp); //calls delete function, passing tuple
			}
			else if(temp.find("items") != string::npos)
			{	
				items.deletet(temp); //calls delete function, passing tuple
			}
			else if(temp.find("customers") != string::npos)
			{
				customers.deletet(temp); //calls delete function, passing tuple
			}
		}
		else if(temp.find("WRITE") != string::npos) //if write query is found in the input file
		{
			spells.write(); //write spells table data into respective file
			items.write(); //write items table data into respective file
			customers.write(); //write customers table data into respective file
		} 
	}
	fin.close();
	
	cout << endl << "All table data queries and output successfully stored in output.dat file." << endl;
	cout << endl << "Spells table data stored in spells_output.dat file." << endl;
	cout << "Items table data stored in items_output.dat file." << endl;
	cout << "Customers table data stored in customers_output.dat file." << endl << endl;
	
return 0;
}

int settablesize(string tfile, string tname) //function that returns sets table size
{
	int N = 0;
	string temp;
	ifstream fin;
	
	fin.open(tfile.c_str());
	
	getline(fin, temp);
	getline(fin, temp);
	while(getline(fin, temp))
	{
		++N;
	}
	fin.close();
	
return N; //returns table size
}