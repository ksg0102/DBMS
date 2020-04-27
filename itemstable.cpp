#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace std;

#include "itemstable.h"

void Itemstable::donematch(string str[5], string t1) //function used for delete query, where there was one match
{ 
	ofstream fout;
	int match = 0;
	int index1 = 0;
	vector<int> ivec; //integer array that holds position where hashtable and the string array match
	
	for(int i = 0; i < N; ++i) //nested for loop that compares the string array and the hashtable
	{
		for(int j = 0; j < 5; ++j)
		{
			if(str[j] != "*") //finds where the string array is not a *
			{
				if(hashtable[i]->id == str[j])
				{
					fout.open("output.dat", ios::app);
					fout <<"Deleted (" << hashtable[i]->id << "|" << hashtable[i]->name << "|" << hashtable[i]->type << "|" << hashtable[i]->rarity << "|" << hashtable[i]->price << ")" << " from items" << endl;
					fout.close();
					match = 1; //match found
					ivec.push_back(i); //stores the position where hashtable and string array match
				}
				if(hashtable[i]->name == str[j])
				{
					fout.open("output.dat", ios::app);
					fout <<"Deleted (" << hashtable[i]->id << "|" << hashtable[i]->name << "|" << hashtable[i]->type << "|" << hashtable[i]->rarity << "|" << hashtable[i]->price << ")" << " from items" << endl;
					fout.close();
					match = 1;
					ivec.push_back(i);
				}
				if(hashtable[i]->type == str[j])
				{
					fout.open("output.dat", ios::app);
					fout <<"Deleted (" << hashtable[i]->id << "|" << hashtable[i]->name << "|" << hashtable[i]->type << "|" << hashtable[i]->rarity << "|" << hashtable[i]->price << ")" << " from items" << endl;
					fout.close();
					match = 1;
					ivec.push_back(i);
				}
				if(hashtable[i]->rarity== str[j])
				{
					fout.open("output.dat", ios::app);
					fout <<"Deleted (" << hashtable[i]->id << "|" << hashtable[i]->name << "|" << hashtable[i]->type << "|" << hashtable[i]->rarity << "|" << hashtable[i]->price << ")" << " from items" << endl;
					fout.close();
					match = 1;
					ivec.push_back(i);
				}
				if(hashtable[i]->price == str[j])
				{
					fout.open("output.dat", ios::app);
					fout <<"Deleted (" << hashtable[i]->id << "|" << hashtable[i]->name << "|" << hashtable[i]->type << "|" << hashtable[i]->rarity << "|" << hashtable[i]->price << ")" << " from items" << endl;
					fout.close();
					match = 1;
					ivec.push_back(i);
				}
			}
		}	
	}

	if(match != 1) //if match not found, let user know that program failed to delete
	{
		fout.open("output.dat", ios::app);
		for(int i = 0; i < t1.length() - 1; ++i)
		{
			if(t1.at(i) == ')')
			{
				index1 = i + 1;
			}
		}
		t1 = t1.substr(0, index1);
		fout << "Failed to delete (" << t1 << " from items" << endl;
		fout.close();
	}
	for(int i = 0; i < ivec.size(); ++i) //for loop that iterates through the integer vector and deletes each position where there was a match
	{
		hashtable.erase(hashtable.begin() + ivec[i]); //delete at position ivec[i]
		ivec[i+1] = ivec[i+1] - 1; //next position subtracted by 1 to make up for deleted row in hashtable
		N -= 1; //decrement table size each time row is deleted
	}
	ivec.clear();
}

void Itemstable::dmultimatch(string str[5], string t1) //function used for delete query, where there was more than one match
{
	ofstream fout;
	int match = 0;
	int index1 = 0;
	
	for(int i = 0; i < N; ++i) //nested for loop comparing string array and hashtable data
	{
		for(int j = 0; j < 5; ++j)
		{
			if(str[j] != "*") //finds where the string array is not a *
			{	
				if(hashtable[i]->id != str[j]) //whenever the hashtable does not equal to the values in the string array, set match to -1
				{
					match = -1;
				}
				if(hashtable[i]->name != str[j])
				{
					match = -1;
				}
				if(hashtable[i]->type != str[j])
				{
					match = -1;
				}
				if(hashtable[i]->rarity!= str[j])
				{
					match = -1;
				}
				if(hashtable[i]->price != str[j])
				{
					match = -1;
				}
			}
		}	
	}
	if(match == -1) //if match was not found, let user know that the program failed to delete
	{
		fout.open("output.dat", ios::app);
		for(int i = 0; i < t1.length() - 1; ++i)
		{
			if(t1.at(i) == ')')
			{
				index1 = i + 1;
			}
		}
		t1 = t1.substr(0, index1);
		fout << "Failed to delete (" << t1 << " from items" << endl;
		fout.close();
	}
}

void Itemstable::sonematch(string str[5], string t1) //function used for select query, where there was more than one match
{
	ofstream fout;
	int match = 0;
	int index1 = 0;
	
	for(int i = 0; i < N; ++i) //nested for loop comparing the string array and the hashtable data
	{
		for(int j = 0; j < 5; ++j)
		{
			if(str[j] != "*") //finds where the string array is not a * 
			{
				if(hashtable[i]->id == str[j]) //whenever ther is a match, set match to 1 and let user know that the tuple was found
				{
					fout.open("output.dat", ios::app);
					fout <<"Found (" << hashtable[i]->id << "|" << hashtable[i]->name << "|" << hashtable[i]->type << "|" << hashtable[i]->rarity << "|" << hashtable[i]->price << ")" << " in items" << endl;
					fout.close();
					match = 1;
				}
				if(hashtable[i]->name == str[j])
				{
					fout.open("output.dat", ios::app);
					fout <<"Found (" << hashtable[i]->id << "|" << hashtable[i]->name << "|" << hashtable[i]->type << "|" << hashtable[i]->rarity << "|" << hashtable[i]->price << ")" << " in items" << endl;
					fout.close();
					match = 1;
				}
				if(hashtable[i]->type == str[j])
				{
					fout.open("output.dat", ios::app);
					fout <<"Found (" << hashtable[i]->id << "|" << hashtable[i]->name << "|" << hashtable[i]->type << "|" << hashtable[i]->rarity << "|" << hashtable[i]->price << ")" << " in items" << endl;
					fout.close();
					match = 1;
				}
				if(hashtable[i]->rarity== str[j])
				{
					fout.open("output.dat", ios::app);
					fout <<"Found (" << hashtable[i]->id << "|" << hashtable[i]->name << "|" << hashtable[i]->type << "|" << hashtable[i]->rarity << "|" << hashtable[i]->price << ")" << " in items" << endl;
					fout.close();
					match = 1;
				}
				if(hashtable[i]->price == str[j])
				{
					fout.open("output.dat", ios::app);
					fout <<"Found (" << hashtable[i]->id << "|" << hashtable[i]->name << "|" << hashtable[i]->type << "|" << hashtable[i]->rarity << "|" << hashtable[i]->price << ")" << " in items" << endl;
					fout.close();
					match = 1;
				}
			}
		}	
	}
	if(match != 1) //if match was not found, let user know that the program did not find a match
	{
		fout.open("output.dat", ios::app);
		for(int i = 0; i < t1.length() - 1; ++i)
		{
			if(t1.at(i) == ')')
			{
				index1 = i + 1;
			}
		}
		t1 = t1.substr(0, index1);
		fout << "No entries match query (" << t1 << " in items" << endl;
		fout.close();
	}
}

void Itemstable::smultimatch(string str[5], string t1) //function used for select query, where there was more than one match
{
	ofstream fout;
	int match = 0;
	int index1 = 0;
	
	for(int i = 0; i < N; ++i) //nested for loop comparing the string array and the hashtable data
	{
		for(int j = 0; j < 5; ++j)
		{
			if(str[j] != "*") //finds where the string array is not a * 
			{	
				if(hashtable[i]->id != str[j]) //if there is no match, set match to -1
				{
					match = -1;
				}
				if(hashtable[i]->name != str[j])
				{
					match = -1;
				}
				if(hashtable[i]->type != str[j])
				{
					match = -1;
				}
				if(hashtable[i]->rarity!= str[j])
				{
					match = -1;
				}
				if(hashtable[i]->price != str[j])
				{
					match = -1;
				}
			}
		}	
	}
	if(match == -1) //if match was not found, let user know that the program did not find tuple
	{
		fout.open("output.dat", ios::app);
		for(int i = 0; i < t1.length() - 1; ++i)
		{
			if(t1.at(i) == ')')
			{
				index1 = i + 1;
			}
		}
		t1 = t1.substr(0, index1);
		fout << "No entries match query (" << t1 << " in items" << endl;
		fout.close();
	}
}

int Itemstable::mhash(string key) //string multiplicative hashing
{ 
	int initval = 0; //position set to 0
	int multi = 5; //multiplier set to 5
	 
	for(char c : key) //for each character in key
	{
		initval = (initval*multi) + c; //set position equal to position*multiplier + ascii value of character
	}
	
return (initval % N); //return position mod table size
}

void Itemstable::setinfo(string tfile, string tname) //function with mutator function that sets file name and table name for future use
{
	setfilename(tfile);
	settablename(tname);
}

void Itemstable::filltable() //function that fills the hashtable with initial values from input file
{
	string temp1;
	ifstream fin;
	
	hashtable.resize(N); //initializes hashtable with table size using resize since hashtable was not initialized at declaration
	for(int i = 0; i < N; ++i)
	{
		hashtable[i] == NULL; //sets newly created vector pointers to NULL for collision strategy
	}
	
	fin.open(filename.c_str());
	
	getline(fin, temp1); //grabs key
	setkey(temp1); //sets key
	
	for(int i = 0; i < 4; ++i) //for loop that sets scheme vector to scheme values
	{
		getline(fin, temp1, ',');
		schemev.push_back(temp1);
	}
	
	getline(fin, temp1);
	schemev.push_back(temp1);
	
	int bucket = mhash(key); //calling hash function and returns bucket for collision strategy
	int probed = 0;
	
	while(probed < N) //linear probing collision strategy
	{
		if(hashtable[bucket] == NULL) //if hashtable[bucket] is empty, set hashtable variables to data values from tuples
		{
			hashtable[bucket] = new item; //set hashtable[bucket] to new struct item for initialization
			getline(fin, temp1, '|');
			hashtable[bucket]->id = temp1;
			getline(fin, temp1, '|');
			hashtable[bucket]->name = temp1;
			getline(fin, temp1, '|');
			hashtable[bucket]->type = temp1;
			getline(fin, temp1, '|');
			hashtable[bucket]->rarity = temp1;
			getline(fin, temp1);
			hashtable[bucket]->price = temp1;
			hashtable[bucket]->next = NULL; //next value in item struct where hashtable[bucket], point to empty value
		}
		
		bucket = (bucket + 1) % N; //set a new bucket value
		++probed; //increment probed value
	}
	fin.close();
}

void Itemstable::display() //displays current data values in hashtable
{
	ofstream fout;
	
	fout.open("output.dat", ios::app);
	for(int i = 0; i < 5; ++i)
	{
		fout << left << setw(21) << schemev[i];
	}
	fout << endl;
	
	for(int i = 0; i < N; ++i)
	{
		fout << left << setw(21) << hashtable[i]->id;
		fout << left << setw(21) << hashtable[i]->name;
		fout << left << setw(21) << hashtable[i]->type;
		fout << left << setw(21) << hashtable[i]->rarity;
		fout << left << setw(21) << hashtable[i]->price << endl;
	}
	fout << endl;
	fout.close();
}

void Itemstable::insert(string temp) //function that inserts new data
{
	ofstream fout;
	string t1; //string that holds string tuples from file
	string t2; //data value from tuple
	int l; //length of string
	int sl = 8; //operation length to subtract from total string length
	int index1 = 8; //index for substr function to begin parsing
	int index2 = 0; //index for substr that will be placed into hashtable
	int count = 0; //count each time there is a new data value to insert
	int bucket1; //bucket that will be used for the rest of the data
	char condition; //condition for failed insert
	
	l = temp.length();
	l -= sl;
	t1 = temp.substr(index1, l); //creates a better string to use for breaking down data values
	
	for(int i = 0; i < t1.length(); ++i)
	{
		if(t1.at(i) == '|' && count == 0)
		{	
			t2 = t1.substr(index2, i); //string holding the value from tuple for insertion
			setkey(t2); //sets key
			for(int i = 0; i < N; ++i) //loop that checks if the key already exists in the hashtable
			{
				if(hashtable[i]->id == key)
				{
					fout.open("output.dat", ios::app);
					for(int i = 0; i < t1.length() - 1; ++i)
					{
						if(t1.at(i) == ')')
						{
							index1 = i + 1;
						}
					}
					t1 = t1.substr(0, index1);
					fout << "Failed to insert (" << t1 << " into " << tablename << endl;
					fout.close();
					condition = 'b'; //sets condition to 'b'
				}
			}
			if(condition == 'b') //if condition is 'b' then insert failed and returns to main
			{
				return;
			}
			
			N += 1; //adds one to the table size
			hashtable.resize(N); //makes the hashtable new size
			hashtable[N] = NULL; //sets newly created vector pointer to NULL for collision strategy
			
			int bucket = mhash(key); //calling hash function and returns bucket for collision strategy
			int probed = 0;
			
			while(probed < N) //linear probing collision strategy
			{
				if(hashtable[bucket] == NULL) //if hashtable[bucket] is empty, set hashtable variables to data values from tuples
				{
					hashtable[bucket] = new item; //set hashtable[bucket] to new struct item for initialization
					hashtable[bucket]->id = t2;
					bucket1 = bucket; //set bucket1 to bucket for further initialization of pointer variables
				}
		
				bucket = (bucket + 1) % N;
				++probed;
			}
			++count; //increment count
			index2 = i + 1; //set new index to break down tuple data value
			l = i; //set length to the last iteration of '|'
		}
		else if(t1.at(i) == '|' && count == 1)
		{
			l = i - l - 1;
			t2 = t1.substr(index2, l);
			hashtable[bucket1]->name = t2;
			++count;
			index2 = i + 1;
			l = i; //set length to the last iteration of '|'
		}
		else if(t1.at(i) == '|' && count == 2)
		{
			l = i - l - 1;
			t2 = t1.substr(index2, l);
			hashtable[bucket1]->type= t2;
			++count;
			index2 = i + 1;
			l = i; //set length to the last iteration of '|'
		}
		else if(t1.at(i) == '|' && count == 3)
		{
			l = i - l - 1;
			t2 = t1.substr(index2, l);
			hashtable[bucket1]->rarity = t2;
			++count;
			index2 = i + 1;
			l = i; //set length to the last iteration of '|'
		}
		else if(t1.at(i) == ')' && count == 4)
		{
			l = i - l - 1;
			t2 = t1.substr(index2, l);
			hashtable[bucket1]->price = t2;
			++count;
			index2 = i + 1;
			l = i; //set length to the last iteration of '|'
			hashtable[bucket1]->next = NULL;
		}
	}
	
	fout.open("output.dat", ios::app);
	for(int i = 0; i < t1.length() - 1; ++i) //let user know insertion complete
	{
		if(t1.at(i) == ')')
		{
			index1 = i + 1;
		}
	}
	t1 = t1.substr(0, index1);
	fout << "Inserted (" << t1 << " into " << tablename << endl;
	fout.close();
}

void Itemstable::update(string temp)
{
	ofstream fout;
	string t1; //string that holds string tuples from file
	string t2; //data value from tuple 
	int l; //length of string
	int sl = 8; //operation length to subtract from total string length
	int index1 = 8; //index for substr function to begin parsing
	int index2 = 0; //index for substr that will be placed into hashtable
	int count = 0; //count each time there is a new data value to insert
	char condition = 'b'; //condition for failed update
	
	l = temp.length();
	l -= sl;
	t1 = temp.substr(index1, l);  //creates a better string to use for breaking down data values

	for(int i = 0; i < t1.length(); ++i) //creates a better string to use for breaking down data values
	{
		if(t1.at(i) == '|' && count == 0)
		{
			t2 = t1.substr(index2, i); //string holding the value from tuple for insertion
			setkey(t2); //sets key
			for(int i = 0; i < N; ++i)
			{
				if(hashtable[i]->id == key)
				{
					index1 = i; //set index1 to i to update other data values in tuple in the hash table
					condition = 'a';
				}
			}
			if(condition == 'b') //if match not found, let user know failed update, return to main
			{
				fout.open("output.dat", ios::app);
				for(int i = 0; i < t1.length() - 1; ++i)
				{
					if(t1.at(i) == ')')
					{
						index1 = i + 1;
					}
				}
				t1 = t1.substr(0, index1);
				fout << "Failed to update (" << t1 << " in " << tablename << endl;
				fout.close();
				return;
			}
			++count;
			index2 = i + 1;
			l = i; //set length to the last iteration of '|'
		}
		else if(t1.at(i) == '|' && count == 1)
		{
			l = i - l - 1;
			t2 = t1.substr(index2, l);
			hashtable[index1]->name = t2;
			++count;
			index2 = i + 1;
			l = i; //set length to the last iteration of '|'
		}
		else if(t1.at(i) == '|' && count == 2)
		{
			l = i - l - 1;
			t2 = t1.substr(index2, l);
			hashtable[index1]->type = t2;
			++count;
			index2 = i + 1;
			l = i; //set length to the last iteration of '|'
		}
		else if(t1.at(i) == '|' && count == 3)
		{
			l = i - l - 1;
			t2 = t1.substr(index2, l);
			hashtable[index1]->rarity = t2;
			++count;
			index2 = i + 1;
			l = i; //set length to the last iteration of '|'
		}
		else if(t1.at(i) == '|' && count == 4)
		{
			l = i - l - 1;
			t2 = t1.substr(index2, l);
			hashtable[index1]->price = t2;
			++count;
			index2 = i + 1;
			l = i; //set length to the last iteration of '|'
		}
	}
	
	fout.open("output.dat", ios::app);
	for(int i = 0; i < t1.length() - 1; ++i) //let user know, update successful
	{
		if(t1.at(i) == ')')
		{
			index1 = i + 1;
		}
	}
	t1 = t1.substr(0, index1);
	fout << "Updated (" << t1 << " in " << tablename << endl;
	fout.close();

}

void Itemstable::write() //function that outputs hashtable data into particular file
{
	ofstream fout;
	
	fout.open("items_output.dat", ios::app);
	
	fout << schemev[0] << endl;
	for(int i = 0; i < 4; ++i)
	{
		fout << schemev[i] << ",";
	}
	fout << schemev[4] << endl;
	
	for(int i = 0; i < N; ++i)
	{
		fout << hashtable[i]->id << "|";
		fout << hashtable[i]->name << "|";
		fout << hashtable[i]->type << "|";
		fout << hashtable[i]->rarity << "|";
		fout << hashtable[i]->price << endl;
	}
	fout.close();
}

void Itemstable::select(string temp) //function that outputs at query tuple
{
	ofstream fout;
	string str[5]; //arrary of strings that holds tuple data
	string t1; //string that holds string tuples from file
	string t2; //data value from tuple 
	int l; //length of string
	int sl = 8; //operation length to subtract from total string length
	int index1 = 8; //index for substr function to begin parsing
	int index2 = 0; //index for substr that will be placed into hashtable
	int count = 0; //count each time there is a new data value to insert
	int snum = 0; 
	
	l = temp.length();
	l -= sl;
	t1 = temp.substr(index1, l);  //creates a better string to use for breaking down data values

	for(int i = 0; i < t1.length(); ++i) //for loop that breaks down data from query tuple
	{
		if(t1.at(i) == '|' && count == 0)
		{
			t2 = t1.substr(index2, i); //string holding the value from tuple for insertion
			str[0] = t2; //stores value of t2 into string array
			++count;
			index2 = i + 1;
			l = i; //set length to the last iteration of '|'
		}
		else if(t1.at(i) == '|' && count == 1)
		{
			l = i - l - 1;
			t2 = t1.substr(index2, l);
			str[1] = t2;
			++count;
			index2 = i + 1;
			l = i; //set length to the last iteration of '|'
		}
		else if(t1.at(i) == '|' && count == 2)
		{
			l = i - l - 1;
			t2 = t1.substr(index2, l);
			str[2] = t2;
			++count;
			index2 = i + 1;
			l = i; //set length to the last iteration of '|'
		}
		else if(t1.at(i) == '|' && count == 3)
		{
			l = i - l - 1;
			t2 = t1.substr(index2, l);
			str[3] = t2;
			++count;
			index2 = i + 1;
			l = i; //set length to the last iteration of '|'
		}
		else if(t1.at(i) == ')' && count == 4)
		{
			l = i - l - 1;
			t2 = t1.substr(index2, l);
			str[4] = t2;
			++count;
			index2 = i + 1;
			l = i; //set length to the last iteration of '|'
		}
	}
	
	for(int i = 0; i < N; ++i) //if all match, output data
	{ 
		if(hashtable[i]->id == str[0] && hashtable[i]->name == str[1] && hashtable[i]->type == str[2] && hashtable[i]->rarity == str[3] && hashtable[i]->price == str[4])
		{
			fout.open("output.dat", ios::app);
			for(int i = 0; i < t1.length() - 1; ++i)
			{
				if(t1.at(i) == ')')
				{
					index1 = i + 1;
				}
			}
			t1 = t1.substr(0, index1);
			fout << "Found (" << t1 << " in items" << endl;
			fout.close();
			return;
		}
	}

	for(int i = 0; i < 5; ++i) //calls function when 1 string found
	{
		if(str[i] != "*")
		{
			++snum;
		}
	}
	if(snum == 1) //calls function when 1 string found
	{
		sonematch(str, t1);
		return;
	}
	else if(snum >= 2) //calls function when 2 or more strings found
	{
		smultimatch(str, t1);
		return;
	}
}

void Itemstable::deletet(string temp) //function to delete from hashtable
{
	ofstream fout;
	string str[5]; //arrary of strings that holds tuple data
	string t1; //string that holds string tuples from file
	string t2; //data value from tuple 
	int l; //length of string
	int sl = 8; //operation length to subtract from total string length
	int index1 = 8; //index for substr function to begin parsing
	int index2 = 0; //index for substr that will be placed into hashtable
	int count = 0;
	int snum = 0;
	
	l = temp.length();
	l -= sl;
	t1 = temp.substr(index1, l);  //creates a better string to use for breaking down data values

	for(int i = 0; i < t1.length(); ++i)
	{
		if(t1.at(i) == '|' && count == 0)
		{
			t2 = t1.substr(index2, i); //string holding the value from tuple for insertion
			str[0] = t2; //stores value of t2 into string array
			++count;
			index2 = i + 1;
			l = i; //set length to the last iteration of '|'
		}
		else if(t1.at(i) == '|' && count == 1)
		{
			l = i - l - 1;
			t2 = t1.substr(index2, l);
			str[1] = t2;
			++count;
			index2 = i + 1;
			l = i; //set length to the last iteration of '|'
		}
		else if(t1.at(i) == '|' && count == 2)
		{
			l = i - l - 1;
			t2 = t1.substr(index2, l);
			str[2] = t2;
			++count;
			index2 = i + 1;
			l = i; //set length to the last iteration of '|'
		}
		else if(t1.at(i) == '|' && count == 3)
		{
			l = i - l - 1;
			t2 = t1.substr(index2, l);
			str[3] = t2;
			++count;
			index2 = i + 1;
			l = i; //set length to the last iteration of '|'
		}
		else if(t1.at(i) == ')' && count == 4)
		{
			l = i - l - 1;
			t2 = t1.substr(index2, l);
			str[4] = t2;
			++count;
			index2 = i + 1;
			l = i; //set length to the last iteration of '|'
		}
	}
	
	for(int i = 0; i < N; ++i) //if all match, output data
	{
		if(hashtable[i]->id == str[0] && hashtable[i]->name == str[1] && hashtable[i]->type == str[2] && hashtable[i]->rarity == str[3] && hashtable[i]->price == str[4])
		{
			hashtable.erase(hashtable.begin() + i);
			N -= 1;
			fout.open("output.dat", ios::app);
			for(int i = 0; i < t1.length() - 1; ++i)
			{
				if(t1.at(i) == ')')
				{
					index1 = i + 1;
				}
			}
			t1 = t1.substr(0, index1);
			fout << "Deleted (" << t1 << " from items" << endl;
			fout.close();
			return;
		}
	}

	for(int i = 0; i < 5; ++i) //calls function when 1 string found
	{
		if(str[i] != "*")
		{
			++snum;
		}
	}
	if(snum == 1) //calls function when 1 string found
	{
		donematch(str, t1);
		return;
	}
	else if(snum >= 2) //calls function when 2 or more strings found
	{
		dmultimatch(str, t1);
		return;
	}
}