#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using std::cout; using std::cin; using std::endl; using std::vector; using std::string;

void main_menu()
{
    cout << "Menu: " << endl;
    cout << "1: Task 1: String length" << endl;
    cout << "2: Task 2: Average salaries" << endl;
    cout << "3: Task 3: Swap sort with pointers" << endl;
    cout << "4: Task 4: Swap sort with double pointers" << endl;
    cout << "5: Task 5: Character replacement with pointers" << endl;
    cout << "6: Task 6: Modular vector database with pointers" << endl;
    cout << "-1: Exit " << endl;
    cout << "Which task would you like to run? ";
}

void task_1_string_length() {
    /* Task 1: String length
    Write a function that uses a for loop to find out and return the length of a string (char array pointer), excluding
    the final ‘\0’ character. It should not use any standard library functions. You may use arithmetic and dereference
    operators in the loop, but not the indexing operator ([ ]).

    As an example, you can define the string following way:
    char arr[] = "computer";
    char *ptr = arr; */

    char arr[] = "computer";
    char* ptr = arr;
    int string_length = -1;
    for (char c : arr) {
        string_length++;
    }
    cout << "\nString length of " << ptr << " is " << string_length << "." << endl << endl;
}

void t2_average_salary(const int salaries[], int number_of_employees) {
    int total_salary = 0;
    for (int i = 0; i < number_of_employees; i++) {
        total_salary += salaries[i];
    }
    int average_salary = total_salary / number_of_employees;
    cout << "The average salary is " << average_salary << "." << endl << endl;
}

void task_2_average_salaries() {
    /* Task 2: Average salaries
    Write a function named average_salary() to find the average salary of the employees of a department.
    In main(), the user will give the total number of employees in the department, and afterwards the salary of
    individual employees. The function average_salary() will take input of salaries as a pointer array and the number
    of employees and returns the average salary.

    Because the average_salary() function is not going to modify the input array, use const to make the array parameter
    a constant.

    TIP: Use dynamic memory allocation to allocate the array size based on the user’s input (see slides 17-18 in L6
    lecture notes) */
    int number_of_employees;
    cout << "\nEnter number of employees: ";
    while (!(cin >> number_of_employees)) {
        cout << "Incorrect input.\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Enter number of employees: ";
    }
    int* salaries = new int[number_of_employees];
    for (int i = 0; i < number_of_employees; i++) {
        cout << "Enter salary for employee " << i + 1 << "/" << number_of_employees << ": ";
        while (!(cin >> salaries[i])) {
            cout << "Incorrect input.\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Enter salary for employee " << i + 1 << "/" << number_of_employees << ": ";
        }
    }
    t2_average_salary(salaries, number_of_employees);
}

void t3_swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void t3_swap_sort(int* a, int* b, int* c, bool* order) {
    if (*order == 1)
    {
        while (*a > *b || *b > *c)
        {
            if (*a > *b)
            {
                t3_swap(a, b);
            }
            else if (*b > *c)
            {
                t3_swap(b, c);
            }
        }
    }
    else if (*order == 0)
    {
        while (*a < *b || *b < *c)
        {
            if (*a < *b)
            {
                t3_swap(a, b);
            }
            else if (*b < *c)
            {
                t3_swap(b, c);
            }
        }
    }
    else
    {
        cout << "Incorrect input for sorting! Please input a correct value." << endl;
        cout << "Sort ascending/descending (1/0): ";
        cin >> *order;
        t3_swap_sort(a, b, c, order);
    }
}

void task_3_swap_sort_with_pointers() {
    /* Task 3: Swap sort with pointers
    Convert your swap_sort() function of Lab 2 Task 4 to use pointers (*) instead of references (&).

    Description of Swap sort (pass-by-reference) from Lab 2 Task 4:
    Write a function named swap_sort() that
    * has a void return value (i.e. does not return anything)
    * takes three int parameters (a, b, c) using pass-by-reference
    * takes also a fourth parameter bool order (true: sort ascending, false: sort descending) (pass-by-value)
    * sorts the values of a, b and c into an ascending/descending order, depending on the value of “order”, by swapping
    them.
    In main( ), ask user to give three integers + whether to sort ascending or descending from the user. Then call the
    function and print out the variables to see whether they are sorted properly. This process should be continued until
    the user gives 0 as the first value. */
    cout << "This function takes three integers (a, b, and c) and then sorts them in" << endl;
    cout << "either ascending or descending order." << endl;
    int a;
    do
    {
        cout << "Give a (0 to quit): ";
        while (!(cin >> a))
        {
            cout << "Incorrect input. Try again: ";
            cin.clear();
            (void)cin.ignore(INT64_MAX, '\n');
        }
        if (a == 0)
        {
            cout << "Bye bye!\n";
            cout << endl;
            break;
        }
        else
        {
            int b; int c; bool order;
            cout << "Give b: ";
            while (!(cin >> b))
            {
                cout << "Incorrect input. Try again: ";
                cin.clear();
                (void)cin.ignore(INT64_MAX, '\n');
            }
            cin.clear();
            (void)cin.ignore(INT64_MAX, '\n');
            cout << "Give c: ";
            while (!(cin >> c))
            {
                cout << "Incorrect input. Try again: ";
                cin.clear();
                (void)cin.ignore(INT64_MAX, '\n');
            }
            cin.clear();
            (void)cin.ignore(INT64_MAX, '\n');
            cout << "\nSort ascending/descending (1/0): ";
            while (!(cin >> order))
            {
                cout << "Incorrect input. Try again: ";
                cin.clear();
                (void)cin.ignore(INT64_MAX, '\n');
            }
            cin.clear();
            (void)cin.ignore(INT64_MAX, '\n');
            t3_swap_sort(&a, &b, &c, &order);
            cout << a << " " << b << " " << c << endl;
        }
    } while (a != 0);
}

void t4_swap(int** x, int** y)
{
    int temp = **x;
    **x = **y;
    **y = temp;
}

void swap_sort_ptr_addr(int** a, int** b, int** c, bool ascending) {
    if (ascending == true)
    {
        while (**a > **b || **b > **c)
        {
            if (**a > **b)
            {
                t4_swap(a, b);
            }
            else if (**b > **c)
            {
                t4_swap(b, c);
            }
        }
    }
    else if (ascending == false)
    {
        while (**a < **b || **b < **c)
        {
            if (**a < **b)
            {
                t4_swap(a, b);
            }
            else if (**b < **c)
            {
                t4_swap(b, c);
            }
        }
    }
}

void task_4_swap_sort_with_double_pointers() {
    /* Task 4: Swap sort with double pointers
    Create one more version of the swap sort function where you use pointers’ memory addresses instead
    (i.e. double pointers). Your function should work with this code:

    int a = 7, b = 6, c = 1;
    int *p1 = &a, *p2 = &b, *p3 = &c;
    swap_sort_ptr_addr(&p1, &p2, &p3, true);
    cout << * p1 << " " << * p2 << " " << *p3;    // Points "1 6 7" */
    cout << "\nSorting the integers 7, 6 and 1..." << endl;
    int a = 7, b = 6, c = 1;
    int* p1 = &a, * p2 = &b, * p3 = &c;
    // To sort in descending order change true to false.
    swap_sort_ptr_addr(&p1, &p2, &p3, true);
    cout << a << " " << b << " " << c << endl << endl;
}

void t5_character_replacement(char* str, char find, char replace) {
    char* s = str;
    while ((s = strchr(s, find)) != nullptr) {
        *s = replace;
    }
}

void task_5_character_replacement_with_pointers() {
    /* Task 5: Character replacement with pointers
    Write a function replace_chars() that takes three parameters:

    one string as a pointer to a char array (i.e. char *str)
    one char as a search character
    another char as a replacement character
    The function then goes through the char array, using pointer arithmetics, and replaces all occurrences of the search
    character with the replacement character.

    In main(), call the function with some content and print out the array before and after the function call.
    Do NOT use the indexing operator [] to access the array contents (i.e. use only the dereference operator *)!
    NOTE: When you declare a string array like this in Visual Studio:
    char *str = "Hello";
    You get an error / warning because “Hello” is a literal constant, but char *str is not. To avoid this, there are two
    strategies:
    1) const char *str = "hello"; // not for this task, because the function must be able to edit the string
    2) char str[] = "hello"; // works here. */
    char str[] = "hello";
    cout << endl << str << " is replaced with ";
    t5_character_replacement(str, 'h', '4');
    t5_character_replacement(str, 'e', '3');
    t5_character_replacement(str, 'l', '1');
    t5_character_replacement(str, 'o', '0');
    cout << str << endl << endl;
}

void t6_database_menu()
{
    cout << "MENU: " << endl;
    cout << "  1. initialize database" << endl;
    cout << "  2. insert" << endl;
    cout << "  3. search" << endl;
    cout << "  4. delete" << endl;
    cout << "  5. print" << endl;
    cout << "  6. save" << endl;
    cout << "  7. load" << endl;
    cout << "  8. quit" << endl;
    cout << endl;
    cout << "Make your choice (1-8): ";
}

void t6_1_initialize_database(vector<string>* vec)
{
    char input;
    //initialize database
    cout << "Are you sure? (y/n): ";
    cin >> input;
    if (input == 'y')
    {
        vec->clear();
    }
    else if (input != 'y' && input != 'n')
    {
        cout << "Incorrect input. Try again." << endl;
        cin.clear();
        (void)cin.ignore(INT64_MAX, '\n');
        t6_1_initialize_database(vec);
    }
}

void t6_2_insert_names(vector<string>* vec)
{
    string name;
    do
    {
        cout << "Enter name(s) or q to go back to menu: ";
        cin >> name;
        if (name == "q" || name == "Q")
        {
            break;
        }
        else
        {
            // Converts name to lower case
            std::for_each(name.begin(), name.end(), [](char& c) {
                c = ::tolower(c);
                });
            vec->push_back(name);
        }
    } while (name != "q" || name != "Q");
    cout << "Number of names in database: " << vec->size() << endl << endl;
}

void t6_3_search_string(const vector<string>* vec)
{
    //search
    if (vec->empty())
    {
        cout << "Vector is empty. You need to add names to vector before using search." << endl;
    }
    else
    {
        string search_term;
        cout << "Enter search term: ";
        cin >> search_term;

        // Converts search_term to lower case
        std::for_each(search_term.begin(), search_term.end(), [](char& c) {
            c = ::tolower(c);
            });

        for (auto iterator = vec->begin(); iterator != vec->end(); iterator++) {
            if ((*iterator).find(search_term) != std::string::npos) {
                cout << *iterator << " ";
            }
        }
        cout << endl << endl;
    }
}

void t6_4_delete_name(vector<string>* vec)
{
    //delete;
    if (vec->empty())
    {
        cout << "Vector is empty. You need to add names to vector before using delete." << endl;
    }
    else
    {
        string search_term;
        cout << "Enter term to be deleted: ";
        cin >> search_term;

        auto it = find(vec->begin(), vec->end(), search_term);
        int vec_position;
        if (it != vec->end())
        {
            vec_position = it - vec->begin();
            vec->erase(vec->begin() + vec_position);
        }
    }
    cout << "Number of names in database: " << vec->size() << endl << endl;
}

void t6_5_print_database(const vector<string>* vec)
{
    //print
    cout << endl << "Names in database: ";
    for (string name : *vec) {
        cout << name << " ";
    }
    cout << endl << endl;
}

// save(), to save the vector into a text file (e.g. one name per row). The file name is given by the user.
// Existing content can be overwritten.
void t6_6_save_database(const vector<string>* vec) {
    using std::fstream;
    cout << "Give filename to save file: ";
    string filename;
    cin >> filename;
    fstream txt_file;
    txt_file.open(filename, std::ios::out);//ios::out writes to file, ios::app appends to file
    if (txt_file.is_open()) {
        for (string name : *vec) {
            txt_file << name << endl;
        }
        txt_file.close();
        cout << "Names saved to file.\n\n";
    }
    else
        cout << "Incorrect filename.\n\n";
}

// load(), to load names from the text file into the vector . The text file name is given by the user.
// Make sure to empty the vector before loading content into it!

void t6_7_load_database(vector<string>* vec) {
    using std::fstream;
    vec->clear(); //Empties the vector
    cout << "Give filename to load file: ";
    string filename;
    cin >> filename;
    fstream txt_file;
    txt_file.open(filename, std::ios::in);//read
    if (txt_file.is_open()) {
        string name;
        while (getline(txt_file, name)) {
            vec->push_back(name);
        }
        cout << "Names loaded from file.\n\n";
    }
    else
        cout << "Incorrect filename.\n\n";
}

void task_6_modular_vector_database_with_pointers() {
    /* Task 6: Modular vector database with pointers
    Modify your vector database solution (Task 6, week 2):

    Create a function for the features (if you have not done it already): initialise, insert, search, delete, print.
    Use a pointer to the vector to pass it to the functions (e.g. insert(vector *database, ...))
    think of suitable return values to the functions (e.g. a “bool” or an error code to indicate success or failure)!
    If the function does not modify the vector, declare the parameter as const.
    Implement two new functions for File IO:
    save(), to save the vector into a text file (e.g. one name per row). The file name is given by the user. Existing
    content can be overwritten.
    load(), to load names from the text file into the vector . The text file name is given by the user. Make sure to
    empty the vector before loading content into it!
    Make sure to show appropriate error messages when the user input is wrong (e.g. a file name is given for load() that
    does not exist). */
    cout << "\n***Task 6 - Vector database***" << endl;
    cout << "This is a simple database system that stores names of persons in a vector." << endl;
    int input;
    vector<string> vec;
    do
    {
        t6_database_menu();
        while (!(cin >> input))
        {
            cout << "Incorrect input.\n";
            cin.clear();
            (void)cin.ignore(INT64_MAX, '\n');
            main_menu();
        }
        switch (input)
        {
        case 1: t6_1_initialize_database(&vec);
            break;
        case 2: t6_2_insert_names(&vec);
            break;
        case 3: t6_3_search_string(&vec);
            break;
        case 4: t6_4_delete_name(&vec);
            break;
        case 5: t6_5_print_database(&vec);
            break;
        case 6: t6_6_save_database(&vec);
            break;
        case 7: t6_7_load_database(&vec);
            break;
        case 8: cout << "Goodbye!" << endl;
            break;
        default: cout << "Sorry, there is no such task!" << endl;
            break;
        }
    } while (input != 8);
}

int main() {
    int input;
    do
    {
        main_menu();
        while (!(cin >> input))
        {
            cout << "Incorrect input.\n";
            cin.clear();
            (void)cin.ignore(INT_MAX, '\n');
            main_menu();
        }
        switch (input)
        {
        case 1: task_1_string_length();
            break;
        case 2: task_2_average_salaries();
            break;
        case 3: task_3_swap_sort_with_pointers();
            break;
        case 4: task_4_swap_sort_with_double_pointers();
            break;
        case 5: task_5_character_replacement_with_pointers();
            break;
        case 6: task_6_modular_vector_database_with_pointers();
            break;
        case -1: cout << "Goodbye!" << endl;
            break;
        default: cout << "Sorry, there is no such task!" << endl;
            break;
        }
    } while (input != -1);
    return 0;
}