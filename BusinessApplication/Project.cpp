#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <Windows.h>
using namespace std;

// Welcome screen logo
void welcomeLogo();

// Header
void header();

// Funtion will give invaid input
void invalid();

// Main menu funtions
string mainMenu();

// Clear funtion
void clear();

// Sign up functons
void signUp(string name, string password, string role);

// Sign in funtions
string signIn(string name, string password);

// For viewing users
void viewUsers();

// check if user is valid
bool isValidUser(string name);

// Function to store the data
void storeTheData(string name, string password, string role);

// Funtions to read the data from file
void readTheData();

// User funtions

// Displays user interface
string userMenu();
void userInterface();

// Funtion to check length of CNIC entered
int CNICcheck(string IDnumber);

// Function to check if entered seat is occupied or not and also checks CNIC
bool seatCheck(string name, string seatNo, string IDnumber);
// bool seatsLimit(string seat);

// Funtion used for seat booking
void bookTicket(string name, string seatNo, string IDnumber, string location, int bill);

// Funtion for check bill according to location
int getBill(string location);

// Used to check if location is valid or not
void checkLocation(int bill);

// Used to check validation of CNIC
void checkCNIClength(int IDnumber);

// Used to view index if entered seat number
int getIndex(string name);

// Funtions to store and read passengers data
void storePassengersData();

// Funtion to read passengers
void readPassengersData();

// Funtion which will give string according to commas
string getLine(string word, int field);

// Funtion to view a passenger information
void showPassenInfo(string name);

// Funtion which will show change menu
string changeMenu();

// Funtion which will show change interface
void changeInterface(int index);

// Funtions for changing information
void changeName(int index);
void changeSeat(int index);
void changeCNIC(int index);
void changeDestination(int index);

// Funtions for checking seat number and CNIC
bool checkSeat(string seatNo);
bool checkCNIC(string IDnumber);

// Funtion to change passenger information
void changeInformation(string name);

// Funtion to cancel the ticket
void ticketCancel(string name);

// Funtion will delete the ticket information
void deleteTicketInfo(int index);

// Function which will ask for confirmation
string confirmation();

// Funtion which will display ticket cancel
void operationCancelled();

// Funtion to view bus information
string viewBusInfoMenu();
void viewBusInfo();

// Funtion to show bus information
void showBusInfo();

// Funtion to show contact information
void showContactInfo();
// Funtion to give feedbacks
void giveFeedback();

// Function to store feedback
void storeFeedback();

// Funtion to confirm feedbacks
void confirmFeedback();

// Funtion to store feedback in file
void storeFeedbackinFile();
void readFeedbacks();

// Funtion will show help menu
string helpMenu();

// Funtion which will show help Interface
void helpInterface();

// Funtion to view location
void viewLocations();

// Funtion to give information about ticket booking
void ticketBookingHelp();

// Funtion to check information
void checkInfoHelp();

// Display manager interface
string managerMenu();
void managerInterface();

// Funtion to view passengers information
void viewPassenInfo();

// Fuction to change bus information
string changeInfoMenu();
void changeBusInfo();

// Funtion to change bus information
void changeDriver(); // Change driver
void updateSeats();  // Update seats capacity

// Funtions to change interface
string changeFaresMenu();
void changeFares();

// Funtion wil enter and return fare
string returnFare();

// Funtion to check fare
bool checkFare(string fare);

// Funtion to view feedback
void viewFeedbacks();

// Funtion to change driver's pay
void changePay();

// Funtion to enter driver's pay
void enterPay();

// Funtion which will show invalid input
void invalidInput();

// Varialbes

// Signup Array size
const int signUPSize = 100;

// Passengers Array size
const int passenSize = 50;

// Variables that contain Bus information
string driverName = "Ali";          // Driver name
string busName = "Daewoo";          // Bus name
int seatCapacity = 50;              // Seats capacity
string Contact_no = "03090442288";  // Contact number
string website = "www.skyways.com"; // Website

// Signup and Signin Arrays
string userName[signUPSize]; // User names array
string passWord[signUPSize]; // Passwords array
string userRole[signUPSize]; // User roles array

// Arrays for ticket booking
string passName[passenSize];   // Passengers name array
string SeatNo[passenSize];     // Seat number array
string CNICnumber[passenSize]; // CNIC number arrray
string Loaction[passenSize];   // Location array
int Bill[passenSize];          // Bill array

// Arrays for feedback
string FeedbackName[passenSize];
string Feedback[passenSize];

// Users count initialized as zero
int usersCount = 0;

// Passengers count initialized as zero
int PassenCount;

// Feedbacks count initialized as zero
int feedbackCount = 0;

// Variables that contain ticket prices
string faisTicket = "1200"; // Faisalabad ticket
string lhrTicket = "1000";  // Lahore ticket
string sialTicket = "1800"; // Sialkot ticket
string islTicket = "2000";  // Islamabad ticket
string mulTicket = "1100";  // Multan ticket

const int destSize = 50;
string Areas[destSize] = {"Faislabad", "Multan", "Lahore", "Sialkot", "Karachi"};
int Prices[destSize] = {1000, 800, 1200, 1300, 3000};
int destcount = 5;

// Driver's pay
string driverPay = "40000";

// Variables for ticket booking
string name, seatNumber, idNumber, location;
int bill;

// Ignore variable
string ignore;

// Feedback variables
string feedbackName, feedback;

// Other variables
bool value;
int IdNumberlength;
string choice;
string answer;
string option;
main()
{
    system("cls");
    welcomeLogo();
    clear();
    readTheData();
    readFeedbacks();
    readPassengersData();
    string name, Password, role;
    while (option != "4")
    {
        header();
        option = mainMenu();
        if (option == "1")
        {
            cout << "Enter user name : ";
            cin >> name;
            cout << "Enter password : ";
            cin >> Password;
            int length = Password.length();
            cout << "Enter the role (manager/user) : ";
            cin >> role;
            bool result = isValidUser(name);
            if (result == true && (role == "manager" || role == "user") && length == 5)
            {
                storeTheData(name, Password, role);
                signUp(name, Password, role);
            }
            else if (length != 5)
            {
                cout << "Password length must be 5" << endl;
                clear();
            }
            else if (result == false)
            {
                cout << "User already exist! " << endl;
                clear();
            }
            else if ((role != "manager" || role != "user"))
            {
                cout << "Invalid role entered! " << endl;
                clear();
            }
        }

        else if (option == "2")
        {
            cout << "Enter user name : ";
            cin >> name;
            cout << "Enter password : ";
            cin >> Password;
            string result = signIn(name, Password);
            if (result == "manager" || result == "Manager")
            {
                cout << "Signed in successfully " << endl;
                managerInterface();
            }

            if (result == "user" || result == "User")
            {
                cout << "Signed in successfully " << endl;
                clear();
                userInterface();
            }

            if (result == "undefined")
            {
                cout << "Invalid entery! " << endl;
                clear();
            }
        }

        else if (option == "3")
        {
            viewUsers();
        }

        else if (option == "4")
        {
            system("cls");
            welcomeLogo();
            clear();
            break;
        }

        else
        {
            invalid();
        }
    }
}

string mainMenu()
{
    string choice;
    cout << "....................................." << endl;
    cout << "1.\tSign up" << endl;
    cout << "2.\tSign in" << endl;
    cout << "3.\tView users" << endl;
    cout << "4.\tExit" << endl;
    cout << "_____________________________________" << endl;
    cout << "Please enter your choice : ";
    cin >> choice;
    return choice;
}

void invalid()
{
    cout << "Invalid entity! " << endl;
    clear();
}

void signUp(string name, string password, string role)
{
    userName[usersCount] = name;
    passWord[usersCount] = password;
    userRole[usersCount] = role;
    usersCount++;
    cout << "Signed up successfully " << endl;
    clear();
}

void storeTheData(string name, string password, string role)
{
    fstream Data;
    Data.open("User.txt", ios::app);
    Data << name << "," << password << "," << role << endl;
}

void viewUsers()
{
    cout << "Name\t\tRole" << endl;
    cout << "_____________________________" << endl;
    for (int i = 0; i < usersCount; i++)
    {
        cout << userName[i] << "\t\t" << userRole[i] << endl;
    }
    clear();
}

string signIn(string name, string password)
{

    for (int i = 0; i < usersCount; i++)
    {
        if (name == userName[i] && password == passWord[i])
        {
            return userRole[i];
            break;
        }
    }
    return "undefined";
}

bool isValidUser(string name)
{
    for (int i = 0; i < usersCount; i++)
    {
        if (name == userName[i])
        {
            return false;
            break;
        }
    }
    return true;
}

void clear()
{
    cout << "Press any key to continue..........";
    getch();
    system("cls");
}

void readTheData()
{
    string word;
    fstream Data;
    Data.open("User.txt", ios::in);
    if (Data)
    {
        while (!(Data.eof()))
        {
            getline(Data, word);
            userName[usersCount] = getLine(word, 1);
            passWord[usersCount] = getLine(word, 2);
            userRole[usersCount] = getLine(word, 3);
            usersCount++;
        }
    }
    Data.close();
}

string getLine(string word, int field)
{
    int comma = 1;
    string item;
    for (int x = 0; x < word.length(); x++)
    {
        if (word[x] == ',')
        {
            comma = comma + 1;
        }
        else if (comma == field)
        {
            item = item + word[x];
        }
    }
    return item;
}

void welcomeLogo()
{
    cout << "                 ______   ___  ____  ____  ____   _________  _______          _  ____   ____  ________  _____      ______             " << endl;
    cout << "               .' ____ \\ |_  ||_  _||_  _||_  _| |  _   _  ||_   __ \\        / \\|_  _| |_  _||_   __  ||_   _|   .' ____ \\        " << endl;
    cout << "               | (___ \\_|  | |_/ /    \\ \\  / /   |_/ | | \\_|  | |__) |      / _ \\ \\ \\   / /    | |_ \\_|  | |     | (___ \\_|  " << endl;
    cout << "                _.____`.   |  __'.     \\ \\/ /        | |      |  __ /      / ___ \\ \\ \\ / /     |  _| _   | |   _  _.____`.       " << endl;
    cout << "               | \\____) | _| |  \\ \\_   _|  |_       _| |_    _| |  \\ \\_  _/ /   \\ \\_\\ ' /     _| |__/ | _| |__/ || \\____) |  " << endl;
    cout << "                \\______.'|____||____| |______|     |_____|  |____| |___||____| |____|\\_/     |________||________| \\______.'        " << endl;
}

void header()
{
    system("cls");
    cout << "********************************************************************************************" << endl;
    cout << "*                                  SKY TRAVELS                                             *" << endl;
    cout << "********************************************************************************************" << endl;
}

string userMenu()
{
    header();
    cout << "........................................................." << endl;
    cout << "1.\tBook a ticket online" << endl;
    cout << "2.\tView your ticket information" << endl;
    cout << "3.\tChange your information" << endl;
    cout << "4.\tCancel your ticket" << endl;
    cout << "5.\tView bus information " << endl;
    cout << "6.\tGive feedback" << endl;
    cout << "7.\tHelp" << endl;
    cout << "8.\tExit" << endl;
    cout << "__________________________________________________________" << endl;
    cout << "Please enter your choice : ";
    cin >> choice;
    return choice;
}

void userInterface()
{
    string userOption;
    int seatNum;
    while (userOption != "8")
    {
        header();
        userOption = userMenu();
        if (userOption == "1")
        {
            cout << " ";
            getline(cin, ignore);
            cout << "Enter your name : ";
            getline(cin, name);
            cout << " Enter your destination : ";
            getline(cin, location);
            cout << " Enter seat number : ";
            getline(cin, seatNumber);
            cout << " Enter Your CNIC number : ";
            getline(cin, idNumber);
            IdNumberlength = CNICcheck(idNumber);
            bool check = checkFare(seatNumber);
            if (check == true)
            {
                seatNum = stoi(seatNumber);
                value = seatCheck(name, seatNumber, idNumber);
                bill = getBill(location);
                if (value == false && IdNumberlength == 13 && bill != -1 && seatNum <= seatCapacity)
                {
                    bookTicket(name, seatNumber, idNumber, location, bill);
                    Bill[PassenCount] = bill;
                    storePassengersData();
                    PassenCount++;
                    cout << "Seat number " << seatNumber << " has been booked successfully..." << endl;
                    clear();
                }
                if (value == true)
                {
                    cout << "Seat already booked! " << endl;
                    clear();
                }
                if (seatNum > seatCapacity)
                {
                    cout << "Seat not available! " << endl;
                    cout << "Seat capacity is : " << seatCapacity << endl;
                    clear();
                }

                checkLocation(bill);
                checkCNIClength(IdNumberlength);
            }
            else
            {
                cout << "Invalid seat number entered! " << endl;
                clear();
            }
        }

        else if (userOption == "2")
        {
            cout << " ";
            getline(cin, ignore);
            cout << "Please enter your name : ";
            getline(cin, name);
            showPassenInfo(name);
        }

        else if (userOption == "3")
        {
            cout << " ";
            getline(cin, ignore);
            cout << " Please confirm your name : ";
            getline(cin, name);
            changeInformation(name);
        }

        else if (userOption == "4")
        {
            cout << " ";
            getline(cin, ignore);
            cout << "Please confirm your name here : ";
            getline(cin, name);
            ticketCancel(name);
        }

        else if (userOption == "5")
        {
            viewBusInfo();
        }

        else if (userOption == "6")
        {
            giveFeedback();
        }

        else if (userOption == "7")
        {
            helpInterface();
        }

        else if (userOption == "8")
        {
            break;
        }

        else
        {
            invalid();
        }
    }
}

void storePassengersData()
{
    fstream PassengersData;
    PassengersData.open("Passenger.txt", ios::out);
    for (int i = 0; i < PassenCount + 1; i++)
    {
        PassengersData << passName[i] << "," << SeatNo[i] << "," << CNICnumber[i] << "," << Loaction[i] << "," << Bill[i] << endl;
    }
    PassengersData.close();
}

void readPassengersData()
{
    string word;
    fstream PassengersData;
    PassengersData.open("Passenger.txt", ios::in);
    if (PassengersData)
    {
        while (!(PassengersData.eof()))
        {
            getline(PassengersData, word);
            if (word == "")
                break;
            passName[PassenCount] = getLine(word, 1);
            SeatNo[PassenCount] = getLine(word, 2);
            CNICnumber[PassenCount] = getLine(word, 3);
            Loaction[PassenCount] = getLine(word, 4);
            Bill[PassenCount] = stoi(getLine(word, 5));
            PassenCount++;
        }
    }
    PassengersData.close();
}

int CNICcheck(string IDnumber)
{
    int count = 0;
    int length = IDnumber.length();
    for (int i = 0; i < length; i++)
    {
        int value1 = IDnumber[i] - '0';
        if (value1 >= 0 && value1 < 10)
        {
            count++;
        }
    }
    return count;
}

bool seatCheck(string name, string seatNo, string IDnumber)
{
    for (int i = 0; i < PassenCount; i++)
    {
        if (name == passName[i] || seatNo == SeatNo[i] || IDnumber == CNICnumber[i])
        {
            return true;
        }
    }
    return false;
}

void bookTicket(string name, string seatNo, string IDnumber, string location, int bill)
{
    if (PassenCount < passenSize)
    {
        passName[PassenCount] = name;
        SeatNo[PassenCount] = seatNo;
        CNICnumber[PassenCount] = IDnumber;
        Loaction[PassenCount] = location;
        Bill[PassenCount] = bill;
    }
}

int getBill(string location)
{
    int bill = -1;
    for (int i = 0; i < destSize; i++)
    {
        if (location == Areas[i])
        {
            bill = Prices[i];
            break;
        }
    }
    return bill;
}

void checkLocation(int bill)
{
    if (bill == -1)
    {
        cout << "Invalid location entered! " << endl;
        clear();
    }
}

void checkCNIClength(int IDnumber)
{
    if (IDnumber != 13)
    {
        cout << "Invalid CNIC entered! " << endl;
        clear();
    }
}

int getIndex(string name)
{
    for (int i = 0; i < PassenCount; i++)
    {
        if (name == passName[i])
        {
            return i;
            break;
        }
    }

    return 404;
}

void showPassenInfo(string name)
{
    int index;
    index = getIndex(name);
    if (index == 404)
    {
        cout << "There is no passenger with this name! " << endl;
        clear();
    }

    else
    {
        cout << "......................................................................................................" << endl;
        cout << "Name\t\tCNIC Number       \tSeat Number        \tDestination      \tBill" << endl;
        cout << passName[index] << "\t\t" << CNICnumber[index] << "        \t" << SeatNo[index] << "       \t\t" << Loaction[index] << "      \t\t" << Bill[index] << endl;
        cout << "_____________________________________________________________________________________________________ " << endl;
        clear();
    }
}

string changeMenu()
{
    system("cls");
    header();
    cout << "....................................." << endl;
    cout << "1.\tChange name" << endl;
    cout << "2.\tChange Seat number" << endl;
    cout << "3.\tChange CNIC number" << endl;
    cout << "4.\tChange destination" << endl;
    cout << "5.\tBack" << endl;
    cout << "_____________________________________" << endl;
    cout << "Please enter your choice : ";
    cin >> choice;
    return choice;
}

void changeInterface(int index)
{
    string changeOption;
    while (changeOption != "5")
    {
        changeOption = changeMenu();
        if (changeOption == "1")
        {
            changeName(index);
            storePassengersData();
        }

        else if (changeOption == "2")
        {
            changeSeat(index);
            storePassengersData();
        }

        else if (changeOption == "3")
        {
            changeCNIC(index);
            storePassengersData();
        }

        else if (changeOption == "4")
        {
            changeDestination(index);
            storePassengersData();
        }

        else if (changeOption == "5")
        {
            break;
        }

        else
        {
            invalid();
        }
    }
}

void changeInformation(string name)
{
    int index;
    index = getIndex(name);
    if (index == 404)
    {
        cout << "There is no passenger with this name! " << endl;
        clear();
    }

    else
    {
        changeInterface(index);
    }
}

void changeName(int index)
{
    cout << " ";
    getline(cin, ignore);
    cout << " Enter your name again : ";
    getline(cin, name);
    passName[index] = name;
    cout << "Your name has been changed successfully..." << endl;
    clear();
}

bool checkSeat(string seatNo)
{
    for (int i = 0; i < PassenCount; i++)
    {
        if (seatNo == SeatNo[i])
        {
            return true;
        }
    }
    return false;
}

bool checkCNIC(string IDnumber)
{
    for (int i = 0; i < PassenCount; i++)
    {
        if (IDnumber == CNICnumber[i])
        {
            return true;
        }
    }
    return false;
}

void changeSeat(int index)
{
    cout << " ";
    getline(cin, ignore);
    cout << " Enter new seat number : ";
    getline(cin, seatNumber);
    value = checkSeat(seatNumber);
    if (value == true)
    {
        cout << "This seat is already booked!" << endl;
        clear();
    }

    else
    {
        SeatNo[index] = seatNumber;
        cout << "Your seat has been changed successfully..." << endl;
        clear();
    }
}

void changeCNIC(int index)
{
    cout << " ";
    getline(cin, ignore);
    cout << " Enter new CNIC number : ";
    getline(cin, idNumber);
    value = checkCNIC(idNumber);
    IdNumberlength = CNICcheck(idNumber);
    if (value == true)
    {
        cout << "          Warning           " << endl;
        cout << "This CNIC is already in use!" << endl;
        clear();
    }

    if (value == false && IdNumberlength == 13)
    {
        CNICnumber[index] = idNumber;
        cout << "Your CNIC has been changed successfully..." << endl;
        clear();
    }
    checkCNIClength(IdNumberlength);
}

void changeDestination(int index)
{
    cout << " ";
    getline(cin, ignore);
    cout << "Enter new destination : ";
    getline(cin, location);
    bill = getBill(location);
    if (bill != -1)
    {
        Loaction[index] = location;
        Bill[index] = bill;
        cout << "Your destination has been changed successfully..." << endl;
        clear();
    }
    checkLocation(bill);
}

void ticketCancel(string name)
{
    int index = getIndex(name);
    if (index == 404)
    {
        cout << "There is no passenger with this name! " << endl;
        clear();
    }

    else
    {
        answer = confirmation();
        if (answer == "y")
        {
            deleteTicketInfo(index);
            cout << "The ticket has been cancelled successfully" << endl;
            clear();
        }

        else if (answer == "n")
        {
            operationCancelled();
        }

        else
        {
            invalid();
        }
    }
}

string confirmation()
{
    string reply;
    cout << "Do you really want to proceed ? (y/n) : ";
    cin >> reply;
    return reply;
}

void deleteTicketInfo(int index)
{
    for (int i = index; i < usersCount; i++)
    {
        passName[i] = passName[i + 1];
        SeatNo[i] = SeatNo[i + 1];
        CNICnumber[i] = CNICnumber[i + 1];
        Loaction[i] = Loaction[i + 1];
        Bill[i] = Bill[i + 1];
        storePassengersData();
    }
    usersCount--;
}

void operationCancelled()
{
    cout << "The operation has been cancelled " << endl;
    clear();
}

string viewBusInfoMenu()
{
    header();
    cout << "..................................." << endl;
    cout << "1.\tView bus information" << endl;
    cout << "2.\tContact info" << endl;
    cout << "3.\tBack" << endl;
    cout << "___________________________________" << endl;
    cout << "Please enter your choice : ";
    cin >> choice;
    return choice;
}

void viewBusInfo()
{
    string viewOption;
    while (viewOption != "3")
    {
        viewOption = viewBusInfoMenu();
        if (viewOption == "1")
        {
            showBusInfo();
        }

        else if (viewOption == "2")
        {
            showContactInfo();
        }

        else if (viewOption == "3")
        {
            break;
        }

        else
        {
            invalid();
        }
    }
}

void showBusInfo()
{
    header();
    cout << "+..............................................+" << endl;
    cout << "Our driver name is : Mr. " << driverName << endl;
    cout << "Our bus name is : " << busName << endl;
    cout << "The seat capacity of our bus is : " << seatCapacity << endl;
    cout << "+______________________________________________+" << endl;
    clear();
}

void showContactInfo()
{
    header();
    cout << "+..............................................+" << endl;
    cout << "Contact us at : " << Contact_no << endl;
    cout << "Visit us at : " << website << endl;
    cout << "+______________________________________________+" << endl;
    clear();
}

void giveFeedback()
{
    cout << "Your feedback is imprtant for us " << endl;
    getline(cin, ignore);
    cout << "Enter your name here : ";
    getline(cin, feedbackName);
    cout << "Enter your feedback here : ";
    getline(cin, feedback);
    confirmFeedback();
}

void confirmFeedback()
{
    answer = confirmation();
    if (answer == "y")
    {
        storeFeedback();
        storeFeedbackinFile();
    }

    else if (answer == "n")
    {
        operationCancelled();
    }
}

void storeFeedback()
{
    FeedbackName[feedbackCount] = feedbackName;
    Feedback[feedbackCount] = feedback;
    feedbackCount++;
    cout << "Thank you for your feedback " << endl;
    clear();
}

void storeFeedbackinFile()
{
    fstream FeedbacksData;
    FeedbacksData.open("Feedback.txt", ios::app);
    FeedbacksData << feedbackName << endl;
    FeedbacksData << feedback << endl;
    FeedbacksData.close();
}

void readFeedbacks()
{
    string feedName, feedback;
    fstream FeedbacksData;
    FeedbacksData.open("Feedback.txt", ios::in);
    while (getline(FeedbacksData, feedName), getline(FeedbacksData, feedback))
    {
        FeedbackName[feedbackCount] = feedName;
        Feedback[feedbackCount] = feedback;
        feedbackCount++;
    }
    FeedbacksData.close();
}
string helpMenu()
{
    header();
    cout << "......................................" << endl;
    cout << "1.\tView available locations" << endl;
    cout << "2.\tHow to book a ticket" << endl;
    cout << "3.\tHow to report a problem" << endl;
    cout << "4.\tHow to check your information" << endl;
    cout << "5.\tBack" << endl;
    cout << "______________________________________" << endl;
    cout << "Please enter your choice : ";
    cin >> choice;
    return choice;
}

void helpInterface()
{
    string helpOption;
    while (helpOption != "5")
    {
        helpOption = helpMenu();
        if (helpOption == "1")
        {
            viewLocations();
        }
        else if (helpOption == "2")
        {
            ticketBookingHelp();
        }

        else if (helpOption == "3")
        {
            cout << "Visit our website " << website << " to report a problem" << endl;
            clear();
        }

        else if (helpOption == "4")
        {
            checkInfoHelp();
        }

        else if (helpOption == "5")
        {
            break;
        }

        else
        {
            invalid();
        }
    }
}

void viewLocations()
{
    header();
    cout << "......................................" << endl;
    cout << "  \tLocation\t\tPrice" << endl;
    cout << "1.\tfaisalabad\t\t" << faisTicket << endl;
    cout << "2.\tlahore    \t\t" << lhrTicket << endl;
    cout << "3.\tfaisalabad\t\t" << sialTicket << endl;
    cout << "4.\tislamabad \t\t" << islTicket << endl;
    cout << "5.\tmultan    \t\t" << mulTicket << endl;
    cout << "______________________________________" << endl;
    clear();
}

void ticketBookingHelp()
{
    header();
    cout << "............................................." << endl;
    cout << "Step 1.Slect book ticket menu " << endl;
    cout << "Step 2.Enter your information " << endl;
    cout << "Step 3.Now you can book your ticket online" << endl;
    cout << "_____________________________________________" << endl;
    clear();
}

void checkInfoHelp()
{
    header();
    cout << ".................................................." << endl;
    cout << "Step 1.Select option to view your informaton " << endl;
    cout << "Step 2.Enter your name to view your information" << endl;
    cout << "Now you can view your information" << endl;
    cout << "__________________________________________________" << endl;
    clear();
}

string managerMenu()
{
    string choice;
    system("cls");
    header();
    cout << "........................................................." << endl;
    cout << "1.\tAllot the tickets" << endl;
    cout << "2.\tView passengers info" << endl;
    cout << "3.\tCancel the ticket" << endl;
    cout << "4.\tChange bus info" << endl;
    cout << "5.\tChange fares" << endl;
    cout << "6.\tChange driver's pay" << endl;
    cout << "7.\tView feedBacks" << endl;
    cout << "8.\tExit" << endl;
    cout << "__________________________________________________________" << endl;
    cout << "Please enter your choice : ";
    cin >> choice;
    return choice;
}

void managerInterface()
{
    string managerOption;
    int seatNum;
    while (managerOption != "8")
    {
        managerOption = managerMenu();
        if (managerOption == "1")
        {
            cout << " ";
            getline(cin, ignore);
            cout << "Enter name of the passenger : ";
            getline(cin, name);
            cout << " Enter the destination : ";
            getline(cin, location);
            cout << " Enter seat number you want to allot : ";
            getline(cin, seatNumber);
            cout << " Enter CNIC number of the passenger : ";
            getline(cin, idNumber);
            IdNumberlength = CNICcheck(idNumber);
            bool check = checkFare(seatNumber);
            if (check == true)
            {
                seatNum = stoi(seatNumber);
                value = seatCheck(name, seatNumber, idNumber);
                bill = getBill(location);
                if (value == false && IdNumberlength == 13 && bill != -1 && seatNum <= seatCapacity)
                {
                    bookTicket(name, seatNumber, idNumber, location,bill);
                    Bill[PassenCount] = bill;
                    storePassengersData();
                    PassenCount++;
                    cout << "Seat number " << seatNumber << " has been booked successfully..." << endl;
                    clear();
                }
                if (value == true)
                {
                    cout << "Seat already booked! " << endl;
                    clear();
                }
                if (seatNum > seatCapacity)
                {
                    cout << "Seat not available! " << endl;
                    cout << "Seat capacity is : " << seatCapacity << endl;
                    clear();
                }

                checkLocation(bill);
                checkCNIClength(IdNumberlength);
            }
            else
            {
                cout << "Invalid seat number entered! " << endl;
                clear();
            }
        }

        else if (managerOption == "2")
        {
            viewPassenInfo();
        }

        else if (managerOption == "3")
        {
            cout << " ";
            getline(cin, ignore);
            cout << "Enter name of the passenger : ";
            getline(cin, name);
            ticketCancel(name);
        }

        else if (managerOption == "4")
        {
            changeBusInfo();
        }

        else if (managerOption == "5")
        {
            changeFares();
        }

        else if (managerOption == "6")
        {
            changePay();
        }

        else if (managerOption == "7")
        {
            viewFeedbacks();
        }

        else if (managerOption == "8")
        {
            break;
        }

        else
        {
            invalid();
        }
    }
}

void viewPassenInfo()
{
    if (PassenCount <= 0)
    {
        cout << "No seat has booked yet! " << endl;
        clear();
    }
    else
    {
        system("cls");
        cout << "......................................................................................................" << endl;
        cout << "Name\t\tCNIC Number       \tSeat Number        \tDestination           \tBill" << endl;
        for (int i = 0; i < PassenCount; i++)
        {
            cout << passName[i] << "\t\t" << CNICnumber[i] << "        \t" << SeatNo[i] << "       \t\t" << Loaction[i] << "          \t\t" << Bill[i] << endl;
        }
        cout << "______________________________________________________________________________________________________" << endl;
        clear();
    }
}

string changeInfoMenu()
{
    header();
    cout << ".................................." << endl;
    cout << "1.\tChange driver" << endl;
    cout << "2.\tUpdate seat capacity" << endl;
    cout << "0.\tBack" << endl;
    cout << "__________________________________" << endl;
    cout << "Please enter your chocie : ";
    cin >> choice;
    return choice;
}

void changeBusInfo()
{
    string changeOption;
    while (changeOption != "0")
    {
        header();
        changeOption = changeInfoMenu();
        if (changeOption == "1")
        {
            changeDriver();
        }
        else if (changeOption == "2")
        {
            updateSeats();
        }
        else if (changeOption == "0")
        {
            break;
        }
        else
        {
            invalid();
        }
    }
}

void changeDriver()
{
    cout << " ";
    getline(cin, ignore);
    cout << "Enter new driver name : ";
    getline(cin, name);
    answer = confirmation();
    if (answer == "y")
    {
        driverName = name;
        cout << "Diver name has been changed successfully " << endl;
        clear();
    }

    else if (answer == "n")
    {
        operationCancelled();
    }

    else
    {
        invalid();
    }
}

void updateSeats()
{
    int capacity;
    cout << "Enter new seat capacity of the bus : ";
    cin >> capacity;
    if (capacity <= 50 && capacity > 0)
    {
        seatCapacity = capacity;
        cout << "Seat capacity has been updated " << endl;
        clear();
    }

    else
    {
        cout << "Seat capacity must be between 1 & 50 " << endl;
        clear();
    }
}

void viewFeedbacks()
{
    if (feedbackCount == 0)
    {
        cout << "No feedback registered yet " << endl;
        clear();
    }
    else
    {
        header();
        cout << "           Comments            " << endl;
        cout << "..............................." << endl;
        for (int i = 0; i < feedbackCount; i++)
        {
            cout << i + 1 << ".";
            cout << "Name : " << FeedbackName[i] << endl;
            cout << "  Comments : " << Feedback[i] << endl;
            cout << endl;
        }
        clear();
    }
}

string changeFaresMenu()
{
    header();
    cout << "******Change Fares******" << endl;
    cout << "........................" << endl;
    cout << "1.\tFaislabad " << endl;
    cout << "2.\tLahore" << endl;
    cout << "3.\tSialkot" << endl;
    cout << "4.\tIslamabad" << endl;
    cout << "5.\tMultan" << endl;
    cout << "0.\tBack" << endl;
    cout << "________________________" << endl;
    cout << "Please select a option : ";
    cin >> choice;
    return choice;
}

string returnFare()
{
    string fare;
    cout << " ";
    getline(cin, ignore);
    cout << "Enter new fare : ";
    getline(cin, fare);
    bool check = checkFare(fare);
    if (check == true)
    {
        return fare;
    }
    else
    {
        return "404";
    }
}

void changeFares()
{
    string faresOption;
    string value;
    value = returnFare();
    while (faresOption != "6")
    {
        faresOption = changeFaresMenu();
        if (faresOption == "1")
        {

            if (value != "404")
            {
                faisTicket = value;
                cout << "Fare has been changed successfully " << endl;
                getch();
            }
            else
            {
                invalid();
            }
        }

        else if (faresOption == "2")
        {
            if (value != "404")
            {
                lhrTicket = value;
                cout << "Fare has been changed successfully " << endl;
                getch();
            }
            else
            {
                invalid();
            }
        }

        else if (faresOption == "3")
        {
            if (value != "404")
            {
                sialTicket = value;
                cout << "Fare has been changed successfully " << endl;
                getch();
            }
            else
            {
                invalid();
            }
        }

        else if (faresOption == "4")
        {
            if (value != "404")
            {
                islTicket = value;
                cout << "Fare has been changed successfully " << endl;
                getch();
            }
            else
            {
                invalid();
            }
        }

        else if (faresOption == "5")
        {
            if (value != "404")
            {
                mulTicket = value;
                cout << "Fare has been changed successfully " << endl;
                getch();
            }
            else
            {
                invalid();
            }
        }
        else if (faresOption == "0")
        {
            break;
        }
        else
        {
            invalid();
        }
    }
}

bool checkFare(string fare)
{
    int count = 0;
    int lengthValue = fare.length();
    for (int i = 0; i < lengthValue; i++)
    {
        int value = fare[i] - '0';
        if (value >= 0 && value < 10)
        {
            count++;
        }
    }
    if (count == lengthValue)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void changePay()
{
    header();
    cout << "Mr. " << driverName << " pay is : Rs." << driverPay << endl;
    cout << "Do you want to change driver's pay?(y/n) : ";
    cin >> choice;
    if (choice == "y")
    {
        enterPay();
    }
    else if (choice == "n")
    {
        operationCancelled();
    }
    else
    {
        invalid();
    }
}
void enterPay()
{
    string pay;
    cout << "";
    getline(cin, ignore);
    cout << "Enter new pay of the driver : ";
    getline(cin, pay);

    bool check = checkFare(pay);
    if (check == true)
    {
        int newPay = stoi(pay);
        if (newPay >= 15000)
        {
            driverPay = pay;
            cout << "Mr. " << driverName << " new pay is : Rs." << driverPay << endl;
            clear();
        }
        else if (newPay < 15000)
        {
            cout << "Pay must be greater than Rs.15000" << endl;
            clear();
        }
    }

    else
    {
        invalid();
    }
}
