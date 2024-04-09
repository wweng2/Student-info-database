#include <iostream>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


int main() {
  
  //int max_length_name = 26;
  //char name[max_length_name];
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
  
  while(choice != 6){

      cout<<"Here is the Available options: \n"
        << " N1: Add new Student \n "
        << "N2: Student Login \n "
        << "N3: Teacher/Faultity Login \n"
        << "N4: Proctor Login \n"
        << " N5: Admin View \n"
        << " N6: Exit \n";

      cin >> choice; 

      if(choice == 1){

        cout<<"How many students are you adding"<<endl;
        cin>> students;
        count = count + students;


        

        
        
      }

      /*
      elif(choice == 2){
        
      }

      elif(choice == 3){

      }

      elif(choice == 4){

      }
      */

    
  }

  cout<<"Thanks for using the Student Grade Database , Have a Nice day \n";

  return 0;
  

  
}
