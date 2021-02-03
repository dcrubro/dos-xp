/*
    -------------------------------------------------------
    XP-DOS Version indev-4
    Written in C++ by Jonas Korene Novak
    Copyright JMCOG 2020
    Contact at: info@jonascraft.com
    -------------------------------------------------------
*/

#include <iostream>
#include <windows.h>
#include <unistd.h>

using namespace std;

bool isRunning = true;
string userCommand;
string version = "indev-4";



void CodeEdit()
{
    isRunning = false;
    bool isEditor = true;
    std::cout << "Welcome to XP-DOS Code!" << endl;
    std::cout << "Type 'help' for help." << endl;
    string commands[6];
    string debugCommands[8];
    string emptyLine;
    string separator = " ";
    string newLine = "\n";
    string file[100];
    string userDebugCommand;
    int currentLines = 0;
    commands[0] = "print";
    commands[1] = "end";
    commands[2] = "goxpdos";
    commands[3] = "cls";
    commands[4] = "pause";
    commands[5] = "input";
    debugCommands[0] = "run";
    debugCommands[1] = "stop";
    debugCommands[2] = "newfile";
    debugCommands[3] = "writefile";
    debugCommands[4] = "list";
    debugCommands[5] = "chkfile";
    debugCommands[6] = "goxpdos";
    debugCommands[7] = "help";
    emptyLine = "";

    for (int i = 0; i < 101; i++)
    {
        file[i] = "";
    }

    while (isEditor)
    {
        std::cin >> userDebugCommand;
        if (userDebugCommand == debugCommands[0])
        {
            string code[100];
            int currentExecutedLine = 0;
            for (int i = 0; i < 101; i++)
            {
                code[i] = file[i];
            }

            for (int i = 0; i < 101; i++)
            {
                if (code[i] == commands[0])
                {
                    string userInput;
                    std::cout << "Request user input..." << endl;
                    std::cin >> userInput;
                    std::cout << userInput << endl;
                }
                else if (code[i] == commands[1])
                {
                    break;
                }
                else if (code[i] == commands[2])
                {
                    std::cout << "Booting to XP-DOS..." << endl;
                    isRunning = true;
                    isEditor = false;
                    break;
                }
                else if (code[i] == commands[3])
                {
                    system("cls");
                }
                else if (code[i] == commands[4])
                {
                    system("PAUSE");
                }
                else if (code[i] == commands[5])
                {
                    string usrInp;
                    std::cin >> usrInp;
                    std::cout << "User Input: " << usrInp << endl;  // Sample result, Change to fit you style
                }
                else if (code[i] == emptyLine || code[i] == separator)
                {
                    std::cout << " " << endl;
                }
                else
                {
                    std::cout << "?Syntax error in: " << i << endl;
                    break;
                }
                currentExecutedLine += 1;
            }

        }
        else if (userDebugCommand == debugCommands[1])
        {
            //TODO: Stop program
        }
        else if (userDebugCommand == debugCommands[2])
        {
            for (int i = 0; i < 101; i++)
            {
                file[i] = "";
            }
        }
        else if (userDebugCommand == debugCommands[3])
        {
            string tempCode;
            std::cin >> tempCode;
            if (currentLines == 0)
            {
                if (file[0] == "")
                {
                    file[0] = tempCode;
                    currentLines += 1;
                }
            }
            else
            {
                currentLines += 1;
                file[currentLines] = tempCode;
            }

        }
        else if (userDebugCommand == debugCommands[4])
        {
            for (int i = 0; i < 101; i++)
            {
                if (file[i] == "" && i != 1)
                {
                    break;
                }
                else
                {
                    std::cout << file[i] << endl;
                }
            }
        }
        else if (userDebugCommand == debugCommands[5])
        {
            for (int i = 0; i < 101; i++)
            {
                if (file[i] == commands[0])
                {
                    std::cout << "Line " << i << " OK!" << endl;
                }
                else if (file[i] == commands[1])
                {
                    std::cout << "Line " << i << " OK!" << endl;
                }
                else if (file[i] == commands[2])
                {
                    std::cout << "Line " << i << " OK!" << endl;
                }
                else if (file[i] == commands[3])
                {
                    std::cout << "Line " << i << " OK!" << endl;
                }
                else if (file[i] == commands[4])
                {
                    std::cout << "Line " << i << " OK!" << endl;
                }
                else if (file[i] == emptyLine || file[i] == separator)
                {
                    std::cout << "Line " << i << " OK!" << endl;
                }
                else
                {
                    std::cout << "?Syntax error in line " << i << "!" << endl;
                }
            }
        }
        else if (userDebugCommand == debugCommands[6])
        {
            std::cout << "Booting to XP-DOS..." << endl;
            isRunning = true;
            isEditor = false;
            system("cls");
            break;
        }
        else if (userDebugCommand == debugCommands[7])
        {
            std::cout << "XPDPS Help:" << endl;
            std::cout << "Command reference:" << endl;
            std::cout << "cls - clears the screen" << endl;
            std::cout << "end - breaks the program" << endl;
            std::cout << "goxpdos - Boot's XP-DOS and exits XPDPS mode" << endl;
            std::cout << "pause - pauses the system" << endl;
            std::cout << "print - get the user to input a string and print's it back" << endl;
            std::cout << "input - get user input over string variable 'usrInp'" << endl;
            std::cout << "Debug Command reference:" << endl;
            std::cout << "chkfile - check the script for syxtax errors" << endl;
            std::cout << "help - shows the help page (<CURRENT>)" << endl;
            std::cout << "list - lists your program" << endl;
            //std::cout << "stop" << endl;
            std::cout << "newfile - makes a new script" << endl;
            std::cout << "writefile - enables you to write one line of script (one line per command)" << endl;
            std::cout << "goxpdos - Boot's XP-DOS and exits XPDPS mode" << endl;
            std::cout << "run - runs your program" << endl;

        }
        else
        {
            std::cout << "Unknown debug command." << endl;
        }

        system("PAUSE");
    }
}

void Print()
{
    string userInput;
    std::cout << "Request user input..." << endl;
    std::cin >> userInput;
    std::cout << userInput << endl;
}

void Quit()
{
    std::cout << "Quitting XP-DOS..." << endl;
    isRunning = false; // Sets isRunning to false which breaks the loop
}

void ClearScreen()
{
    system("cls");
}

void PauseSystem()
{
    system("PAUSE");
}

void DisplayAbout()
{
    std::cout << "About:" << endl;
    std::cout << "XP-DOS: version " << version << endl;
    std::cout << "Home user operation system for PC's" << endl;
    std::cout << "Written in C++ by Jonas Korene Novak" << endl;
    std::cout << "Copyright 2020 by JMCOG" << endl;
    std::cout << "Type 'help' for user help" << endl;
}

void DisplayHelp()
{
    std::cout << "User help" << endl;
    std::cout << "IMPORTANT!!! THIS VERSION IS NOT FINAL! REPORT BUGS AT info@jonascraft.com" << endl;
    std::cout << "Command reference:" << endl;
    std::cout << "about: Displays about page" << endl;
    std::cout << "cls: Clears the screen" << endl;
    std::cout << "code: Program in XPDPS" << endl;
    std::cout << "help: Display help page (<CURRENT>)" << endl;
    std::cout << "pause: Pauses the system" << endl;
    std::cout << "calc: Runs Calculator" << endl;
}

void Calculator()
{
    std::cout << "Calculator started!" << endl;
    char op;
    float num1, num2;
    bool isCalculator = true;
    string endAskAgain;

    while (isCalculator)
    {
        std::cout << "Enter operation here (+, -, *, or /): ";
        std::cin >> op;
        std::cout << endl;

        std::cout << "Enter two operands: ";
        std::cin >> num1 >> num2;
        std::cout << endl;

        switch (op)
        {
            case '+':
                std::cout << num1 + num2 << endl;
                break;
            case '-':
                std::cout << num1 - num2 << endl;
                break;
            case '*':
                std::cout << num1 * num2 << endl;
                break;
            case '/':
                std::cout << num1 / num2 << endl;
                break;

            default:
                std::cout << "Error during calculation - Type of error: Invalid operation" << endl;
                break;
        }

        std::cout << "Do Another calculation? (Y or N) ";
        std::cin >> endAskAgain;

        if (endAskAgain == "Y" || endAskAgain == "y")
        {
            isCalculator = true;
        }
        else if (endAskAgain == "N" || endAskAgain == "n")
        {
            std::cout << "Quitting to XP-DOS..." << endl;
            ClearScreen();
            isCalculator = false;
            break;
        }
        else
        {
            std::cout << "Invalid answer! Quitting to XP-DOS..." << endl;
            ClearScreen();
            isCalculator = false;
            break;
        }

    }


}

int main()
{
    std::cout << "XP-DOS version " << version << endl;
    std::cout << "Type 'help' for user help" << endl;

    while (isRunning)
    {
        std::cout << "Enter command:" << endl;
        std::cin >> userCommand;
        if (userCommand == "print")
        {
            Print();
        }
        else if (userCommand == "quit")
        {
            Quit();
        }
        else if (userCommand == "cls")
        {
            ClearScreen();
        }
        else if (userCommand == "pause")
        {
            PauseSystem();
        }
        else if (userCommand == "about")
        {
            DisplayAbout();
        }
        else if (userCommand == "help")
        {
            DisplayHelp();
        }
        else if (userCommand == "code")
        {
            ClearScreen();
            std::cout << "Quitting XP-DOS and starting code editor..." << endl;
            CodeEdit();
        }
        else if (userCommand == "calc")
        {
            std::cout << "Quitting to Calculator..." << endl;
            ClearScreen();
            Calculator();
        }
        else
        {
            std::cout << "Unknown command/Illegal action" << endl;
        }

    }

    return 0;
}
