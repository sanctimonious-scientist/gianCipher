#include <iostream>
#include <string>

int j = 0;
bool debug = false;

void debugM(std::string dMessage) {
	if (debug) {
		std::cout << dMessage << std::endl;
	}
	return;
}

std::string descramble(std::string message, std::string sign, std::string otherSign, std::string conversion[2][3]) {
	std::string singleSign;
	std::string otherSignSingle;
	std::string doubleSingleSign;
	int arrayChoice;
	while (message.find(sign) != std::string::npos) {
		j++;
		arrayChoice = j % 2;
		singleSign = conversion[arrayChoice][0];
		otherSignSingle = conversion[arrayChoice][1]; //questionExclamation basically
		doubleSingleSign = conversion[arrayChoice][2];
		if (message.find(otherSign + sign) != std::string::npos) {
			if (message.find(otherSign + sign) == message.find(sign) - 1) {
				message.replace(message.find(otherSign + sign), 2, otherSignSingle);
				continue;
			}
		}
		if (message.find(message.find(sign + sign)) != std::string::npos) {
			if (message.find(sign) == message.find(sign + sign)) {
				message.replace(message.find(sign + sign), 2, doubleSingleSign);
				continue;
			}
		}
		else {
			message.replace(message.find(sign), 1, singleSign);
			continue;
		}
	}
	return message;
}

int main(int argc, char** argv) {
	if (argc > 1) {
		if (argv[1] == "-d" || argv[1] == "-D") {
			std::cout << "Activated debug mode." << std::endl;
			debug = true;
		}
	}
	std::string input;
	std::string choice;
	std::string exclamationValues[2][3] = {{"1", "0", "5"}, {"2", "1", "4"}};
	std::string questionValues[2][3] = {{"3", "6", "2"}, {"0", "5", "3"}};
	std::string ampersandValues[2][3] = {{"4", "7", "9"}, {"9", "6", "7"}};
	std::cout << "GIANCIPHER V 1.0\nEnter message." << std::endl;
	getline(std::cin, input);
	while (true) {
		std::cout << "SCRAMBLE OR DESCRAMBLE? (ENTER S OR D)" << std::endl;
		getline(std::cin, choice);
		if (choice == "S" || choice == "s") {
			// scramble(input);
			std::cout << "Scrambling coming soon!" << std::endl;
		}
		else if (choice == "D" || choice == "d") {
			input = descramble(input, "!", "?", exclamationValues);
			input = descramble(input, "?", "!", questionValues);
			input = descramble(input, "&", "$", ampersandValues);
			std::string finalize[2][2] = {{"$", "8"}, {"_", ""}};
			for (int i = 0; i < 2; i++) {
				while (input.find(finalize[i][0]) != std::string::npos) {
					input.replace(input.find(finalize[i][0]), 1, finalize[i][1]);
				}
			}
			break;
		}
		else {
			std::cout << "Choose a listed response." << std::endl;
		}
	}
	std::cout << input << std::endl;
	return 0;
}