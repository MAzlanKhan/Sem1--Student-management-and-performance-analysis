#include<iostream>
#include<string>
using namespace std;
int main(){
    char userChoice;

    string studentName[50] = {"Ali", "Ayesha", "Bilal", "Sehar", "Hassan", "Hina", "Imran", "Kiran", "Zain", "Sara", "Usman", "Maria", "Omar", "Sania", "Tariq", "Hira", "Shahbaz", "Noor", "Daniyal", "Iqra"};
    string feeSubmissionStatus[50] = {"Submitted", "Submitted", "Not Submitted", "Submitted", "Not Submitted", "Submitted", "Submitted", "Not Submitted", "Submitted", "Submitted", "Not Submitted", "Submitted", "Submitted", "Not Submitted", "Submitted", "Submitted", "Not Submitted", "Submitted", "Submitted", "Not Submitted"};
    string newEntryName, grade, remarks;

    int n = 20, rollNo = 1021, searchStudentId, totalMarks = 1200;
    int studentRoll[50] = {1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011, 1012, 1013, 1014, 1015, 1016, 1017, 1018, 1019, 1020};

    float updateStudentMarks, studentPercentage;
    float studentMarks[50] = {150, 200, 250, 300, 350,400, 450, 500, 550, 600,650, 700, 750, 800, 850,900, 950, 1000, 1100, 0};


    //  BODY OF CODE


    cout << "\n__________ STUDENT MANAGEMENT SYSTEM __________" << endl<<endl;
    while (true){
        
        cout << "_________________________________\n";
        cout << "_________________________________\n";
        cout << "Press [1] to Add a Student\n";
        cout << "Press [2] to Display All the Students of Class\n";
        cout << "Press [3] to Find/Check a Specific Student.\n";
        cout << "Press [4] to Display Performance and Marks of All Students.\n";
        cout << "Press [5] to Update Marks of Students.\n";
        cout << "Press [6] to Update Fee Status.\n";
        cout << "Press [E] to Exit.\n";
        cout << "_________________________________\nEnter: ";

        cin >> userChoice;



        // PART 1: ADD A STUDENT

        if (userChoice == '1'){
            bool exists = false;

            cout << "Enter the Name of Student: ";
            getline(cin >> ws, newEntryName); // to take string input with spaces

            for(int i = 0; i <= n-1; i++){
                if(newEntryName == studentName[i]){
                    cout << "--------" << endl;
                    cout << "**ERROR!!**\n--Student Already Exists!; Please Try Again with a Different Name--" << endl;
                    cout << "--------" << endl;
                    exists = true;
                }
            }

            if(exists != true){
                studentRoll[n] = rollNo; // storing roll number as index r = 0
                studentName[n] = newEntryName; // storing name at index n = 0
                
                cout << "\n**Student Added Successfully!**" << endl;
                cout << "------------------------------" << endl;
                cout << "Name is: " << newEntryName << " and Roll No is: " << studentRoll[n] << endl<<endl;

                n++;
                rollNo++;
            } 
        }



        // PART 2: DISPLAY ALL STUDENTS

        else if(userChoice == '2'){
            cout << "--(DISPLAYING ALL STUDENTS)--" << endl<<endl;
            cout << "_______________________" << endl;
            
            int k = 1;
            for(int i = 0; i <= n - 1; i++){ // suppose 2 entries then i = 3 and j <= 3-1 = 2
                cout << k << ".";
                cout << "Student Name: " << studentName[i] << endl;
                cout << "Student ID: " << studentRoll[i] << endl;
                cout << "Fee Status: " << feeSubmissionStatus[i] <<endl;
                cout << "----" << endl;
                k++;
            }  
            cout << "_______________________" << endl<<endl;
        }



        // PART 3: SEARCH A STUDENT

        else if(userChoice == '3'){
            bool exists = false;
            int toBeSearh;

            while(!exists){
                cout << "Enter the Student ID: ";
                cin >> searchStudentId;
              
                for(int i = 0; i<= n-1; i++){
                    if(studentRoll[i] == searchStudentId){
                        exists = true;
                        toBeSearh = i; 
                    }
                }

                if(exists == true){
                    if(studentMarks[toBeSearh] >= 1100){
                        grade = "A+";
                        remarks = "Excellent Performance";
                    }
                    else if(studentMarks[toBeSearh] >= 1000){
                        grade = "A";
                        remarks = "Very Good Performance";
                    }
                    else if(studentMarks[toBeSearh] >= 900){
                        grade = "B+";
                        remarks = "Good Performance";
                    }
                    else if(studentMarks[toBeSearh] >= 800){
                        grade = "B";
                        remarks = "Satisfactory Performance";
                    }
                    else if(studentMarks[toBeSearh] >= 700){
                        grade = "C+";
                        remarks = "Needs Improvement, Practice more.";
                    }
                    else if(studentMarks[toBeSearh] >= 600){
                        grade = "C";
                        remarks = "Poor Performance, Work Harder.";
                    }
                    else if(studentMarks[toBeSearh] >= 500){
                        grade = "D+";
                        remarks = "Very Poor Performance, Significant Improvement Needed.";
                    }
                    else if(studentMarks[toBeSearh] >= 400){
                        grade = "D";
                        remarks = "Extremely Poor Performance, Immediate Action Required.";
                    }
                    else{
                        grade = "F";
                        remarks = "He Failed!";
                    }

                    studentPercentage = (studentMarks[toBeSearh] / totalMarks) * 100;
 
                    cout << "\n_______________________" << endl;
                    cout << "Student Name: " << studentName[toBeSearh] << endl; 
                    cout <<"Student ID: " << studentRoll[toBeSearh] << endl;
                    cout <<"Marks Obtained: " << studentMarks[toBeSearh] << endl;
                    cout << "Percentage: " << studentPercentage << "%" << endl;
                    cout << "Grade: " << grade << endl;
                    cout << "Remarks: " << remarks << endl;
                    cout << "Fee Status: " << feeSubmissionStatus[toBeSearh] << endl;
                    cout << "_______________________" << endl<<endl;
                    break;
                } 
                else{
                    cout << "--------" << endl;
                    cout << "**ERROR!!**\n--Student Not Found! Please Try Again with a Valid Roll Number--" << endl;
                    cout << "--------" << endl<<endl;
                    break;
                }                
            }
        }



        // PART 4: DISPLAY MARKS OF ALL STUDENTS WITH GRADES AND REMARKS

        else if(userChoice == '4'){
            cout << "--(DISPLAYING MARKS OF ALL STUDENTS)--" << endl<<endl;
            cout << "_______________________" << endl;
        
            for(int i = 0; i <= n - 1; i++){ // suppose 2 entries then i = 3 and j <= 3-1 = 2
                
                if(studentMarks[i] >= 1100){
                    grade = "A+";
                    remarks = "Excellent Performance";
                }
                else if(studentMarks[i] >= 1000){
                    grade = "A";
                    remarks = "Very Good Performance";
                }
                else if(studentMarks[i] >= 900){
                    grade = "B+";
                    remarks = "Good Performance";
                }
                else if(studentMarks[i] >= 800){
                    grade = "B";
                    remarks = "Satisfactory Performance";
                }
                else if(studentMarks[i] >= 700){
                    grade = "C+";
                    remarks = "Needs Improvement, Practice more.";
                }
                else if(studentMarks[i] >= 600){
                    grade = "C";
                    remarks = "Poor Performance, Work Harder.";
                }
                else if(studentMarks[i] >= 500){
                    grade = "D+";
                    remarks = "Very Poor Performance, Significant Improvement Needed.";
                }
                else if(studentMarks[i] >= 400){
                    grade = "D";
                    remarks = "Extremely Poor Performance, Immediate Action Required.";
                }
                else{
                    grade = "F";
                    remarks = "He Failed!";
                }

                studentPercentage = (studentMarks[i] / totalMarks) * 100;

                cout << "Student Name: " << studentName[i] << endl;
                cout << "Student ID: " << studentRoll[i] << endl;
                cout << "Marks Obtained: " << studentMarks[i] << endl;
                cout << "Percentage: " << studentPercentage << "%" << endl;
                cout << "Grade: " << grade << endl;
                cout << "Remarks: " << remarks << endl;
                cout << "_______________________" << endl<<endl;
            }

        }



        // PART 5: UPDATE STUDENT MARKS

        else if(userChoice == '5'){
            bool exists = false;
            int toBeSearh;

            while(!exists){
                cout << "Enter Student ID: ";
                cin >> searchStudentId;

                for(int i = 0; i<= n-1;i++){
                    if(studentRoll[i] == searchStudentId){
                       exists = true;
                       toBeSearh = i;
                    }
                }

                if( exists == true){
                    cout << "\n------------------------" << endl;
                    cout << "Student Name: "<<studentName[toBeSearh]<<endl;
                    cout << "Student ID: " << studentRoll[toBeSearh] << endl;
                    cout << "Current Marks: " << studentMarks[toBeSearh] <<endl;
                    cout << "------------------------" << endl;

                    cout << "Enter new marks: ";
                    cin >> updateStudentMarks;
                    studentMarks[toBeSearh] = updateStudentMarks;
                        
                    cout << "**Marks updated successfully!**" << endl;
                    cout << "-------------------------" << endl;
                    exists = false;
                    break;
                }
                else{ 
                    cout << "--------" << endl;
                    cout << "**ERROR!!**\n--Student Not Found! Please Try Again with a Valid Roll Number--" << endl;
                    cout << "--------" << endl<<endl;  
                    exists = false;
                }      
            }
        }   



        // PART 6
        else if(userChoice == '6'){
            bool exists = false;
            int toBeSearh;
            while(!exists){
                cout << "Enter Student ID to Update Fee Status: ";
                cin >> searchStudentId;
                
                for(int i = 0; i<=n-1;i++){
                    if(studentRoll[i] == searchStudentId){
                       exists = true;
                       toBeSearh = i;
                    }
                }
                if(exists == true){
                    cout << "_______________________" << endl;
                    cout << "Student Name: " << studentName[toBeSearh] << endl;
                    cout << "Fee Status is: " << feeSubmissionStatus[toBeSearh] << endl;
                    cout << "_______________________" << endl<<endl;
                    cout << "Press [1]. Submitted\nPress [2]. Not Submitted\nPress [3]. Due" << endl;
                    cout << "-------";
                    cin >> userChoice;
                }
                if(userChoice == '1'){
                    feeSubmissionStatus[toBeSearh] = "Submitted";
                    cout << "--------------------------" << endl;
                    cout << "**Fee Status Updated Successfully!**" << endl;
                    cout << "--------------------------" << endl;
                    break;
                }
                else if(userChoice == '2'){
                    feeSubmissionStatus[toBeSearh] = "Not Submitted";
                    cout << "--------------------------" << endl;
                    cout << "**Fee Status Updated Successfully!**" << endl;
                    cout << "--------------------------" << endl;
                    break;
                }
                else if(userChoice == '3'){
                    feeSubmissionStatus[toBeSearh] = "Due";
                    cout << "--------------------------" << endl;
                    cout << "**Fee Status Updated Successfully!**" << endl;
                    cout << "--------------------------" << endl;
                    break;
                }
                else{
                    exists = false;
                    cout << "\n***ERROR***\nInvalid Number..." <<endl;

                }
            }
        }



        // EXITING THE PROGRAM

        else if (userChoice == 'E' || userChoice == 'e'){
            cout << "**EXITING THE PROGRAM**\nTHANK YOU.." << endl;
            break;
        }

        else{
            cout << "Invalid Input! Please try again." << endl;
        }
    }
    return 0;
}