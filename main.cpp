#include "memory.cpp"
#include "encode.cpp"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdio.h>

using namespace std;

string file_to_string(ifstream& in){
    stringstream sstr;
    sstr << in.rdbuf();
    return sstr.str();
}

ifstream infile("input.txt");
string code = file_to_string(infile);
memory external = memory(2048);
vector<string> binary = string_to_binary(code);

int main(){
	for (int j = 0; j < binary.size(); j++){
		external.setword(j, binary[j]);
	}
	cout << "| Word | Data |" << "\n";
	for (int i = 0; i < external.getsize(); i++){
		printf ("|  %i   | %s |\n", i, external.getword(i));
	}
	
	
	//UI code
	bool run_prog = true;
	while (run_prog)
	{
		cout<<"Enter command: edit source code; print converted assembly code; memory; exit" <<endl;
		cin>> command; 
		if(string == "edit source code") 
		{
			//open file with source code;
		}
		else if(string =="print converted assembly code" )
		{
			//call function that print converted assembly code
		}
		else if(string == "memory")
		{
			//print memory from memory class
			// should be a memory that I can call eg. memory that print all..
			
		}
		else if (string =="exit")
		{
			run_prog = false;
			
		}
		else
		{
			cout<<"Please enter a valid command"<<endl;
		}
	}
	
}
