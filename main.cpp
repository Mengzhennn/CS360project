#include <iostream>
#include "memory.hpp"
#include "structs.hpp"
#include "encode.hpp"

string file_to_string(ifstream& in){
    stringstream sstr;
    sstr << in.rdbuf();
    return sstr.str();
}

int main(int argc, char** argv) 
{
	bool run_prog = true;
	std::string Source_In;
	string code;
	std::string inputFile = "input2.txt";
	
	{
		ifstream infile(inputFile.c_str());
		code = file_to_string(infile);
		infile.close();
	}
	
	
	memory external = memory(2048);
	vector<string> binary = string_to_binary(code);
	
	while (run_prog)
	{
		
		cout<<"Enter number for command:1. edit source code; 2. print converted assembly code; 3. memory; 4. exit" <<endl;
		
		string command;

		getline(std::cin, command);
		
		if(command == "1")
		{
			std::cout << "Please edit the input file " << inputFile << " directly, press any key to continue" << std::endl;
			std::cin.ignore(1);
			std::cin.clear();
			
			ifstream infile(inputFile.c_str());
			code = file_to_string(infile);
			infile.close();
		}
		else if(command=="2" )
	
		{
			if(Source_In != "")
			{
				//parse entire string, including tabs and the like, into MIPS assembly code.
				//Call function on Source_In string.
				//Store result in some container.
			}
			//call function that print converted assembly code
			//Print using cout or in-built print function.
		}
		
		else if(command == "3")
	
		{
				for (int j = 0; j < binary.size(); j++){
					external.setword(j, binary[j]);
				}
				cout << "| Word | Data |" << "\n";
	
				//code doesn't work on my mac without the .c_str() at the end. If this causes
				//a problem removing it should hopefully fix it - Emile
				for (int i = 0; i < external.getsize(); i++)
				{
					
					printf ("|  %i   | %s |\n", i, external.getword(i).c_str()); 
				}
	
	

		}
		
		else if (command =="4")
	
		{
	
			run_prog = false;
			

		}
		
		else

		{

			cout<<"Please enter a valid command"<<endl;
			
		}
	
	}
	
	return 0;
}



/*
	for (int j = 0; j < binary.size(); j++){
		external.setword(j, binary[j]);
	}
	
	cout << "| Word | Data |" << "\n";
	
	//code doesn't work on my mac without the .c_str() at the end. If this causes
	//a problem removing it should hopefully fix it - Emile
	for (int i = 0; i < external.getsize(); i++){
		printf ("|  %i   | %s |\n", i, external.getword(i).c_str());   
	}
*/