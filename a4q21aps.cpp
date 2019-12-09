#include <iostream>
#include <bits/stdc++.h>
#include <iterator>

#define ll long long int
#define ull unsigned long long int
#define max_size 700000
#define prime_no 786433

using namespace std;

template <typename T1,typename T2>
struct keyvalue
{
	T1 key;
	T2 value;
};

template <typename T1,typename T2>
class unorderedmap
{
	list<keyvalue<T1, T2> > *ump;
	
	public:
	unorderedmap()
	{
	//	static T2 value;
		ump = new list<keyvalue<T1,T2> >[max_size];
	}
	
	ll calculatehash(T1 key)
	{
		ostringstream oss;
		oss << key;
		string st = oss.str();
		ull result = 0;
		ull a = 31;
		ll b = 997;
   		for (ll i = 0; i < st.length(); i++)
        {      
        	result = (int)st[i] + a*result;  
      	}
     // 	cout<<"result "<<result<<endl;
		ll index = (((a * result )+ b) % prime_no ) % max_size;
	//	cout<<"index "<<index<<endl;
		return index;
	}
	
	void insert(T1 key, T2 value)
	{
		int ispresent = 0;
		keyvalue<T1, T2> pair;
		pair.key = key;
		pair.value = value;
		ll index = calculatehash(key);
		typename list<keyvalue<T1,T2> >::iterator it;
		for(it = ump[index].begin(); it != ump[index].end(); it++)
		{
			if((*it).key == key)
			{
				(*it).value = value;
				ispresent = 1;
				break;
			}
		}
		if(ispresent == 0)
		{
			ump[index].push_back(pair);
		}		
	}
	
	bool find(T1 key)
	{
		int ispresent = 0;
		ll index = calculatehash(key);
		typename list<keyvalue<T1,T2> >::iterator it;
		for(it = ump[index].begin(); it != ump[index].end(); it++)
		{
			if((*it).key == key)
			{
				ispresent = 1;
				break;
			}
		}
		
		if(ispresent == 1)
			return true;
		else
			return false;
	}
	
	void deletekey(T1 key)
	{
//		int ispresent = 0;
		ll index = calculatehash(key);
		typename list<keyvalue<T1,T2> >::iterator it;
		for(it = ump[index].begin(); it != ump[index].end(); it++)
		{
			if((*it).key == key)
			{
				ump->erase(it);
				break;
			}
		}
	}
	
	bool end()
	{
		return false;		
	}

	T2 operator[](T1 key)
	{
		int ispresent =0;
		ll index = calculatehash(key);
		typename list<keyvalue<T1,T2> >::iterator it;
		for(it = ump[index].begin(); it != ump[index].end(); it++)
		{
			if((*it).key == key)
			{
				ispresent = 1;
				break;
			}
		}
		
		if(ispresent == 1)
		{
			return (*it).value;
		}
		else
		{
			static T2 value;
			return value;
		}
	}
	
	void display()
	{
		for(ll index = 0; index<max_size; index++)
		{
			typename list<keyvalue<T1,T2> >::iterator it;
			for(it = ump[index].begin(); it != ump[index].end(); it++)
			{
				cout<<(*it).key<<" --> "<<(*it).value<<endl;
			}
		}
	}
	
};

int main()
{
	unorderedmap<char,int> ump;
	ump.insert('a',1);
	ump.insert('b',2);
	ump.insert('c',3);
	ump.insert('d',4);
	ump.insert('a',5);
	ump.deletekey('b');
	if(ump.find('b') == ump.end())
		cout<<"deleted"<<endl;
	cout<<ump['a']<<endl;
	ump.display();
	return 0;
}

