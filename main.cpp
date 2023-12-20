#include "stack.hpp"
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> tokens;
map<string,Stack*> stacks;

void invalidCmd(string &cmd){
	cout << "\n   Invalid command: " << cmd << endl << endl;
}

void stackNF(string &name){
	cout << "\n   Stack named: '" << name << "' has not found or created!" << endl << endl;
}

void listStacks(){
	if(stacks.empty()){cout << "\n   No stacks were created! " << endl << endl; return;}
	cout << "\n   List of stacks available:" << endl;
	for(auto const &s : stacks){
		cout << "     " << s.first << endl;
	}
	cout << endl;
}

void printHelp(){
	cout << "\n   Available Commands:";
	cout << "\n       stacks";
	cout << "\n       create <stack_name> <int_stack_size>";
	cout << "\n       get <stack_name>";
	cout << "\n       push <stack_name> <int_value>";
	cout << "\n       pop <stack_name>";
	cout << "\n       delete <stack_name>";
	cout << "\n       quit/exit\n" << endl;
}

bool parseInput(string &inp){
	tokens.clear();
	string token = "";
	for(char &c : inp){
		if(c == ' '){tokens.push_back(token);token = "";}
		else{token += c;}
	}
	if(token != ""){tokens.push_back(token);}

	if(tokens.size() >= 3){

		string cmd = tokens.at(0);
		string name = tokens.at(1);
		string val = tokens.at(2);

		if(stacks.find(name) == stacks.end()){
			if(cmd == "create"){
				stacks.insert({name,new Stack(stoi(val))});
			}
			else{ stackNF(name); }
		}
		else if(cmd == "push"){
			stacks[name]->push(stoi(val));
		}
		else{ invalidCmd(cmd); }

	}
	else if(tokens.size() == 2){

		string cmd = tokens.at(0);
		string name = tokens.at(1);

		if(stacks.find(name) != stacks.end()){
			if(cmd == "get"){
				cout << endl << "   " << stacks[name]->get() << endl << endl;
			}
			else if(cmd == "pop"){
				stacks[name]->pop();
			}
			else if(cmd == "delete"){
				delete stacks[name];
				stacks.erase(name);
			}
			else{ invalidCmd(cmd); }
		}
		else{ stackNF(name); }

	}
	else if(tokens.size() == 1){

		string cmd = tokens.at(0);

		if(cmd == "help"){
			printHelp();
		}
		else if(cmd == "stacks"){
			listStacks();
		}
		else if(cmd == "quit" || cmd == "exit"){
			cout << "\n   Cleaning...\n" << endl;
			for(auto const &s : stacks){
				delete s.second;
			}
			stacks.clear();
			return false;
		}
		else{ invalidCmd(cmd); }
	}
	else{ cout << "\n   Type 'help' to list available commands.\n" << endl;}
	return true;
}

bool getInput(){
	string inp;
	cout << ">> ";
	getline(cin,inp);
	return parseInput(inp);
}

int main(){
	cout << "\n-------------------\n| Stack Simulator |\n-------------------" << endl;
	cout << "Follow: https://github.com/AbdulBasitKhatri" << endl;
	cout << "\n   Type 'help' to list available commands.\n" << endl;
	while(getInput()){}
	return 0;
}

