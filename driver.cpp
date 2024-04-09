#include <iostream>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


int main() {
  
  int max_length_data = 26;
  char data[max_length_data];
  int students = 0;
  int choice = 0;
  int count = 0;

  string intial_value = "00";
  string proctor = "";

  ifstream f("student_database.txt");
  string line;

  for (int i = 0; std::getline(f, line); ++i) {
      count++;
  }
  cout<<"Welcome to the Student Grade database"<<endl;
  
  while(choice != 5){

      cout<<"Here is the Available options: \n"
        << " N1: Add new Student \n "
        << "N2: Student Login \n "
        << "N3: Teacher/Faultity Login \n"
        << " N4: Admin View \n"
        << " N5: Exit \n";

      cin >> choice; 

      if(choice == 1){

        cout<<"How many students are you adding"<<endl;
        cin>> students;
        count = count + students;


        for(int i = 0 ; i < students ; i++){

          ofstream outfile;
          outfile.open("student_database.txt", ios::app);

          cout<<"Please enter the Students's Regitration Number: \n";
          cin >>data;
          outfile <<data<<"\t";

          cout<<"Please enter the Students' name: \n";

          cin>>data;

          int name_length = strlen(data);

          while(name_length < 26){
            data[name_length] = ' ';
            name_length = name_length + 1;
            
          }

          outfile <<data<<"\t";
          outfile << intial_value << "\t";
          outfile << intial_value << "\t";

          cout<<"Please enter the proctor ID"<<endl;

          cin>> proctor;

          outfile<< proctor << endl;
          

          
        }

        

        
        
      }

      
      else if(choice == 2){

        char RegisNum[9];
        cout<<"Enter your Registration number";
        cin>>RegisNum;

        ifstream infile;
        int check = 0;
        infile.open("student_database.txt", ios::in);

        while(infile>>data){

          if(strcmp(data, RegisNum) == 0 ){
            cout<<"Registration Number"<<data<<endl;

            infile >>data;

            cout<<"Name"<<data<<endl;

            infile >>data;

            cout<<"Cs101 Marks"<<data<<endl;

            infile >>data;

            cout<<"Cs201 Marks"<<data<<endl;

            infile >>data;

            cout<<"Proctor ID"<<data<<endl;

            infile.close();
            check = 1;
            
          }
        }

        if(check == 0){
          cout<<"Sorry , Data relating to this Registration number is not found"<< " please enter the correct number"<<endl;
        }
        
      }
      
      else if(choice == 3){

        char subjectcode[5];
        cout<<"Please enter your subject code"<<endl;
        cin>>subjectcode;

        string code1 = "CS101";
        string code2 = "CS202";
        string mark = "";
        ifstream infile;
        int check = 0;

        cout<<"Avaiable operation: \n"<<"N1. Add data for student: \n"
        <<"N2: View data\n";

        cin >>choice;
      
      

        if(choice == 1){

          cout<<"Warning, You have to updata or add marks for all the students that is in the database, please prepare for this \n";
        
      

          for(int i = 0 ; i < count ; i++){
            fstream file("student_database.txt");

            if (strcmp(subjectcode, code1.c_str())
                == 0) {
                file.seekp(26 + 37 * i,
                           std::ios_base::beg);
                cout << "Enter the mark of student#"
                     << (i + 1) << " : ";
                cin >> mark;
                file.write(mark.c_str(), 2);
            }

            if (strcmp(subjectcode, code2.c_str())
                == 0) {
                file.seekp(29 + 37 * i,
                           std::ios_base::beg);
                cout << "Enter the mark of student#"
                     << (i + 1) << " : ";
                cin >> mark;
                file.write(mark.c_str(), 2);
            }
            
          }
        }


        else if(choice == 2){
          infile.open("student_database.txt", ios::in);
          if (strcmp(subjectcode, code1.c_str()) == 0) {
              cout << "Registration number - Marks\n"
                   << endl;
              while (infile >> data) {
                  cout << data;
                  infile >> data;
                  infile >> data;
                  cout << " - " << data << endl;
                  infile >> data;
                  infile >> data;
                  check = 1;
              }
          }

          infile.close();
          infile.open("student_database.txt", ios::in);

          if (strcmp(subjectcode, code2.c_str()) == 0) {
              cout << "Registration number - Marks\n"
                   << endl;
              while (infile >> data) {
                  cout << data;
                  infile >> data;
                  infile >> data;
                  infile >> data;
                  cout << " - " << data << endl;
                  infile >> data;
                  check = 1;
              }
          }
          }

          infile.close();

          if (check == 0) {
          cout << "No such subject code found!" << endl;
          }
        }
      

      else if(choice == 4){
        char password[25];
        cout<<"Enter the Adim password";

        cin>>password;

        string adim_password = "DJE345";

        if(strcmp(password,adim_password.c_str()) == 0){

          cout<<"Outline of the database is Registration Number, Name \n"<<  "Subject1 (Cs101), Subject2(Cs201), Proctor ID"<<endl;
          
          ifstream infile;

          infile.open("student_database.txt", ios::in);
          char data[20];

          while (infile >> data) {
              cout << data << "\t";
              infile >> data;
              cout << data << "\t";
              infile >> data;
              cout << data << "\t";
              infile >> data;
              cout << data << "\t";
              infile >> data;
              cout << data << endl;
          }
          
        }
        

      }
      

  
  

  cout<<"Thanks for using the Student Grade Database , Have a Nice day \n";

  return 0;
  
  }
  
}
