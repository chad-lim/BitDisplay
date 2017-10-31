#include "bitdisp.h"

int main(int args, char *argv[]){

	// Get input from file
	std::string inputs = "";

	while(std::cin){
		std::string temp;
		std::getline(std::cin, temp);
		inputs.append(temp);
	}

	// Default values for command line arguments
	bool bin = true;
	bool acbout = true;
	bool bout = false;
	bool acbin = false;
	//	ACBOUT MEANS OUTPUT IN BINARY
	//	BOUT MEANS OUTPUT IN ASCII
	//	ACBIN MEANS TAKE IN BINARY
	// 	BIN MEANS TAKE IN ASCII


	// Only check for acbin and bout since those are not default
	checkArgs(argv, bin, bout, acbin, acbout);

	if(bin && bout){

		std::cout << inputs <<std::endl;
	}

	if (acbin && acbout){
		bool flag = false;
		inputs.erase(std::remove(inputs.begin(), inputs.end(), '\n'), inputs.end());
		for(int i = 0; i < inputs.size(); i++){
			if(inputs.at(i) != '0' && inputs.at(i) != '1' && inputs[i] != ' '){
				fprintf(stderr, "Error: Not a binary value. Cannot be displayed with this command\nUsage: ./bitdisp [-bin | -acbin] [-bout | -acbout] < [File]\n");
				flag = true;
			}
			inputs.erase(std::remove(inputs.begin(), inputs.end(), ' '), inputs.end());
			if(inputs.size()%8 != 0){
				fprintf(stderr, "Error: Not a proper number of input bits.\nMust input 8 bits to create a displayable byte\n");
				flag = true;
			}
			if(flag){
				return 0;
			}
		}

		std::cout << inputs << std::endl;
	}


	if (bin && acbout){
		inputs.erase(std::remove(inputs.begin(), inputs.end(), ' '), inputs.end());
		inputs.erase(std::remove(inputs.begin(), inputs.end(), '\n'), inputs.end());
		acToBin(inputs);
	}
	if (acbin && bout){
		inputs.erase(std::remove(inputs.begin(), inputs.end(), '\n'), inputs.end());
		for(int i = 0; i < inputs.size(); i++){
			if(inputs.at(i) != '0' && inputs.at(i) != '1' && inputs[i] != ' '){
				fprintf(stderr, "Error: Not a binary value. Cannot be displayed with this command\nUsage: ./bitdisp [-bin | -acbin] [-bout | -acbout] < [File]\n");
				return 0;
			}
		}
		inputs.erase(std::remove(inputs.begin(), inputs.end(), ' '), inputs.end());


		if(inputs.size()%8 != 0){
			fprintf(stderr, "Error: Not a proper number of input bits.\nMust input 8 bits to create a displayable byte\n");
			return 0;
		}
		binToAc(inputs);
	}

}

void acToBin(std::string inputs){

	std::string out;
	std::string upperNybble;
	std::string lowerNybble;

	for(int i = 0; i < inputs.size(); i++){
		std::bitset<8> x((char)inputs.at(i));
		out = x.to_string();
		upperNybble = out.substr(0,4);
		lowerNybble = out.substr(4,4);
		std::cout << upperNybble << " " << lowerNybble << "\n";
	}
}

void binToAc(std::string inputs){
	std::stringstream ss((inputs));
	std::string out;
	while(ss.good()){
		std::bitset<8> b;
		ss >> b;
		char c = char(b.to_ulong());
		out += c;
	}
	std::cout << out;
}

void checkArgs(char *argv[], bool &bin, bool &bout, bool &acbin, bool &acbout){
	if(argv[1] != NULL){
		std::string arg1 = argv[1];
		if(arg1 == "-bin"){
			bin = true;
			acbin = false;
		}
		else if (arg1 == "-bout") {
			bout = true;
			acbout = false;
		}
		else if (arg1 == "-acbin") {
			acbin = true;
			bin = false;
		}
		else if (arg1 == "-acbout") {
			acbout = true;
			acbin = false;
		}

		if(argv[2] != NULL){
			std::string arg2 = argv[2];
  			if(arg2 == "-bin"){
				bin = true;
				acbin = false;
			}
			else if (arg2 == "-bout") {
				bout = true;
				acbout = false;

			}
			else if (arg2 == "-acbin") {
				acbin = true;
				bin = false;
			}
			else if (arg2 == "-acbout") {
				acbout = true;
				bout = false;
			}
		}
	}
}
