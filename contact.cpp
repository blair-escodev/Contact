#include <iostream> 
#include <vector> 
#include <string>
#include <fstream>
#include <memory> 
#include <string> 


struct char_contact { 
std :: string name; 
std :: string contact; 
}; 

enum class menuOption  {
addContact, 
viewContacts,
searchContact, 
deleteContact, 
exit, 
}; 

// check if it is digit. 

bool isDigit (std :: string &phoneContact) { 
int length = phoneContact.size();
if(phoneContact.empty()) { 
return false; 
} 
for (char digit : phoneContact) { 
if (!std :: isdigit(static_cast<unsigned char> (digit)) ||  length != 10) { 
return false; 
}
// end of loop 
}
return true; 
} 

// Add contact function
// It adds the person name, and phone number only 
// It checks the number of digit if it is up to standard  then it stores the number. 

std :: vector <char_contact> addContact (std :: vector <char_contact>& record) {
std :: cin.ignore(std :: numeric_limits<std :: streamsize> :: max(), '\n'); 
bool is_running = true; 
char_contact person; 
std :: string name; 
std :: string* name_ptr = &name; 
std :: string phoneContact; 
std :: string*  contact_ptr = &phoneContact;

std :: cout << "Name: "; 
std :: getline(std :: cin, *name_ptr); 

while (is_running){ 
std :: cout <<  "Phone Contact: "; 
std :: cin >> *contact_ptr; 

if(isDigit(phoneContact)) { 
is_running = false; 
record.push_back({name, phoneContact}); 
}

else{ 
std :: cout << "Numbers only, try again!\n"; 
} 

}


return record;
//End of addContact
}
int main () {
std :: unique_ptr <std :: vector<char_contact>>  record = std :: make_unique<std :: vector<char_contact>>(); 
int choice; 
const int upperBoundary = 5;
bool running = true; 
std :: string menu [5] = {"Add contact", "View contacts", "Search contact", "Delete contact", "Exit"}; 


while (running) {
	std :: cout << std :: endl << " Menu " << std :: endl; 
for (int i = 0; i < upperBoundary; i++) {	
std :: cout << (i + 1) << ". " << menu[i] << '\n'; 
} 	
std :: cout << "Choose: "; 
std :: cin >> choice;

if (std :: cin.fail() ||  choice < 0 || choice > 5) { 
	std :: cin.clear(); 
	std :: cin.ignore(1000, '\n'); 
} 



menuOption chose = static_cast<menuOption>(choice - 1); 

switch (chose) { 
case menuOption :: addContact : 
	std :: cout << "Add contact has been selected\n";
        addContact(*record); 	
	break; 

case menuOption :: viewContacts: 
	std :: cout << "View Contacts has been selected\n"; 
	break; 

case menuOption :: searchContact: 
	std :: cout << "Search contact has been selected\n"; 
 	break; 

case menuOption :: deleteContact: 
	std :: cout << "Delete contact has been selected\n"; 
	break; 

case menuOption :: exit:
        running = false; 	
	std :: cout << "Application has exit successfully\n"; 
	break; 
default : 
	std :: cout << "Try again\n"; 
	break; 
} 

}


// End of main.
}
