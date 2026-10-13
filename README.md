# This is a light weight, console based C++ application designedto manage personal contacts with persistent file storage. 

## Features
* **Add Contacts:** this create new entries with input validationensuring phone numbers contain only digits and meet the required10-digit standard.
* **View Contacts:** Display all stored contacts loaded directlyfrom the persistent storage which is the file. 
* **Search Contacts:** This search for specific entries by name using a case-insensitive query lookup. 
* **Delete Contacts:** This remove unwanted contacts or records from both memory and the underlying text file with confirmation prompts. 
* **Persistent Storage:** Authomatically saves and syncs data to to local `contactBook.txt` file. 


---
## Getting Stared: 

### Perequisites: 
You need a C++ compiler installed on your system that supports **C++17** or letter ( e.g., Clang, g++ etc). 

### Compilation and Excution: 
Open your terminal inside the project directory and run thefollowing 
1. **Compile the program:** ```bash
g++ -std=c++17 main.cpp -o contact.cpp.
