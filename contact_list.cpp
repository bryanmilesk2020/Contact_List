//contact list project
#include <iostream>
#include <map>
#include <string>
//#define DISPLAY_LIST

std::pair <std::string, std::string> addContact() { //gets name and number and puts it into
	std::cout << "What is the name of the contact?\n"; //a pair, returns that pair to main function
	std::string name;
	std::cin >> name;

	std::cout << "What is the phone number?\n";
	std::string phoneNumber;
	std::cin >> phoneNumber;

	std::pair<std::string, std::string> p1(name, phoneNumber);

	return p1;
}

void searchContact(std::map <std::string, std::string> contactList) {
	std::cout << "What is the name of the contact you are searching?\n";
	std::string name;
	std::cin >> name;

	std::cout << name << "'s phone number is " << contactList[name] << '\n';
}

std::map <std::string, std::string> deleteContact(std::map < std::string, std::string> &contactList) {
	std::cout << "What is the name of the contact you want to delete?\n";
	std::string name;
	std::cin >> name;

	contactList.erase(name);

	return contactList;
}

int main() {

	std::map <std::string, std::string> contactList;
	char answ;
	
	while (true) {
		std::cout << "Would you like to (a)dd, (s)earch, or (d)elete a contact?\n";

		std::cin >> answ;

		if (answ == 'a') {
			contactList.insert(addContact()); //inserts pair from addContact() into map contactList1
		}
		if (answ == 's') {
			searchContact(contactList);
		}
		if (answ == 'd') {
			deleteContact(contactList);
		}
#ifdef DISPLAY_LIST
		for (auto itr = contactList.begin(); itr != contactList.end(); itr++) {
			std::cout << (*itr).first << " : " << (*itr).second << '\n';
		}
#endif
	}
}
