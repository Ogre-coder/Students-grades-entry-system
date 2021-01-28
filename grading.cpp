// ELEX 4618 lab 2 - Student Grading System using object oriented programming with error checking + Delete & Save/Load capability
// by Henry Wong (A00953101)

//header file of CCourse class
#include "CCourse.h"

int main() //Main acitivity
{
    CCourse Course; //instantiate CCourse Class
    int add_flag = 0; //create an add flag to make sure students are added before print/edit/save/delete

    do
    {
        Course.print_menu(); // call print_menu function to print main menu         

        if (Course.option == "A") // if 'A' is pressed
        {
            Course.add_student(); // call add_student function to start adding students
            add_flag = 1; //add flag is set to tag that students are added
        }
        else if (Course.option == "P") // if 'P' is pressed
        {
            if (add_flag == 1) // if add_flag is set 
            {
                Course.print_grades(); // call print_grades function to print grades;
            }
            else //if no students are added
            {
                cout << "Student not yet enter! Must first add!\n" << endl; //reminder message
            }
        }
        else if (Course.option == "E") // if 'E' is pressed
        {
            if (add_flag == 1) // if add_flag is set
            {
                Course.edit_student(); // call edit_student function to edit student
            }
            else // if no students are added
            {
                cout << "Student not yet enter! Must first add!\n" << endl; //reminder message
            }
        }
        else if (Course.option == "S") // if 'S' is pressed
        {
            if (add_flag == 1) //if add_flag is set
            {
                Course.save_student(); //call save_students function
            }
            else
            {
                cout << "Student not yet enter! Must first add!\n" << endl; //reminder message
            }
        }
        else if (Course.option == "L") // if 'L' is pressed
        {
            Course.load_student(); //call load_student function
        }
        else if (Course.option == "D") // if 'D' is pressed
        {
            if (add_flag == 1)  //if add_flag is set
            {
                Course.delete_student();    //call delete_student function
            }
            else
            {
                cout << "Student not yet enter! Must first add!\n" << endl; //reminder message
            }
        }
        else if (Course.option == "Q")  // if 'Q' is pressed
        {
            Course.quit(); //call quit function
            if (Course.option == "No") //if selected no
            {
                break; //break out this while loop to exit
            }
        }
        else //if non-exsiting key is pressed
        {
            while (Course.option != "A") //error checking; if 1 is not equal, it means others will also not
            {
                cout << "No Such Option! Re-enter!\n" << endl;  //message
                break;
            }
        }

    } while (1); //keep looping unless 'Q' is pressed

    return 0;
}
