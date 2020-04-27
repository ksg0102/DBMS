class Itemstable
{
	private:
			//ID,NAME,TYPE,RARITY,PRICE
			string filename;
			string tablename;
			string key;
			int N; //tablesize
			
			struct item //struct that contains the hashtable variables
			{
				string id;
				string name;
				string type;
				string rarity;
				string price;
				item* next;
			};
			
			vector<item*> hashtable; //vector pointer that acts as hashtable
			vector<string> schemev; //scheme vector;
	public:
			Itemstable(int its) //parameterized constructor that sets table size before running queries
			{
				N = its;
			}
			~Itemstable() //destructor that empties vectors and frees memory
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
			void sonematch(string str[5], string t1);
			void smultimatch(string str[5], string t1);
			void deletet(string temp);
			void donematch(string str[5], string t1);
			void dmultimatch(string str[5], string t1);
};