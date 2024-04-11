#include <iostream>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


int main() {

  /* These intialzation of variables for the use thoughout the program like the while loop varible and , the max length is assign to be 26 letters long for the name
  
    */
  int max_length_data = 26;
  char data[max_length_data];
  int students = 0;
  int choice = 0;
  int count = 0;

  // The string values for the starting grades for new students and the protoc's name
  string intial_value = "00";
  string proctor = "";

  /* Open the databse and reads how many lines are written in the 
  database to use for looping though the file and adding new students
  */
  ifstream f("student_database.txt");
  string line;

  for (int i = 0; std::getline(f, line); ++i) {
      count++;
  }
  cout<<"Welcome to the Student Grade database"<<endl;

  // The UI to allow for the User to choice 4 option they can do 
  while(choice != 5){

      cout<<"Here is the Available options: \n"
        << " N1: Add new Student \n "
        << "N2: Student Login \n "
        << "N3: Teacher/Faultity Login \n"
        << " N4: Admin View \n"
        << " N5: Exit \n";

      cin >> choice; // Inserting the option the user choose

      if(choice == 1){

        // Choose how many students to be added
        cout<<"How many students are you adding"<<endl;
        cin>> students;
        count = count + students;

        /* This add the new students with their name and protocr idea
        with the intial values for the two class of 0 */

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

        /* The student login and requires the regirstration number 
        associated for the thier own grades*/
        
        char RegisNum[9];
        cout<<"Enter your Registration number";
        cin>>RegisNum;

        /* Opens the files and use strcmp to find the correct person
        based on the regirstration number stores in the databse the number the user puts in and allow for the view of grades*/
        
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

      /* The Error warning when the number enter is not in the database */
        
        if(check == 0){
          cout<<"Sorry , Data relating to this Registration number is not found"<< " please enter the correct number"<<endl;
        }
        
      }
      
      else if(choice == 3){

        // The Teacher login to changes grades for students
        char subjectcode[5];
        cout<<"Please enter your subject code"<<endl;
        cin>>subjectcode;

        // The current classses and grades in the teacher can modify
        string code1 = "CS101";
        string code2 = "CS202";
        string mark = "";
        ifstream infile;
        int check = 0;

        cout<<"Avaiable operation: \n"<<"N1. Add data for student: \n"
        <<"N2: View data\n";

        cin >>choice;
      
      

        if(choice == 1){

          /* If chosen the teacher will go though each students and with the right subject , make grade modication to only that class*/
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

        // Views all the grades for the students of the first calss
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

          // Views all the grades for the students of the second calss

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
          // Error warning for when the subject code is not found
          if (check == 0) {
          cout << "No such subject code found!" << endl;
          }
        }
      
      /* Using the admin password to view all the grades */
        
      else if(choice == 4){
        char password[25];
        cout<<"Enter the Adim password";

        cin>>password;

        // The password comaprison to make sure its the right person
        string adim_password = "DJE345";

        if(strcmp(password,adim_password.c_str()) == 0){

          cout<<"Outline of the database is Registration Number, Name \n"<<  "Subject1 (Cs101), Subject2(Cs201), Proctor ID"<<endl;
          
          ifstream infile;

          /* open the file and loops though the data with each student does a while loop in order to retreive each part of the data*/
          
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
      

  
  


  
  }
  // Ending Message when the User ends the while loop
  cout<<"Thanks for using the Student Grade Database , Have a Nice day \n";

  return 0;
  
}
