#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student
{
    int id;
    string name;
    string email;
    string phone;
    
    void input();
};

void Student:: input(){
    cout << "Enter id: "; 
    cin >> id; cin.ignore(1000, '\n');
    cout << "Enter name: "; 
    getline (cin, name);
    cout << "Enter email: "; 
    getline (cin, email);
    cout << "Enter phone number: "; 
    cin >> phone;
}

int main(){
    int i;
    cout << "How many students?: ";
    cin >> i;
    vector<Student> students (i);
    
    for (int j = 0; j < i; j++) students[j].input();
    
    cout << "\nYour Students Profile:\n";
    for (Student s: students) cout << "Id: " << s.id << "\nName: " << s.name << "\nEmail: " << s.email << "\nNumber Phone: " << s.phone << '\n';
        
}