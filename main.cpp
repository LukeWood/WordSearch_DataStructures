#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;
//TYPE DECLARATIONS BEGIN

//Creating a Point type to store in my vector of answers
typedef std::pair<int, int> Point;

//Creating a struct for each word we find containing the point at and word name.
struct foundword
{
	string word;
	Point location;
	string dir;
};

//TYPE DECLARATIONS END

//FUNCTION DECLARATIONS BEGIN

//Creating a pseudo constructor to make it easier to get a foundword
foundword create_found_word(string word, int x,int y, string dir)
{
	foundword toreturn;
	Point temp(x,y);
	toreturn.word = word;
	toreturn.location = temp; 
	toreturn.dir = dir;
	return toreturn;
}

//Basic function to determine if the char getting input is a digit
bool isNum(char c) 
{
   return (c >='0' && c <='9');
}

//Function to write a foundword to a file
void write_found_word(const foundword wfound, ofstream& file)
{
file<<wfound.word<<"|"<<wfound.location.first<<"|"<<wfound.location.second<<"|"<<wfound.dir<<"\n";
}

//FUNCTION DECLARATIONS END

//MAIN BEGIN
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
ofstream out;
vector<string> wordSearch;
string* wordBank;
vector<foundword> found;

int wbanklen = 0;
int height = 0;//Word search height.

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
		//Read in leangth and convert to wbanklen using cstdlib
		//break was neccesary to prevent another the first word in the word bank from being thrown away
		break;
		}
		else
		{
		wordSearch.push_back(x);
		height++;
		}
	}

//Just showing that I have successfully read in the word search and closing the ifstream.
	cout<<"Full Word Search:\n";
	for(int i = 0; i < wordSearch.size(); i++)
	{
		cout<<wordSearch[i]<<"\n";
	}
	cout<<"Height: "<<height<<"\n";
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
	//file input is now complete.
	cout<<"Full word bank:\n";
	for(int i = 0; i < wbanklen;i++)
	{
		cout<<wordBank[i]<<"\n";
	}
	cout<<"Beginning to solve word search.\n";
	for(int i = 0; i <height;i++)
	{
		//Loop through each row
		for(int j = 0; j < wordSearch[0].length(); j++)
		{
			//Loop through each column
			for(int t = 0; t < wbanklen;t++)
			{
				//Check each word in word bank.
				if(wordSearch[i][j] == wordBank[t][0])
				{
					cout<<"Found the letter: "<<wordBank[t][0]<<"\n";
					if(wordBank[t].length()<=1)
					{
						found.push_back(create_found_word(wordBank[t],i,j,"N/A"));
					}
					else
					{
						//Find direction
						//
						for(int z = 0; z < wordBank[t].length(); z++)
						{
						
						}
					}
				}
			}
		}
	}	
}
else
{
	cout<<"File was not opened.\n";
}

out.open(argv[2]);
//Write each word found to the file.
if(out)
{
for(int i = 0; i < found.size(); i++)
{
	write_found_word(found[i],out);
}
}
out.close();

//End Program
delete[] wordBank;
return 0;
}
