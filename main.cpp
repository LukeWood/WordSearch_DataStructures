#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <pair>
using std::ifstream;
using std::ofstream;
using std::cout;
using std::vector;
using std::string;
using std::pair;

//Creating a Point type to store in my vector of answers
typedef std::pair<double, double> Point;

int main(int argc, char*argv[])
{
//Check to ensure that there are two strings passed to the program, the input file then output file.
if(argc!=4)
{
cout<<"need 3 command prompt arguments, wordbank file, wordsearch file and output file."<<"\n";
return 0;
}

//Continue on in program, declaring the variables I will need.
ifstream in;
vector<string> inputContent;
vector<string> wordBank;
vector<Point> locations;
//Trying to open the ifstream to the file input and read each line into the vector of sting, keep track of size before \n.
in.open(argv[1]);
if(in.is_open())
{
	cout<<"Reading in the word search.\n";
	string temp = "";
	char x;
	while (in>>x)
	{
		temp+= x;
		if(in.peek()=='\n')
		{
		inputContent.push_back(temp);
		temp = "";
		}
	}
}

//Just showing that I have successfully read in the word search and closing the ifstream.
cout<<"Full Word Search:\n";
for(int i = 0; i < inputContent.size(); i++)
{
	cout<<inputContent[i]<<"\n";
}
in.close();
cout<<"\n";
//Reading in the word bank.
in.open(argv[2]);
if(in.is_open())
{
	cout<<"Reading in the word bank.\n";
	string word;
	while(in>>word)
	{
	wordBank.push_back(word);
	}
}
in.close();

cout<<"Full word bank:\n";
for(int i = 0; i < wordBank.size();i++)
{
cout<<wordBank[i]<<"\n";
}

//End Program
return 0;
}
