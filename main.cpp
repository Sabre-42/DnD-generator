#include <iostream>
#include <cstdlib>
#include <random>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

/* Main issue is that the desired file streaming methodology of keeping the data of the previous run of code
   but allowing for that previous data to be overwritten each time the code is run isn't working. 
   I have narrowed it down to the way that the ofstream method is being done in line 250 */
   
/* I am completely open to edits, comments, and most any changes. So long as I can understand why that change is being made
   Otherwise feel free to tear into this code. Thanks in advance */
class Diceroller
{
    private:
        int result;
        
    public:
        int userInput; 
        
        int die()
        {
            cout << "What Dice Would You Like To Roll? \n"
                << "1. 4-sided " << "2. 6-sided " << "3. 8-sided "
                << "4. 10-sided " << "5. 12-sided " << "6. 20-sided " 
                << "7. 100-sided " << "8. Percentile \n";
            
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
                    uniform_int_distribution<> distr(1, 4); // define the range
                    
                    cout << "How many times do you want to roll? " << endl;
                    cin >> numOfRolls;
                    
                    cout << "Results: ";
                    
                    for(int n = 0; n<numOfRolls; ++n)
                        std::cout << distr(gen) << ' '; // generate numbers
                    
                    cout << "\n\n";
                }
                   break;
                case 2: //d6
                {   
                    uniform_int_distribution<> distr(1, 6); // define the range
                    
                    cout << "How many times do you want to roll? " << endl;
                    cin >> numOfRolls;
                    
                    cout << "Results: ";
                    
                    for(int n = 0; n<numOfRolls; ++n)
                        std::cout << distr(gen) << ' '; // generate numbers
                    
                    cout << "\n\n";
                }
                    break;
                case 3: //d8
                {   
                    uniform_int_distribution<> distr(1, 8); // define the range
                    
                    cout << "How many times do you want to roll? " << endl;
                    cin >> numOfRolls;
                    
                    cout << "Results: ";
                    
                    for(int n = 0; n<numOfRolls; ++n)
                        std::cout << distr(gen) << ' '; // generate numbers
                    
                    cout << "\n\n";
                }
                    break;
                case 4: //d10
                {   
                    uniform_int_distribution<> distr(1, 10); // define the range
                    
                    cout << "How many times do you want to roll? " << endl;
                    cin >> numOfRolls;
                    
                    cout << "Results: ";
                    
                    for(int n = 0; n<numOfRolls; ++n)
                        std::cout << distr(gen) << ' '; // generate numbers
                    
                    cout << "\n\n";
                }
                    break;
                case 5: //d12
                {   
                    uniform_int_distribution<> distr(1, 12); // define the range
                    
                    cout << "How many times do you want to roll? " << endl;
                    cin >> numOfRolls;
                    
                    cout << "Results: ";
                    
                    for(int n = 0; n<numOfRolls; ++n)
                        std::cout << distr(gen) << ' '; // generate numbers
                    
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
                case 8: //Percentile - Shut up I know it's redundant
                {   
                    uniform_int_distribution<> distr(1, 100); // define the range
                    
                    cout << "Results: " << distr(gen) << "% " << ' ' << "\n\n"; // generate numbers
                }
                    break;
            }
            
        }
};

class Statgen:public virtual Diceroller //built inheritance here to for the continued use of the userInput variable
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
        
        int methodChoice() //overall method for menu and data encapsulation
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
                  //running method1 for each main stat then assigning them
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
                    method3();
                    break;
                case 4:
                    method4();
                    break;
                case 5: 
                    method5();
                    break;
            }
            
            return 0;
        }
        
        //Currently the primary testing function
        int method1() //4d6 Drop Lowest
        {
            //doing file streaming here to monitor the vector outputs as each change occurs
            ofstream datafile;
            datafile.open("Stat-data", ios::out /*| ios::app*/);
            //This is what I think is why it's not working. 
            
            /* built pointers here so that the roll variables would be more secure
            Could potentially be unnecessary */
            int * ptr1 = &roll1;
            int * ptr2 = &roll2;
            int * ptr3 = &roll3;
            int * ptr4 = &roll4;
            
            if(datafile.is_open())
            {
                random_device rd; // obtain a random number from hardware
                mt19937 gen(rd()); // seed the generator
                uniform_int_distribution<> distr(1, 6); // define the range
            
                *ptr1 = distr(gen);
                *ptr2 = distr(gen);
                *ptr3 = distr(gen);
                *ptr4 = distr(gen);
            
                totalRoll.push_back(*ptr1);
                totalRoll.push_back(*ptr2);
                totalRoll.push_back(*ptr3);
                totalRoll.push_back(*ptr4);
            
                cout << "\nInitial Vector: ";
                for(int i=0; i < totalRoll.size(); i++)
                    cout << totalRoll.at(i) << ' ';
                cout << "\n";
                
                datafile << "\nInitial Vector: ";
                for(int i=0; i < totalRoll.size(); i++)
                    datafile << totalRoll.at(i) << ' ';
                datafile << "\n";
            
                auto m = min_element(totalRoll.begin(), totalRoll.end());
                totalRoll.erase(m);
            
                cout << "Editted Vector: ";
                for(int i=0; i < totalRoll.size(); i++)
                    cout << totalRoll.at(i) << ' ';
                cout << "\n";
            
                datafile << "Editted Vector: ";
                for(int i=0; i < totalRoll.size(); i++)
                    datafile << totalRoll.at(i) << ' ';
                datafile << "\n";
            
                stat = accumulate(totalRoll.begin(), totalRoll.end(), 
                            decltype(totalRoll)::value_type(0));
            
                cout << "Final Stat: " << stat;
                datafile << "Final Stat: " << stat << endl;
            }
            datafile.close();
            
            ptr1 = nullptr;
            ptr2 = nullptr;
            ptr3 = nullptr;
            ptr4 = nullptr;
            
            delete ptr1;
            delete ptr2;
            delete ptr3;
            delete ptr4;
          /* Always got yelled at by my CS teacher to not leave hanging pointers 
             So I am deleting the pointers */
            
            totalRoll.erase(totalRoll.begin(), totalRoll.end());
            /* deleting vector contents here so that elements contained within don't compound 
               leading to impossible levels of stats */
            
            return stat; //returning stat value to be assigned to each stat
        }
        
        int method2()
        {
            
            random_device rd; // obtain a random number from hardware
            mt19937 gen(rd()); // seed the generator
            uniform_int_distribution<> distr(1, 6); // define the range
            
            roll1 = distr(gen);
            roll2 = distr(gen);
            roll3 = distr(gen);
            roll4 = distr(gen);
            
            if(roll1 == 1)
                roll1 = distr(gen);
            else if(roll2 == 1)
                roll2 = distr(gen);
            else if(roll3 == 1)
                roll3 = distr(gen);
            else if(roll4 == 1)
                roll4 = distr(gen);
                
            
            totalRoll.push_back(roll1);
            totalRoll.push_back(roll2);
            totalRoll.push_back(roll3);
            totalRoll.push_back(roll4);
            
            auto m = min_element(totalRoll.begin(), totalRoll.end());
            totalRoll.erase(m);
            
            stat = accumulate(totalRoll.begin(), totalRoll.end(), 
                            decltype(totalRoll)::value_type(0));
            
            
            return stat;
        }
        
        int method3()
        {
            return 0;
        }
        
        int method4()
        {
            return 0;
        }
        
        int method5()
        {
            return 0;
        }
};

class Usermenu:public Statgen //Starting menu when code is first run. 
{
    public:
    
        int menuChoice;
        
        void menu()
        {
            cout << "Welcome to whatever this program name is!\n\n"
                << "What would you like to do? \n"
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
            };
        }
};

int main() //very simplistic enduser file. Could've had the last class built in here but don't want to deal with it now
{
    
    Usermenu u;
   
    u.menu();
    
    return 0;
}
