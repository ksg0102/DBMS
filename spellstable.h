class Spellstable
{
	private:
			//NAME,LEVEL,SCHOOL,CASTING_TIME,RANGE,COMPONENTS,DURATION
			string filename;
			string tablename;
			string key;
			int N; //tablesize
			
			struct item //struct that contains the hashtable variables
			{
				string name;
				string level;
				string school;
				string casting_time;
				string range;
				string components;
				string duration;
				item* next;
			};
			
			vector<item*> hashtable; //vector pointer that acts as hashtable
			vector<string> schemev; //scheme vector;
	public:
			Spellstable(int sts) //parameterized constructor that sets table size before running queries
			{
				N = sts;
			}
			~Spellstable() //destructor that empties vectors and frees memory
			{
				schemev.clear();
				hashtable.clear();
				vector<item*>(hashtable).swap(hashtable);
			}
			
			void setinfo(string tfile, string tname); //all necessary functions for hashtable
			void setfilename(string f){filename = f;}
			void settablename(string tn){tablename = tn;}
			void setkey(string k){key = k;}
			void filltable();
			int mhash(string key);
			void display();
			void insert(string temp);
			void update(string temp);
			void write();
			void select(string temp);
			void sonematch(string str[7], string t1);
			void smultimatch(string str[7], string t1);
			void deletet(string temp);
			void donematch(string str[7], string t1);
			void dmultimatch(string str[7], string t1);
			
};