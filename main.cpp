#include <iostream>
#include <cstdlib>
#include <random>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
#include <windows.h>
using namespace std;

class Diceroller
{
    private:
        int result;
        
    public:
        int userInput; 
        
        int die()
        {
            cout << "What Dice Would You Like To Roll? \n"
                << "1. 4-sided " << " 2. 6-sided " << " 3. 8-sided "
                << " 4. 10-sided " << " 5. 12-sided " << " 6. 20-sided " 
                << " 7. 100-sided " << " 8. Percentile \n";
            
            cout << "Input your choice in the form of a number: ";
            
            cin >> userInput;
            
            cout << "\n";
            return userInput;
        }
        
        void roller()
        {
            int numOfRolls; //Number of Rolls user requests
            random_device rd; // obtain a random number from hardware
            mt19937 gen(rd()); // seed the generator
                    
            switch(userInput)
            {
                case 1: //d4
                {   
                    uniform_int_distribution<> distr(1, 4); 
                    
                    cout << "How many times do you want to roll? " << endl;
                    cin >> numOfRolls;
                    
                    cout << "Results: ";
                    
                    for(int n = 0; n<numOfRolls; ++n)
                        std::cout << distr(gen) << ' '; 
                    
                    cout << "\n\n";
                }
                   break;
                case 2: //d6
                {   
                    uniform_int_distribution<> distr(1, 6); 
                    
                    cout << "How many times do you want to roll? " << endl;
                    cin >> numOfRolls;
                    
                    cout << "Results: ";
                    
                    for(int n = 0; n<numOfRolls; ++n)
                        std::cout << distr(gen) << ' '; 
                    
                    cout << "\n\n";
                }
                    break;
                case 3: //d8
                {   
                    uniform_int_distribution<> distr(1, 8); 
                    
                    cout << "How many times do you want to roll? " << endl;
                    cin >> numOfRolls;
                    
                    cout << "Results: ";
                    
                    for(int n = 0; n<numOfRolls; ++n)
                        std::cout << distr(gen) << ' '; 
                    
                    cout << "\n\n";
                }
                    break;
                case 4: //d10
                {   
                    uniform_int_distribution<> distr(1, 10); 
                    
                    cout << "How many times do you want to roll? " << endl;
                    cin >> numOfRolls;
                    
                    cout << "Results: ";
                    
                    for(int n = 0; n<numOfRolls; ++n)
                        std::cout << distr(gen) << ' '; 
                    
                    cout << "\n\n";
                }
                    break;
                case 5: //d12
                {   
                    uniform_int_distribution<> distr(1, 12); 
                    
                    cout << "How many times do you want to roll? " << endl;
                    cin >> numOfRolls;
                    
                    cout << "Results: ";
                    
                    for(int n = 0; n<numOfRolls; ++n)
                        std::cout << distr(gen) << ' '; 
                    
                    cout << "\n\n";
                }
                    break;
                case 6: //d20
                {   
                    uniform_int_distribution<> distr(1, 20); // define the range
                    
                    cout << "How many times do you want to roll? " << endl;
                    cin >> numOfRolls;
                    
                    cout << "Results: ";
                    
                    for(int n = 0; n<numOfRolls; ++n)
                        std::cout << distr(gen) << ' '; // generate numbers
                    
                    cout << "\n\n";
                }
                    break;
                case 7: //d100
                {   
                    uniform_int_distribution<> distr(1, 100); // define the range
                    
                    cout << "How many times do you want to roll? " << endl;
                    cin >> numOfRolls;
                    
                    cout << "Results: ";
                    
                    for(int n = 0; n<numOfRolls; ++n)
                        std::cout << distr(gen) << ' '; // generate numbers
                    
                    cout << "\n\n";
                }
                    break;
                case 8: //Percentile
                {   
                    uniform_int_distribution<> distr(1, 100); // define the range
                    
                    cout << "Results: " << distr(gen) << "% " << ' ' << "\n\n"; // generate numbers
                }
                    break;
            }
            
        }
};

class Statgen:public virtual Diceroller 
{
    public:
        
        /*funtions for determining method of rolling stats
            Method 1 - 4d6 drop lowest 
            Method 2 - 4d6 drop lowest - reroll 1's
            Method 3 - 3d6 - No mulligan
            Method 4 - 3d6 - reroll 1's
            Method 5 - 2d6+6 
        */
        
        int str, dex, con, inte, wis, chr;
        int stat;
        int roll1, roll2, roll3, roll4;
        vector<int>totalRoll;
        
        int methodChoice() 
        { 
           
            
            cout << "\nChoose method for rolling stats: \n"
                << "Method 1 - 4d6 drop lowest \n" 
                << "Method 2 - 4d6 drop lowest - reroll 1's \n"
                << "Method 3 - 3d6 - No mulligan \n"
                << "Method 4 - 3d6 - reroll 1's \n"
                << "Method 5 - 2d6+6 \n";
                
            cout << "Input your choice as a single number: ";
            
            cin >> userInput;
            
            switch(userInput)
            {
                case 1:
                {
                    str = method1();
                    dex = method1();
                    con = method1();
                    inte = method1();
                    wis = method1();
                    chr = method1();
                         
                    cout << "\n\nMethod: 4d6 drop Lowest" << endl << endl
                         << "Str: " << str  << "\n" 
                         << "Dex: " << dex  << "\n"
                         << "Con: " << con  << "\n"
                         << "Int: " << inte << "\n"
                         << "Wis: " << wis  << "\n"
                         << "Chr: " << chr  << "\n"; 
                }
                    break;
                case 2: 
                {
                    str  = method2();
                    dex  = method2();
                    con  = method2();
                    inte = method2();
                    wis  = method2();
                    chr  = method2();
                         
                    cout << "\n\nMethod: 4d6 drop Lowest - Reroll 1's" << endl << endl
                         << "Str: " << str  << "\n" 
                         << "Dex: " << dex  << "\n"
                         << "Con: " << con  << "\n"
                         << "Int: " << inte << "\n"
                         << "Wis: " << wis  << "\n"
                         << "Chr: " << chr  << "\n";
                }
                    break;
                case 3:
                {
                    str  = method3();
                    dex  = method3();
                    con  = method3();
                    inte = method3();
                    wis  = method3();
                    chr  = method3();
                         
                    cout << "\n\nMethod: 3d6 - No Mulligan" << endl << endl
                         << "Str: " << str  << "\n" 
                         << "Dex: " << dex  << "\n"
                         << "Con: " << con  << "\n"
                         << "Int: " << inte << "\n"
                         << "Wis: " << wis  << "\n"
                         << "Chr: " << chr  << "\n";
                }
                    break;
                case 4:
                {
                    str  = method4();
                    dex  = method4();
                    con  = method4();
                    inte = method4();
                    wis  = method4();
                    chr  = method4();
                         
                    cout << "\n\nMethod: 3d6 - Reroll 1's" << endl << endl
                         << "Str: " << str  << "\n" 
                         << "Dex: " << dex  << "\n"
                         << "Con: " << con  << "\n"
                         << "Int: " << inte << "\n"
                         << "Wis: " << wis  << "\n"
                         << "Chr: " << chr  << "\n";
                }
                    break;
                case 5: 
                {
                    str  = method5();
                    dex  = method5();
                    con  = method5();
                    inte = method5();
                    wis  = method5();
                    chr  = method5();
                         
                    cout << "\n\nMethod: 2d6 + 6" << endl << endl
                         << "Str: " << str  << "\n" 
                         << "Dex: " << dex  << "\n"
                         << "Con: " << con  << "\n"
                         << "Int: " << inte << "\n"
                         << "Wis: " << wis  << "\n"
                         << "Chr: " << chr  << "\n";
                }
                    break;
            }
            
            return 0;
        }
        
        
        int method1() //4d6 - Drop Lowest
        {
            char filename[MAX_PATH];

            GetModuleFileNameA(nullptr, filename, sizeof(filename));

            string filepath;

            filepath = filename;
            filepath = filepath.erase(filepath.find_last_of('\\'));

        
            ofstream datafile;
            datafile.open(filepath + "/output.txt", ios::out /*| ios::app*/);
    
            for(int i = 0; i < 3; i++)
            {
               int *ptr1 = &roll1;
               int *ptr2 = &roll2;
               int *ptr3 = &roll3;
               int *ptr4 = &roll4;
        
               if (datafile.is_open()) 
               {
                  random_device rd;
                  mt19937 gen(rd());
                  uniform_int_distribution<> distr(1, 6);
            
                  *ptr1 = distr(gen);
                  *ptr2 = distr(gen);
                  *ptr3 = distr(gen);
                  *ptr4 = distr(gen);
            
                  totalRoll.push_back(*ptr1);
                  totalRoll.push_back(*ptr2);
                  totalRoll.push_back(*ptr3);
                  totalRoll.push_back(*ptr4);
            
                  cout << "\nInitial Roll: ";
                  for (int i = 0; i < totalRoll.size(); i++)
                     cout << totalRoll.at(i) << ' ';
                  cout << "\n";

                  datafile << "\nInitial Vector: ";
                  for (int i = 0; i < totalRoll.size(); i++)
                     datafile << totalRoll.at(i) << ' ';
                  datafile << "\n";
          
                  auto m = min_element(totalRoll.begin(), totalRoll.end());
                  totalRoll.erase(m);
            
                  cout << "Drop Lowest Roll: ";
                  for (int i = 0; i < totalRoll.size(); i++)
                     cout << totalRoll.at(i) << ' ';
                  cout << "\n";
            
                  datafile << "Editted Vector: ";
                  for (int i = 0; i < totalRoll.size(); i++)
                     datafile << totalRoll.at(i) << ' ';
                  datafile << "\n";
            
                  stat = accumulate(totalRoll.begin(), totalRoll.end(),
                        decltype(totalRoll)::value_type(0));
            
                  cout << "Final Stat: " << stat;
                  datafile << "Final Stat: " << stat << endl;
               }
        
               else
               {
                  cout << "Failed to open Data File\n";
                  cout << "Exiting Program";
                  exit(1);
               }
        
               ptr1 = nullptr;
               ptr2 = nullptr;
               ptr3 = nullptr;
               ptr4 = nullptr; 
        
               delete ptr1;
               delete ptr2;
               delete ptr3;
               delete ptr4;
        
               totalRoll.erase(totalRoll.begin(), totalRoll.end());
            }
    
            datafile.close();

            return stat;
        }  
        
        int method2() //4d6 - Drop lowest - Reroll 1's
        {
            
            random_device rd; 
            mt19937 gen(rd()); 
            uniform_int_distribution<> distr(1, 6); 
            
            roll1 = distr(gen);
            roll2 = distr(gen);
            roll3 = distr(gen);
            roll4 = distr(gen);
           
            totalRoll.push_back(roll1);
            totalRoll.push_back(roll2);
            totalRoll.push_back(roll3);
            totalRoll.push_back(roll4);
            
            cout << "\nInitial Roll: ";
                for (int i = 0; i < totalRoll.size(); i++)
                    cout << totalRoll.at(i) << ' ';
                cout << "\n";
           
            if (roll1 == 1)
            { 
                replace(totalRoll.begin(), totalRoll.end(), 1, distr(gen)); 
            }
           
            if (roll2 == 1)
            { 
                replace(totalRoll.begin(), totalRoll.end(), 1, distr(gen));
            }
        
            if (roll3 == 1)
            { 
                replace(totalRoll.begin(), totalRoll.end(), 1, distr(gen));
            }
        
            if (roll4 == 1)
            { 
                replace(totalRoll.begin(), totalRoll.end(), 1, distr(gen));
            }
            
            cout << "Reroll 1's: ";
                for (int i = 0; i < totalRoll.size(); i++)
                    cout << totalRoll.at(i) << ' ';
                cout << "\n";
            
            auto m = min_element(totalRoll.begin(), totalRoll.end());
            totalRoll.erase(m);
            
            cout << "Drop Lowest Roll: ";
                for (int i = 0; i < totalRoll.size(); i++)
                    cout << totalRoll.at(i) << ' ';
                cout << "\n";
         
            stat = accumulate(totalRoll.begin(), totalRoll.end(),
                    decltype(totalRoll)::value_type(0));
            
            cout << "Final Stat: " << stat;
            
            totalRoll.erase(totalRoll.begin(), totalRoll.end());
            
            return stat;
        }
        
        int method3() //3d6 - No Mulligan
        {
           random_device rd; 
            mt19937 gen(rd()); 
            uniform_int_distribution<> distr(1, 6); 
            
            roll1 = distr(gen);
            roll2 = distr(gen);
            roll3 = distr(gen);
           
            totalRoll.push_back(roll1);
            totalRoll.push_back(roll2);
            totalRoll.push_back(roll3);
            
            cout << "\nInitial Roll: ";
                for (int i = 0; i < totalRoll.size(); i++)
                    cout << totalRoll.at(i) << ' ';
                cout << "\n";
            
            stat = accumulate(totalRoll.begin(), totalRoll.end(),
                    decltype(totalRoll)::value_type(0));
            
            cout << "Final Stat: " << stat;
            
            totalRoll.erase(totalRoll.begin(), totalRoll.end());
            
            return stat;
        }
        
        int method4()
        {
            random_device rd; 
            mt19937 gen(rd()); 
            uniform_int_distribution<> distr(1, 6); 
            
            roll1 = distr(gen);
            roll2 = distr(gen);
            roll3 = distr(gen);
           
            totalRoll.push_back(roll1);
            totalRoll.push_back(roll2);
            totalRoll.push_back(roll3);
            
            cout << "\nInitial Roll: ";
                for (int i = 0; i < totalRoll.size(); i++)
                    cout << totalRoll.at(i) << ' ';
                cout << "\n";
           
            if (roll1 == 1)
            { 
                replace(totalRoll.begin(), totalRoll.end(), 1, distr(gen)); 
            }
           
            if (roll2 == 1)
            { 
                replace(totalRoll.begin(), totalRoll.end(), 1, distr(gen));
            }
        
            if (roll3 == 1)
            { 
                replace(totalRoll.begin(), totalRoll.end(), 1, distr(gen));
            }
            
            cout << "Reroll 1's: ";
                for (int i = 0; i < totalRoll.size(); i++)
                    cout << totalRoll.at(i) << ' ';
                cout << "\n";
            
            stat = accumulate(totalRoll.begin(), totalRoll.end(),
                    decltype(totalRoll)::value_type(0));
            
            cout << "Final Stat: " << stat;
            
            totalRoll.erase(totalRoll.begin(), totalRoll.end());
            
            return stat;
        }
        
        int method5()
        {
            random_device rd; 
            mt19937 gen(rd()); 
            uniform_int_distribution<> distr(1, 6); 
            
            roll1 = distr(gen);
            roll2 = distr(gen);
            roll3 = 6;
           
            totalRoll.push_back(roll1);
            totalRoll.push_back(roll2);
            
            cout << "\nInitial Roll: ";
                for (int i = 0; i < totalRoll.size(); i++)
                    cout << totalRoll.at(i) << ' ';
                cout << "\n";
                
            totalRoll.push_back(roll3);    
                
            cout << "Adding 6 to the rolls: ";
                for (int i = 0; i < totalRoll.size(); i++)
                    cout << totalRoll.at(i) << ' ';
                cout << "\n";
            
            stat = accumulate(totalRoll.begin(), totalRoll.end(),
                    decltype(totalRoll)::value_type(0));
            
            cout << "Final Stat: " << stat;
            
            totalRoll.erase(totalRoll.begin(), totalRoll.end());
            
            return stat;
        }
};

class Usermenu:public Statgen  
{
    public:
    
        int menuChoice;
        char recursiveChoice;
        
        void menu()
        {
                cout << "What would you like to do? \n"
                     << "1. Character Stat Generator \n" 
                     << "2. Dice Roller\n";
                
            cout << "\nChoice: ";
            cin >> menuChoice;
            
            switch(menuChoice)
            {
                case 1:
                    Statgen::methodChoice();
                    break;
                case 2:
                {
                    Diceroller::die();
                    Diceroller::roller();
                }
                    break;
                default:
                {
                    cout << "Improper Input! \n\n" << "Try Again" << endl;
                    menu();
                }
                break;
            };
            
            cout << "\nWant to run program again? (Y/N): "; 
            cin >> recursiveChoice;
            cout << endl;
            
            if(recursiveChoice == 'y' || recursiveChoice == 'Y')
            {
                menu();
            }
            else if (recursiveChoice == 'n' || recursiveChoice == 'Y')
            {
                cout << "\nEnjoy your day!" << endl;
                exit(1);
            }
        }
};

int main() 
{
    
    Usermenu u;
    
    cout << "Welcome to whatever this programs name is!\n\n";
    
    u.menu();
    
    return 0;
}
