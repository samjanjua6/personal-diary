#include<iostream>   //input output
#include<conio.h>    //_getche();
#include<string>     //getline and strings
#include<fstream>    // file input output

#define RED     "\033[31m"      
#define GREEN   "\033[32m"   //escape codes
#define MAGENTA "\033[35m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"
#define length 50



//#define UNDERLINE   "\033[4m"

//#define SWAP   "\033[7m"



using namespace std;

void passward();    //declaration
void addrecord();
void viewrecord();
void editrecord();
void deleterecord();

struct record
{
    string time;
    string name;
    string place;
    string explain;
    string topic;
};

int main()
{
    
   invalidd:
    int switch_on;
    system("cls");

    cout << "\t\n********************************************";
    cout << "\t\n*            Personal Diary                *";
    cout << "\t\n********************************************" << endl;
    cout << "created by :- " <<YELLOW << "Samreen * " << MAGENTA << "Shaheer" <<  YELLOW << " * Maryam" << RESET;
    cout << "\n\n";
    cout << "\tAdd Record \t[1]\n";
    cout << "\tView Record\t[2]\n";
    cout << "\tEdit Record\t[3]\n";
    cout << "\tDelete Record\t[4]\n";
    cout << "\tExit\t\t[5]\n\n";
    cout << "\tSelect an option: ";
    cin >> switch_on;

    switch (switch_on)
    {

    case 1:
        passward();
        addrecord();
        break;
    case 2:
        passward();
        viewrecord();
        break;
    case 3:
        passward();
        editrecord();
        break;
    case 4:
        passward();
        deleterecord();
        break;
    case 5:
        exit(0);
    default:
        cout << RED << "Invalid option." << RESET << endl;
        cout << "Press any key to try again" << endl;
        _getche();
        
        goto invalidd;
        break;
    }
    return 0;
}

void passward()
{
    string pass;
    string username;
    const int maxnumattpass = 3;
    int attempts = 0;   // actual attempts
    int remaining = 3;  //just to show show remaining attempts on screen
    cout <<  YELLOW << "\nFor extra protection only three tries are allowed !" << endl << RESET;
    do {
        cout << "Enter the username: ";
        cin >> username;
        cout << "Enter your password: ";
        // cin >> pass;
        char ch;
        while ((ch = _getch()) != '\r')
        {
            pass.push_back(ch);
            cout << '*';
        }
        if (username == "samreen" && pass == "@12345")
        {
            cout << GREEN << "\nCorrect Password !" << RESET << endl;
            break;
        }
        else
        {
            cout << RED << "\nInvalid username or password. Please try again." << RESET << endl;
            pass.clear();
            attempts++;
            remaining--;
            cout << "\n" << remaining << " Attempts Remaining\n" << endl;
            if (attempts >= maxnumattpass)
            {
                cout << RED << "maximum attempts reached.exit program" <<RESET<< endl;
                exit(0);
            }
        }
    } while (true);
}

void addrecord()
{
    string filename;
    record e;
    ofstream outFile;

    cout << "\n************************************";
    cout << "\n*          Adding Record           *";
    cout << "\n************************************";
    cout << "\n\n\n";

    cout << "\nEnter DATE OF YOUR RECORD [yyyy-mm-dd]: ";
    cin >> filename;
    cin.ignore();                                                // Clear the newline character from the buffer

    outFile.open(filename,ios::app);

    if (!outFile.is_open())
    {
        cout << RED << "Error opening file." << RESET << endl;
        return;
    }

    cout << "Enter Name of client: ";
    getline(cin, e.name);
    cout << "Enter Place of incident: ";
    getline(cin, e.place);
    cout << "Enter time: ";
    getline(cin, e.time);
    cout << "Define Topic: ";
    getline(cin, e.topic);
    cout << "Explain Incident: ";
    getline(cin, e.explain);

    outFile << "TIME: " << e.time << endl;
    outFile << "MEETING WITH: " << e.name << endl;
    outFile << "MEETING AT: " << e.place << endl;
    outFile << "TOPIC: " << e.topic << endl;
    outFile << "NOTE: " << e.explain << endl;

    cout << GREEN << "Record added successfully." << RESET << endl;
    outFile.close();
    cout << "Press Enter to return to main menu !";
    _getche();
    main();
}

void viewrecord()
{
    string filename;
    record e;
    ifstream inFile;

    cout << "\n**************";
    cout << "\n*          Viewing Record          *";
    cout << "\n**************";
    cout << "\n\n\n";

    cout << "Enter DATE OF YOUR RECORD TO VIEW [yyyy-mm-dd]: ";
    cin >> filename;

    inFile.open(filename);

    if (!inFile.is_open())
    {
        cout << RED << "File not found or unable to open." << RESET << endl;
        cout << "Press Enter to return to main menu !";
        _getche();
        main();
    }

    string line;
    while (getline(inFile, line))
    {
        cout << line << endl;
    }

    inFile.close();

    _getche();
    main();                                               // Wait for user input
}

void editrecord()
{
    string filename;
    record e;
    ifstream inFile;  //
    ofstream outFile;

    cout << "\n************************************";
    cout << "\n*            Edit Record           *";
    cout << "\n************************************";
    cout << "\n\n\n";

    cout << "Enter DATE OF YOUR RECORD TO EDIT [yyyy-mm-dd]: ";
    cin >> filename;
    cin.ignore(); // Clear the newline character from the buffer

    inFile.open(filename);

    if (!inFile.is_open())
    {
        cout << RED << "File not found or unable to open." << RESET << endl;
        cout << "Press Enter to return to main menu !";
        _getche();
        main();
    }

    cout << "Current record:" << endl;
    string line;
    while (getline(inFile, line))
    {
        cout << line << endl;
    }

    inFile.close();

    outFile.open(filename);

    if (!outFile.is_open())
    {
        cout <<RED <<"Error opening file for writing." <<RESET<< endl;
        cout << "Press Enter to return to main menu !";
        _getche();
        main();
    }

    cout << "\nEnter the new data:" << endl;

    cout << "NEW TIME [hh:mm]: ";
    getline(cin, e.time);
    cout << "NEW MEETING PERSON: ";
    getline(cin, e.name);
    cout << "NEW MEETING PLACE: ";
    getline(cin, e.place);
    cout << "NEW TOPIC: ";
    getline(cin, e.topic);
    cout << "NEW NOTE: ";
    getline(cin, e.explain);

    outFile << "TIME: " << e.time << endl;
    outFile << "MEETING WITH: " << e.name << endl;
    outFile << "MEETING AT: " << e.place << endl;
    outFile << "TOPIC: " << e.topic << endl;
    outFile << "NOTE: " << e.explain << endl;

    cout << GREEN << "Record edited successfully." << RESET << endl;
    outFile.close();
    cout << "Press Enter to return to main menu !";
    _getche();
    main();
}

void deleterecord()
{
    string filename;
    cout << "Enter the DATE OF YOUR RECORD TO BE DELETED [yyyy-mm-dd]: ";
    cin >> filename;

    if (remove((filename).c_str()) == 0)
    {
        cout << GREEN << "Record deleted successfully." << RESET << endl;
    }
    else
    {
        cout << RED << "Error deleting file or file not found" << RESET << endl;
    }
    cout << "Press Enter to return to main menu !";
    _getche();
    main();
}

