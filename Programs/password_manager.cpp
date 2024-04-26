#include <iostream>
#include <fstream>
#include <vector>

/*class to store the filename and master key required to access the created file. 
*/
class PasswordVault 
{
protected:
    std::string filename;
    std::string master_key;

public:
    PasswordVault(std::string name, std::string key) : filename(name), master_key(key) 
    {
        //create file with the user give filename
        std::ifstream file(name);
        //file.open(name);
	if (!file) 
        {
            std::cout<< "File could not be opened. Please try again later!"<<std::endl;
            return;
        }
        file.close();
    }

    void addPassword(std::string account, std::string username, std::string password) 
    {
         //open the user's file in append mode
        std::ofstream file(filename, std::ios_base::app);
        if (!file.is_open()) {
            std::cout << "Could not open file, please check and try again later!"<<std::endl;
            return;
        }
        //store account:username:password into the file
        file<<account<<":"<<username<<":"<<password<<std::endl;
        file.close();
    }

    void getPassword(std::string key, std::string account) 
    {
	//if the master key doesn't match the user provided key, don't show password
        if (key != master_key) 
	{
            std::cout<<"The entered key does not match master key!"<<std::endl;
            return;
        }
	
        std::ifstream file(filename);
        std::string line;
        std::string username;
	std::string password;
        //check each line for the user provided account,
	//if the account is present, return the username and password
	while (getline(file, line)) 
	{
            int first_delim = line.find(':');
            if (first_delim != std::string::npos) 
	    {
                int second_delim = line.find(':', first_delim + 1);
                if (second_delim != std::string::npos) 
		{
		    std::string acc = line.substr(0, first_delim);
                    if (acc == account) 
		    {
                        username = line.substr(first_delim + 1, second_delim - first_delim - 1);
                        password = line.substr(second_delim + 1);
                        file.close();
                        displayPassword(username, password); // Return username and password if account matches
                        return;
                    }
                }
            }
        }
        file.close();
        std::cout<<"Account not found!"<<std::endl;
    }

    void displayPassword(std::string username, std::string password)
    {
         std::cout<<"Username : "<<username<<" Password : "<<password<<std::endl;
    }

};
/*Implement the user class to store individual users and their permissions
 */
class User : public PasswordVault 
{
    std::string username;
    bool isAdmin;

public:
    User(std::string usern, bool adminRights, std::string name, std::string key)
        : username(usern), isAdmin(adminRights), PasswordVault(name, key) {}

    void changeAdminRights(bool adminRights) {
        isAdmin = adminRights;
    }
};

int main() {
    //first user is named admin, they have admin rights, their usernames and passwords are stored in 
    //the "admin.txt" paramter and the master key to access the created file is "bq654"
    //user1 details
    User user1("alice", true, "alice_passwords.txt", "9876h");
    user1.addPassword("somedomain1.com", "alice@example.com", "het326");
    user1.addPassword("somedomain2.com", "Bob@domain.com", "29fndk");
    
    //user2 details
    User user2("tom", false, "tom_passwords.txt", "298fjkb");
    user2.addPassword("somedomain3.com", "tom@somedomain.com", "ei3n2l");
    
    //user3 details
    User user3("lisa", true, "lisa_passwords.txt", "865sdf");
    user3.addPassword("somedomain4.com", "l@domain4.com", "cef87k");

    user1.getPassword("9876h", "somedomain2.com");
    user1.getPassword("9876h", "tom@somedomain.com");
    user2.getPassword("298fjkb", "goo.com");
    user3.getPassword("wrongmasterkey", "l@domain4.com");
    
    return 0;
}

