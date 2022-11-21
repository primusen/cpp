#include <iostream>
#include <fstream>

using namespace std;

string getdata(string file) {
    string data;
    ifstream readFile(file);
    
    getline(readFile, data); 

    readFile.close();
    return data;
}

int main() {
    string data, tempData, writeData, user_input;
    bool login = false;

    cout << "Login or signup? (l/s) "; cin >> user_input;

    while (true) {
        data = getdata("data/data.txt");

        if (user_input == "l" || login) {
            login = true;

            while (login) {
                tempData = data;
                cout << "What is your username? "; cin >> user_input;

                if (data.find(("u_" + user_input)) != string::npos) {
                    tempData.erase(0, (data.find(user_input)));
                    tempData.erase((tempData.find(" ")), tempData.length());
                    tempData.erase(0, (tempData.find(":") + 1));
                    
                    cout << "What is your password? "; cin >> user_input;

                    if (user_input == tempData) {
                        cout << "Login successful!" << endl;
                        return 0;
                    } else {
                        cout << "Incorrect password." << endl;
                    }
                } else {
                    cout << "User not found." << endl;
                }
            }
            
        } else if (user_input == "s") {
            while (true) {
                cout << "What will your username be? "; cin >> user_input;

                if (data.find(("u_" + user_input)) != string::npos) {
                    cout << "Username already taken." << endl;
                } else {
                    break;
                }
            }

            writeData = "u_" + user_input + ":";

            cout << "What will your password be? "; cin >> user_input;

            ofstream writeFile("data/data.txt");
            writeFile << data + (writeData + user_input + " ");

            writeFile.close();

            cout << "Would you like to log in? (y/n) "; cin >> user_input;

            if (user_input == "y") {
                login = true;
            } else {
                return 0;
            }
        } else {
            cout << "Invalid input." << endl;
            return 0;
        }
    }
}