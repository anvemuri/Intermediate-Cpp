#include<iostream>
#include<fstream>

using namespace std;

int displayMenu();

int main()
{

    const int ROWS = 4, COLS = 5;
    string headerJeff[COLS] = {"JEFF", "Monday", "Tuesday", "Wednesday", "Thursday"};
    string headerAnna[COLS] = {"ANNA", "Monday", "Tuesday", "Wednesday", "Thursday"};
    int tableJeff[ROWS][COLS] = {{11, 1, 1, 0, 0}, {12, 0, 1, 1, 1}, {01, 0, 1, 1, 0}, {02, 1, 1, 1, 0}};
    int tableAnna[ROWS][COLS] = {{11, 1, 1, 0, 1}, {12, 0, 1, 0, 1}, {01, 1, 1, 0, 0}, {02, 1, 0, 1, 1}};

    int choice;
    int numChoice, dayChoice, timeChoice, markChoice, availableJ = 0, availableA = 0, availableGroup = 0;

    ifstream inputFile;
    ofstream outputFile;

    inputFile.open("C:\\Users\\anjali.vemuri\\Desktop\\AnjaliVemuri_Lab1\\Schedule.txt");
    outputFile.open("C:\\Users\\anjali.vemuri\\Desktop\\AnjaliVemuri_Lab1\\Schedule.txt");

    choice = displayMenu();

    while(choice > 0 && choice < 7)
    {
        switch(choice)
        {
            case 1: cout << "1. Mark a schedule\n2. Remove a schedule\n";
                    cout << "What do you want to do? ";
                    cin >> markChoice;
                    cout << endl;
                    if(markChoice == 1)
                    {
                        cout << "1. Jeff\n2. Anna" << endl;
                        cout << "Please choose an instructor(enter the number): ";
                        cin >> numChoice;
                        cout << endl;

                        if(numChoice == 1) // Set a schedule for Jeff
                        {
                            cout << "1. Monday\n2. Tuesday\n3. Wednesday\n4. Thursday\n";
                            cout << "Choose a day: ";
                            cin >> dayChoice;
                            cout << endl;

                            cout << "1. 11-12 PM\n2. 12-01 PM\n3. 01-02 PM\n4. 02-03 PM" << endl;
                            cout << "Choose a time: ";
                            cin >> timeChoice;
                            cout << endl;

                            if(tableJeff[timeChoice - 1][dayChoice] == 1)
                            {
                                cout << "The day and time already have a schedule!" << endl << endl;
                            }
                            else
                            {
                                tableJeff[timeChoice - 1][dayChoice] = 1;
                                cout << "The schedule is now set!" << endl << endl;
                            }
                        }
                        else // Set a schedule for Anna
                        {
                            cout << "1. Monday\n2. Tuesday\n3. Wednesday\n4. Thursday\n";
                            cout << "Choose a day: ";
                            cin >> dayChoice;
                            cout << endl;

                            cout << "1. 11-12 PM\n2. 12-01 PM\n3. 01-02 PM\n4. 02-03 PM" << endl;
                            cout << "Choose a time: ";
                            cin >> timeChoice;
                            cout << endl;

                            if(tableAnna[timeChoice - 1][dayChoice] == 1)
                            {
                                cout << "The day and time already have a schedule!" << endl << endl;
                            }
                            else
                            {
                                tableAnna[timeChoice - 1][dayChoice] = 1;
                                cout << "The schedule is now set!" << endl << endl;
                            }
                        }
                    }
                    else // REMOVE A SCHEDULE
                    {
                        cout << "1. Jeff\n2. Anna" << endl;
                        cout << "Please choose an instructor(enter the number): ";
                        cin >> numChoice;
                        cout << endl;

                        if(numChoice == 1) // Set a schedule for Jeff
                        {
                            cout << "1. Monday\n2. Tuesday\n3. Wednesday\n4. Thursday\n";
                            cout << "Choose a day: ";
                            cin >> dayChoice;
                            cout << endl;

                            cout << "1. 11-12 PM\n2. 12-01 PM\n3. 01-02 PM\n4. 02-03 PM" << endl;
                            cout << "Choose a time: ";
                            cin >> timeChoice;
                            cout << endl;

                            if(tableJeff[timeChoice - 1][dayChoice] == 0)
                            {
                                cout << "The day and time is already free!" << endl << endl;
                            }
                            else
                            {
                                tableJeff[timeChoice - 1][dayChoice] = 0;
                                cout << "The schedule is now free!" << endl << endl;
                            }
                        }
                        else // Set a schedule for Anna
                        {
                            cout << "1. Monday\n2. Tuesday\n3. Wednesday\n4. Thursday\n";
                            cout << "Choose a day: ";
                            cin >> dayChoice;
                            cout << endl;

                            cout << "1. 11-12 PM\n2. 12-01 PM\n3. 01-02 PM\n4. 02-03 PM" << endl;
                            cout << "Choose a time: ";
                            cin >> timeChoice;
                            cout << endl;

                            if(tableAnna[timeChoice - 1][dayChoice] == 0)
                            {
                                cout << "The day and time is already free!" << endl << endl;
                            }
                            else
                            {
                                tableAnna[timeChoice - 1][dayChoice] = 0;
                                cout << "The schedule is now free!" << endl << endl;
                            }
                        }
                    }

                    break;

            // DISPLAY THE SCHEDULE
            case 2: cout << "-------------------------------------------------------\n";
                    cout << "\t      SWIMMING INSTRUCTOR SCHEDULE\n";
                    cout << "-------------------------------------------------------\n\n";

                    for(int i = 0; i < COLS; i++) //DISPLAY THE SCHEDULE OF JEFF
                    {
                        cout << headerJeff[i] << "     ";
                    }
                    cout << endl;

                    for(int d = 0; d < ROWS; d++)
                    {
                        switch(tableJeff[d][0])
                        {
                            case 11: cout << "11-12       ";
                                    break;

                            case 12: cout << "12-01       ";
                                    break;

                            case 01: cout << "01-02       ";
                                    break;

                            default: cout << "02-03       ";
                        }

                        for(int a = 1; a < COLS; a++)
                        {
                            switch(tableJeff[d][a])
                            {
                                case 1: cout << "X           ";
                                        break;
                                default: cout << "-           ";
                            }
                        }

                        cout << endl;
                    }

                    cout << "-------------------------------------------------------\n";

                    //DISPLAY THE SCHEDULE OF ANNA
                    for(int i = 0; i < COLS; i++)
                    {
                        cout << headerAnna[i] << "     ";
                    }
                    cout << endl;

                    for(int d = 0; d < ROWS; d++)
                    {
                        switch(tableAnna[d][0])
                        {
                            case 11: cout << "11-12       ";
                                    break;

                            case 12: cout << "12-01       ";
                                    break;

                            case 01: cout << "01-02       ";
                                    break;

                            default: cout << "02-03       ";
                        }

                        for(int a = 1; a < COLS; a++)
                        {
                            switch(tableAnna[d][a])
                            {
                                case 1: cout << "X           ";
                                        break;
                                default: cout << "-           ";
                            }
                        }

                        cout << endl;
                    }
                    cout << endl << endl;
                    break;

            case 3: cout << "1. Jeff\n2. Anna\n" << endl;
                    cout << "Please choose an instructor(enter the number): ";
                    cin >> numChoice;
                    cout << endl;

                    if(numChoice == 1) // DISPLAY AVAILABLE TIME SLOTS FOR JEFF
                    {
                        for(int i = 0; i < ROWS; i++)
                        {
                            for(int a = 1; a <= COLS; a++)
                            {
                                if(tableJeff[i][a] == 0)
                                {
                                    switch(tableJeff[i][a])
                                    {
                                        case 0: availableJ++;
                                    }
                                }
                            }
                        }

                        cout << "There are " << availableJ << " available slots of individual lessons for Jeff" << endl << endl;
                        availableJ = 0; // Make availableJ 0 again for next use.
                    }
                    else // DISPLAY AVAILABLE TIME SLOTS FOR ANNA
                    {
                        for(int i = 0; i < ROWS; i++)
                        {
                            for(int a = 1; a <= COLS; a++)
                            {
                                switch(tableAnna[i][a])
                                {
                                    case 0: availableA++;
                                }
                            }
                        }
                        cout << "There are " << availableA << " available slots of individual lessons for Anna" << endl << endl;
                        availableA = 0; // Make availableA 0 again for next use.
                    }
                    break;

            case 4: for(int i = 0; i < ROWS; i++) // DISPLAY THE AVAILABLE TIME SLOTS FOR GROUP LESSONS
                    {
                        for(int a = 1; a < COLS; a++)
                        {
                            if(tableJeff[i][a] == 0 && tableAnna[i][a] == 0)
                            {
                                availableGroup++;
                            }
                        }
                    }

                    cout << "There are " << availableGroup << " available group lessons." << endl << endl;
                    break;

            case 5: break;

            default: for(int i = 0; i < ROWS; i++)
                     {
                        for(int a = 1; a < COLS; a++)
                        {
                            outputFile << tableJeff[i][a] << ", ";
                        }
                        outputFile << endl;
                     }

                     outputFile << endl << endl;

                     for(int i = 0; i < ROWS; i++)
                     {
                        for(int a = 1; a < COLS; a++)
                        {
                            outputFile << tableAnna[i][a] << ", ";
                        }
                        outputFile << endl;
                     }

                      cout << "Schedule saved!" << endl << endl;
        }
        choice = displayMenu();
    }

    inputFile.close(); // CLOSE THE FILE
    outputFile.close(); // CLOSE THE FILE

    return 0;
}

//********************************************************************************************************
//FUNCTION DEFINITION: This function will display the menu and will prompt the user to get his/her choice
//                     on the menu.
//********************************************************************************************************

int displayMenu()
{
    int choice;

    cout << "--------------------------MENU---------------------------\n\n";

    cout << "1. Set schedule" << endl;
    cout << "2. Display schedule" << endl;
    cout << "3. Display time slots available for individual lessons" << endl;
    cout << "4. Display time slots available for group lessons" << endl;
    cout << "5. Load a schedule" << endl;
    cout << "6. Save schedule" << endl << endl;

    cout << "Enter the number of your choice(Enter negative number to stop): ";
    cin >> choice;
    cout << endl;

    return choice;
}
