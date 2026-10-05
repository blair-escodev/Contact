#include <iostream> 
#include <vector> 
#include <string>
#include <fstream>
#include <memory> 
#include <string> 
#include <algorithm> 
#include <cctype> 
#include <sstream> 

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

//This is done to save the contact into file. 
void save_contacts (std :: string& name, std :: string& phoneNumber) { 
std :: string contact_file = "contactBook.txt";
std :: fstream output_file (contact_file.c_str(), std :: ios :: out | std :: ios :: app); 
if(output_file.is_open()) { 
	output_file << name << '|' << phoneNumber << std :: endl; 
} 
else { 
std :: cerr <<  "File can't be open\n"; 
} 
output_file.close(); 
} 

// check if it is digit. 
// This is done to check: 
// if the numbers are digit
// if the numbers are up to 10. 
// if the input is not empty. 
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

std :: string trim (std :: string& text) { 
while (!text.empty() && text.back() == ' ') { 
text.pop_back(); 
}
while (!text.empty() && text.front() == ' ') { 
text.erase(0, 1); 
} 
return text; 
} 
// Add contact function
// It adds the person name, and phone number only 
// It checks the number of digit if it is up to standard  then it stores the number. 

std :: vector <char_contact> addContact (std :: vector <char_contact>& record) {
std :: cin.ignore(std :: numeric_limits<std :: streamsize> :: max(), '\n'); 
bool is_running = true; 

std :: string name; 
std :: string* name_ptr = &name; 
std :: string phoneContact; 
std :: string*  contact_ptr = &phoneContact;

std :: cout << "Name: "; 
std :: getline(std :: cin, *name_ptr); 

while (is_running){ 
std :: cout <<  "Phone Contact: "; 
std :: getline (std :: cin , *contact_ptr); 

if(isDigit(phoneContact)) { 
is_running = false;
*name_ptr = trim(*name_ptr); 
*contact_ptr = (*contact_ptr); 
save_contacts(name,phoneContact); 
record.push_back({name, phoneContact}); 
}

else{ 
std :: cout << "Numbers only, try again!\n"; 
} 

}

return record;
//End of addContact
}

//This is done to view the contact list. 
void viewContact (std :: vector <char_contact>& record) { 
std :: string line; 
std :: ifstream file ("contactBook.txt"); 


if(!file.is_open()) { 
std :: cerr <<  "Error: file can not be found! "; 
} 

while (std :: getline(file, line)) { 
std :: cout << line << std :: endl; 
} 
}


// This to help search a certain name.
// Send the string to upper case. 

bool check_Name (std :: string name) { 

if (name.empty()) { 
return true; 
} 
return false; 
} 

//Ask name function. 

std :: string askName () { 
std :: cin.ignore(std :: numeric_limits < std :: streamsize > ::  max(),'\n'); 
std :: string name; 
bool isRunning = true; 
while (isRunning) { 
std :: cout << "Enter name to search contact: "; 
std :: getline ( std :: cin, name); 

if (check_Name(name)) { 
std :: cout << "Error: name is empty! \n";  
} 
else { 
isRunning = false;
trim(name); 
//std :: cout << "my name is: " << name << std :: endl; 
return name; 
} 
}
  
return name; 
} 	

std :: string  to_upperCase  (std :: string name) { 
std :: transform ( name.begin(), name.end(), name.begin(), toupper);
return name; 
} 

void  loadContacts (std :: vector <char_contact>& record) { 
char_contact person;
std :: string line;
std :: ifstream contactFile ("contactBook.txt"); 

if (!contactFile.is_open()) { 
std :: cerr << "Error: file cannot be found!\n"; 
} 

while (std :: getline(contactFile, line )) { 
size_t pos = line.find('|'); 
if (pos == std :: string :: npos) { 
continue; 
}
person.name = line.substr(0, pos); 
person.contact = line.substr(pos + 2);
record.push_back(person); 
}

while (!person.name.empty() && person.name.back() == ' ') { 
person.name.pop_back(); 
} 

while (!person.contact.empty() && person.contact.front() == ' '){
person.contact.erase(0,1); 
}

}

// If the name matches with one of the name in the vector, then the name and the phone contact print out
std :: vector <char_contact> findContact (std :: vector <char_contact>& record, std :: string name) { 
bool found = false; 

for( const auto& contact : record ) { 
if (to_upperCase(contact.name) == to_upperCase(name)) { 
std :: cout << "Name: " << contact.name << ". "  << "Phone number: " << contact.contact << std :: endl; 
found = true; 
break; 
} 

}

if (!found) { 
std :: cout << "No match found for: " << name << std :: endl; 
} 
return record; 
} 


int main () {
std :: unique_ptr <std :: vector<char_contact>>  record = std :: make_unique<std :: vector<char_contact>>(); 
int choice;
const int upperBoundary = 5;
bool running = true; 
std :: string menu [5] = {"Add contact", "View contacts", "Search contact", "Delete contact", "Exit"}; 


//loadContacts(*record); 
//std :: cout << '[' << (*record)[0].name << "]\n"; 
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
	std :: cout << "\nAdd contact has been selected\n";
        addContact(*record); 	
	break; 

case menuOption :: viewContacts: 
	std :: cout << "\nView Contacts has been selected\n"; 
	viewContact(*record); 	
	break; 

case menuOption :: searchContact: {  
	std :: cout << "Search contact has been selected\n";  
	std :: string name = askName();
	loadContacts(*record);
      	std :: vector <char_contact> search = findContact(*record, name ); 
	break; 


				  } 
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
