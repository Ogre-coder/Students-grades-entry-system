#include "CCourse.h"
#include "CStudent.h"

using namespace std;

CStudent student; //instantiate Cstudent Class

CCourse::CCourse(void)
{

} //Constructor not being used

CCourse::~CCourse(void) {

} //Destructor not being used

int CCourse::add_student()
{
    cout << "Adding Student" << "\n\n";  //confirm that it is inside add_student()

    cout << "Student Number:";
    cin >> student.student_number; //ask user to enter student number;

    if (student.student_number == "MENU") //if student number is entered wrong and user type 'menu'
    {
        student.student_number = ""; //student number will be cleared;
        cout << "\n";
        return 0;  //break out this function
    }

    //error checking: if student size is not 9 or does not include 'A00' or 'A01'
    while (student.student_number.size() != 9 || (student.student_number.find("A00") == npos && student.student_number.find("A01") == npos))
    {
        cout << "Error in student number! Re-enter again!" << endl; //Re-enter message
        cout << "Student Number:";
        cin >> student.student_number; // user enter student numebr again 

        if (student.student_number == "MENU") //if student number is entered wrong and user type 'menu'
        {
            student.student_number = "";  //student number will be cleared;
            cout << "\n";
            return 0;  //break out this function
        }
        //if student entered student # correctly
        if (student.student_number.size() == 9 && (student.student_number.find("A00") == 0 || student.student_number.find("A01") == 0))
        {
            break; // exit this error checking loop
        }
    }

    //convert float student data to string for error checking using regex 
    string str_lab = to_string(student.lab_grade);
    string str_quiz = to_string(student.quiz_grade);
    string str_midterm = to_string(student.midterm_grade);
    string str_finalexam = to_string(student.finalexam_grade);

    while (count <= 3) // to ensure all types of grades are using only 1 error checking loop, loop when count below 3
    {
        if (count == 0) // if count is 0, user enters lab grade
        {
            cout << "Lab Grade:";
            cin >> str_lab;
            str = str_lab;
        }
        else if (count == 1)  // if count is 1, user enters quiz grade
        {
            cout << "Quiz Grade:";
            cin >> str_quiz;
            str = str_quiz;
        }
        else if (count == 2)    // if count is 2, user enters midterm grade
        {
            cout << "Midterm Grade:";
            cin >> str_midterm;
            str = str_midterm;
        }
        else if (count == 3)
        {
            cout << "Final Exam Grade:";   // if count is 3, user enters midterm grade
            cin >> str_finalexam;
            str = str_finalexam;
        }

        if (str == "MENU")  //if student number is entered wrong and user type 'menu'
        {
            cout << "\n";
            return 0;   //break out this function
        }
        // error checking scheme using regex; if string doesnt equal to 2 digits/1 digit decimal place
        // or 100, user will enter a loop and keep repeating until data is entered correctly
        while (!(regex_match(str, regex("[1-9][0-9](\\.[0-9]+)?")) || regex_match(str, regex("[0-9](\\.[0-9]+)?")) ||
            regex_match(str, regex("[1][0][0](\.[0]+)?"))))
        {
            // each count corresponds to each type of grade
            if (count == 0)
            {
                cout << "Error in lab grade! Re-enter again!" << endl;
                cout << "Lab Grade:";
                cin >> str_lab;
                str = str_lab;

            }
            else if (count == 1)
            {
                cout << "Error in quiz grade! Re-enter again!" << endl;
                cout << "Quiz Grade:";
                cin >> str_quiz;
                str = str_quiz;

            }
            else if (count == 2)
            {
                cout << "Error in midterm grade! Re-enter again!" << endl;
                cout << "Midterm Grade:";
                cin >> str_midterm;
                str = str_midterm;
            }
            else if (count == 3)
            {
                cout << "Error in final exam grade! Re-enter again!" << endl;
                cout << "Final Exam Grade:";
                cin >> str_finalexam;
                str = str_finalexam;
            }

            if (str == "MENU") //if user entered wrong and wants to go back to menu
            {
                cout << "\n";
                return 0; //break this loop and go out of function
            }

            // if user entered the data correctly
            if (regex_match(str, regex("[1-9][0-9](\\.[0-9]+)?")) || regex_match(str, regex("[0-9](\\.[0-9]+)?")) ||
                regex_match(str, regex("[1][0][0](\.[0]+)?")))
            {
                break; // break this loop and go out of function
            }
        }

        if (count >= 0)
        {
            count++;  //increment count so all grade conditions are covered
        }

    }

    cout << '\n';

    //convert string to float so other methods can use
    student.lab_grade = stof(str_lab);
    student.quiz_grade = stof(str_quiz);
    student.midterm_grade = stof(str_midterm);
    student.finalexam_grade = stof(str_finalexam);

    //calculate final grade
    student.final_grade = 0.4 * student.lab_grade + 0.1 * student.quiz_grade + 0.2 * student.midterm_grade
        + 0.3 * student.finalexam_grade;

    count = 0; //reset count so user will enter data starting from student number
    total_students.push_back(student); //append student data into a vector
    return 0;

}

int CCourse::edit_student()
{
    // convert integer student_edit to string for error checking
    string str_num = to_string(student_edit);

    cout << "Student to Edit:"; // user enter which student will edit
    cin >> str_num;

    if (str_num == "MENU") //if user typed "MENU" 
    {
        str_num = "";
        cout << "\n";
        return 0; //break out this function to go back to menu 
    }

    //cannot edit student if student exceeds the number of students added, therefore, need to convert
    //str_num to integer to set a condition
    if (regex_match(str_num, regex("\\d")))
    {
        student_edit = stoi(str_num);
    }

    // if student_edit entered is not an integer and above students limit. 
    while (!(regex_match(str_num, regex("\\d"))) || student_edit > total_students.size() ||
        student_edit == 0)
    {
        // student will re-enter
        cout << "Error in student edit! Re-enter again!" << endl;
        cout << "Student to Edit:";
        cin >> str_num;

        //if student typed 'MENU' because student edit is entered wrong
        if (str_num == "MENU")
        {
            str_num = "";
            cout << "\n";
            return 0; // break this while loop and exit this funciton
        }

        if (regex_match(str_num, regex("\\d")))
        {
            student_edit = stoi(str_num);
        }

        //if student edit is entered correctly
        if (regex_match(str_num, regex("[1-9]?[0-9]")) && student_edit <= total_students.size() &&
            student_edit > 0)
        {
            break; //break this loop
        }
    }

    // user will enter student number 
    cout << "Student Number:";
    cin >> total_students[student_edit - 1].student_number;

    //same as above 
    if (total_students[student_edit - 1].student_number == "MENU")
    {
        total_students[student_edit - 1].student_number = "";
        cout << "\n";
        return 0;
    }

    //error checking loop that make sure student numebr is entered correctly
    //exactly like in add_student()
    while (total_students[student_edit - 1].student_number.size() != 9 ||
        (total_students[student_edit - 1].student_number.find("A00") == npos &&
            total_students[student_edit - 1].student_number.find("A01") == npos))
    {
        cout << "Error in student number! Re-enter again!" << endl;
        cout << "Student Number:";
        cin >> total_students[student_edit - 1].student_number;

        if (total_students[student_edit - 1].student_number == "MENU")
        {
            total_students[student_edit - 1].student_number = "";
            cout << "\n";
            return 0;
        }

        if (total_students[student_edit - 1].student_number.size() == 9 &&
            (total_students[student_edit - 1].student_number.find("A00") == 0 ||
                total_students[student_edit - 1].student_number.find("A01") == 0))
        {
            break;
        }
    }

    //convert float student data to string for error checking using regex 
    string str_lab = to_string(total_students[student_edit - 1].lab_grade);
    string str_quiz = to_string(total_students[student_edit - 1].quiz_grade);
    string str_midterm = to_string(total_students[student_edit - 1].midterm_grade);
    string str_finalexam = to_string(total_students[student_edit - 1].finalexam_grade);
    string str_totalstudents = to_string(total_students.size() - 1);

    //exactly same error checking loop like in add_student() for grades
    while (count <= 3)
    {
        if (count == 0)
        {
            cout << "Lab Grade:";
            cin >> str_lab;
            str = str_lab;
        }
        else if (count == 1)
        {
            cout << "Quiz Grade:";
            cin >> str_quiz;
            str = str_quiz;
        }
        else if (count == 2)
        {
            cout << "Midterm Grade:";
            cin >> str_midterm;
            str = str_midterm;
        }
        else if (count == 3)
        {
            cout << "Final Exam Grade:";
            cin >> str_finalexam;
            str = str_finalexam;
        }

        if (str == "MENU")
        {
            cout << "\n";
            return 0;
        }

        while (!(regex_match(str, regex("[1-9][0-9](\\.[0-9]+)?")) || regex_match(str, regex("[0-9](\\.[0-9]+)?")) ||
            regex_match(str, regex("[1][0][0](\.[0]+)?"))))
        {
            if (count == 0)
            {
                cout << "Error in lab grade! Re-enter again!" << endl;
                cout << "Lab Grade:";
                cin >> str_lab;
                str = str_lab;
            }
            else if (count == 1)
            {
                cout << "Error in quiz grade! Re-enter again!" << endl;
                cout << "Quiz Grade:";
                cin >> str_quiz;
                str = str_quiz;
            }
            else if (count == 2)
            {
                cout << "Error in Midterm grade! Re-enter again!" << endl;
                cout << "Midterm Grade:";
                cin >> str_midterm;
                str = str_midterm;
            }
            else if (count == 3)
            {
                cout << "Error in Final Exam grade! Re-enter again!" << endl;
                cout << "Final Exam Grade:";
                cin >> str_finalexam;
                str = str_finalexam;
            }

            if (str == "MENU")
            {
                cout << "\n";
                return 0;
            }

            if (regex_match(str, regex("[1-9][0-9](\\.[0-9]+)?")) || regex_match(str, regex("[0-9](\\.[0-9]+)?")) ||
                regex_match(str, regex("[1][0][0](\.[0]+)?")))
            {
                break;
            }

        }

        if (count >= 0)
        {
            count++;
        }
    }

    cout << '\n';

    //convert string to float so other methods can use
    total_students[student_edit - 1].lab_grade = stof(str_lab);
    total_students[student_edit - 1].quiz_grade = stof(str_quiz);
    total_students[student_edit - 1].midterm_grade = stof(str_midterm);
    total_students[student_edit - 1].finalexam_grade = stof(str_finalexam);

    //calculate final grade
    total_students[student_edit - 1].final_grade = 0.4 * total_students[student_edit - 1].lab_grade
        + 0.1 * total_students[student_edit - 1].quiz_grade + 0.2 * total_students[student_edit - 1].midterm_grade
        + 0.3 * total_students[student_edit - 1].finalexam_grade;

    count = 0; //reset count

    return 0; //exit this function as student's data is editted
}

int CCourse::print_menu()
{
    //print main menu on console
    cout << "**************************************** \n";
    cout << "ELEX4618 Grade System, by Henry Wong \n";
    cout << "**************************************** \n";
    cout << "(A)dd student\n(E)dit student\n(P)rint grades\n(S)ave class\n(L)oad class\n(D)elete class\n(Q)uit\n";
    cout << "TYPE 'MENU' if pressed the wrong option or current entry is entered wrong.\n";
    cout << "Current entry will not be saved!\n\n";
    cin >> option; // ask user to enter option 

    return 0;
}

int CCourse::print_grades()
{
    //if total number of students is 0 
    if (total_students.size() == 0)
    {
        cout << "\nNo students exist!\n" << endl; //dont print grades
    }
    else
    {
        //iterate through the vector 
        for (int i = 0; i <= total_students.size() - 1; i++)
        {
            //print out students information that the user has entered
            cout << "\n";
            cout << "#" << "      " << "Student" << "      " << "Lab" << "    " << "Quiz" << "    "
                << "Midterm" << "      " << "Final Exam" << "    " << "Final Grade" << endl;

            //formatted by allocating spaces for each data and align them on the left margin
            cout << left << setw(7) << i + 1 << setw(13) << left << fixed << setprecision(1) << total_students[i].student_number
                << setw(7) << left << fixed << setprecision(1) << total_students[i].lab_grade << setw(8) << left << fixed
                << setprecision(1) << total_students[i].quiz_grade << setw(13) << left << fixed << setprecision(1)
                << total_students[i].midterm_grade << setw(14) << left << fixed << setprecision(1)
                << total_students[i].finalexam_grade << fixed << setprecision(2) << total_students[i].final_grade << endl;

            cout << "\n";

        }
    }
    return 0;
}

int CCourse::save_student()
{
    ofstream myfile;    //defin the output file stream to create and write to files

    //check if a student exists 
    if (total_students.size() != 0) //if a student exists
    {
        //asks user to enter the name of the file he wants to save as
        cout << "Input file name:";
        cin >> file_name;

        //user can return to menu if wants to change file name
        if (file_name == "MENU")
        {
            file_name = "";
            cout << "\n";
            return 0;
        }
        while (!(regex_match(file_name, regex("\\w+")))) //if file name is not a valid format
        {
            // User will reenter
            cout << "File name format is invalid! Re-enter!\n";
            cout << "Input file name:";
            cin >> file_name;

            if (file_name == "MENU")
            {
                file_name = "";
                cout << "\n";
                return 0;
            }

            //if user finally entered the filename in a correct format
            if (regex_match(file_name, regex("\\w+")))
            {
                break; // break the loop and prepare to write to file
            }
        }

        //indicate file is ready to write
        cout << "\nFile saved!\n" << endl;
    }
    else //if no students exist
    {
        //error message
        cout << "No students exist! Must first add!\n" << endl;
        return 0;
    }

    myfile.open(file_name); //open file
    //iterate through the vector of class student which contains data per student
    for (int i = 0; i <= total_students.size() - 1; i++)
    {
        //use myfile instead of cout
        myfile << "\n";
        myfile << "#" << "      " << "Student" << "      " << "Lab" << "    " << "Quiz" << "    "
            << "Midterm" << "      " << "Final Exam" << "    " << "Final Grade" << endl;

        myfile << left << setw(7) << i + 1 << setw(13) << left << fixed << setprecision(1) << total_students[i].student_number
            << setw(7) << left << fixed << setprecision(1) << total_students[i].lab_grade << setw(8) << left << fixed
            << setprecision(1) << total_students[i].quiz_grade << setw(13) << left << fixed << setprecision(1)
            << total_students[i].midterm_grade << setw(14) << left << fixed << setprecision(1)
            << total_students[i].finalexam_grade << fixed << setprecision(2) << total_students[i].final_grade << endl;

        myfile << "\n";

    }
    myfile.close(); //close the file 

    return 0;
}

int CCourse::load_student()
{
    ifstream myfile;  //define the input file stream to read files

    //ask user to enter file name that wanted to load in 
    cout << "Input file name:";
    cin >> file_name;

    //can return to menu if file name is wrong 
    if (file_name == "MENU")
    {
        file_name = "";
        cout << "\n";
        return 0;
    }
    //error checking loop
    while (!(regex_match(file_name, regex("\\w+"))))
    {
        //if file name has an invalid format, re-enter
        cout << "File name format is invalid! Re-enter!\n";
        cout << "Input file name:";
        cin >> file_name;


        //return to menu
        if (file_name == "MENU")
        {
            file_name = "";
            cout << "\n";
            return 0;
        }

        //if user entered file name in a correct format, break error checking loop
        if (regex_match(file_name, regex("\\w+")))
        {
            break;
        }
    }

    myfile.open(file_name); //open the file

    //loop from stack exchange to check if file existed in the folder
    //if file did not exist
    while (!myfile)
    {
        //user will re-enter 
        cout << "File cannot be found!" << endl;
        //user will choose to go back to the main menu or enter a new file name
        cout << "Re-enter(press any key) or add a file(press'A'):";
        cin >> option;
        //if user decides to enter a new file name
        if (option != "A")
        {
            cout << "Input file name:";
            cin >> file_name;

            //open the file
            myfile.open(file_name);

            //if file did exist
            if (myfile)
                break; //break the check loop and ready to read the content
        }
        else // if user chooses 'A', 
        {
            cout << '\n';
            return 0; //break out the loop and exit the function 
        }
    }

    //confirmed that file has loaded
    cout << "\nFile Loaded!" << endl;

    //line of code copied from stack exchange to put the entire content of a file into a string
    string file_contents{ istreambuf_iterator<char>(myfile), istreambuf_iterator<char>() };

    //read the string
    myfile >> file_contents;
    //output the string
    cout << file_contents << endl;

    //close the file
    myfile.close();

    return 0;
}

int CCourse::delete_student()
{
    //convert student_delete to string for error checking
    string str_num = to_string(student_delete);

    //ask user to enter student_delete to choose which student to delete
    cout << "Student to delete:";
    cin >> str_num;

    //return to menu
    if (str_num == "MENU")
    {
        str_num = "";
        cout << "\n";
        return 0;
    }

    //convert student_delete to integer so size of student can be checked 
    if (regex_match(str_num, regex("\\d")))
    {
        student_delete = stoi(str_num);
    }

    //if student delete has an invalid format; not a digit
    while (!(regex_match(str_num, regex("\\d"))) || student_delete > total_students.size() ||
        student_delete == 0)
    {
        //user will re-enter
        cout << "Error in student edit! Re-enter again!" << endl;
        cout << "Student to Edit:";
        cin >> str_num;

        //return to menu
        if (str_num == "MENU")
        {
            str_num = "";
            cout << "\n";
            return 0;
        }

        if (regex_match(str_num, regex("\\d")))
        {
            student_delete = stoi(str_num);
        }

        //if student delete is valid
        if (regex_match(str_num, regex("\\d")) && student_delete <= total_students.size() &&
            student_delete > 0)
        {
            break;  //break the loop
        }
    }

    //if passes error checking, delete the element in the vector
    total_students.erase(total_students.begin() + (student_delete - 1));

    //confirm the student is erased
    cout << "\nStudent erased!\n" << endl;

    return 0;
}

int CCourse::quit()
{
    //ask user to choose an option
    cout << "Do you want to save? TYPE 'MENU' to go back and save!" << endl;
    cout << "Or 'No' to exit: ";
    cin >> option;

    //user can return to menu and save 
    if (option == "MENU")
    {
        cout << "\n";
        return 0;
    }
    else if (option == "No") //if user didnt wanna save, 
    {
        //program will exit 
        cout << "\nProgram will now end!\n" << endl;
        cout << "\n";
    }

    return 0;
}