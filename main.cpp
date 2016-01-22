#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;
//Basic function to determine if the char getting input is a digit
bool isNum(char c) 
{
   return (c >='0' && c <='9');
}

//Creating a Point type to store in my vector of answers
typedef std::pair<int, int> Point;

//Creating a struct for each word we find containing the point at and word name.
struct foundword
{
	string word;
	Point location;
	string dir;
};
//Creating a pseudo constructor to make it easier to get a foundword
foundword create_found_word(string word, int x,int y, string dir)
{
	foundword toreturn;
	Point temp(x,y);
	toreturn.word = word;
	toreturn.location = temp; 
	return toreturn;
}

//Function to write a foundword to a file
void write_found_word(foundword wfound, ofstream file)
{
cout<<wfound.word<<"|"<<wfound.location.first<<"|"<<wfound.location.second<<"|"<<wfound.dir<<"\n";
}

int main(int argc, char*argv[])
{
//Check to ensure that there are two strings passed to the program, the input file then output file.
if(argc!=3)
{
cout<<"need 2 command prompt arguments, wordsearch file and output file."<<"\n";
return 0;
}

//Continue on in program, declaring the variables I will need.
ifstream in;
vector<string> wordSearch;
string* wordBank;
vector<foundword> found;
int wbanklen = 0;

//Trying to open the ifstream to the file input and read each line into the vector of sting, keep track of size before \n.
in.open(argv[1]);
if(in.is_open())
{
	cout<<"Reading in the word search.\n";
	string x;
	bool done = false;
	while (in>>x && !done)
	{
		if(isNum(x[0]))
		{
		done = true;
		wbanklen = atoi(x.c_str());
		break;
		}
		else
		{
		wordSearch.push_back(x);
		}
	}

//Just showing that I have successfully read in the word search and closing the ifstream.
	cout<<"Full Word Search:\n";
	for(int i = 0; i < wordSearch.size(); i++)
	{
		cout<<wordSearch[i]<<"\n";
	}
	cout<<"\n"<<"Reading in word bank.\n";
//Reading in the word bank.
	wordBank = new string[wbanklen];
	for(int i = 0; i < wbanklen;i++)
	{
		string word;
		in>>word;
		wordBank[i] = word;
	}	
	in.close();
	cout<<"Full word bank:\n";
	for(int i = 0; i < wbanklen;i++)
	{
		cout<<wordBank[i]<<"\n";
	}
	cout<<"Beginning to solve word search.\n";
}
else
{
	cout<<"File was not opened.\n";
}
//End Program
return 0;
}
