// luhn algorithm to check 16 digit credit card numbers

#include <iostream>
#include <cstring>

void checkLuhn(char card_num[16])
{
     int card_number[16];
    //store values in int array so can perform opp
        for (int i = 0; i != 16; i++)
        {
        card_number[i] = card_num[i] - 48 ;

        std::cout<<card_number[i]<<", ";
        } 

    int luhn_sum = 0; 
    
    

    
    std::cout<<std::endl;

    //loop to check second num from right
    //decrement by 2 to skip digits, start at 14 to leave last unchanged
    for (int i = 14; i >= 0; i = i - 2)
    {
        
            card_number[i] = card_number[i] * 2; //multiply every second digit by 2

    }

    std::cout<<std::endl;
    for (int i = 0; i< 16; i++)
            std::cout<<card_number[i]<<", "<<std::endl;

    for (int i = 0; i < 16; i++)
    {
        if (card_number[i] > 9)
        {
            card_number[i] = card_number[i] - 9; //"add" doubled digits if >9
        }
        
        luhn_sum = card_number[i] + luhn_sum; //running Luhn value
    } 

    //OUTPUT

    //check if luhn_sum multiple of 10
    if((luhn_sum % 10) == 0)
        std::cout<<"This number is valid!";
    else
        std::cout<<"Sorry! This number is invalid, please check the entered number.";
    return;
}
int main()
{
    //INPUT
    char start = 'n'; // char for user to start/loop Luhn. 
    bool valid = false; //counter for illegal input while

    std::cout<<"Welcome to Luhn Algorith! Would you like to check a card number?";
    std::cout<<std::endl<<"[y] to start               [n] to exit"<<std::endl;
    std::cin>>start;

    //only start/loop if user confirm
    while(start == 'y')
    {

    //int card_number1[16]; //pass to int for opp
    char card_number[20]; //user_given input. init to 20 incase misstype
        std::cout<<"Please enter your credit card number: ";
        std::cin>>card_number;

        
        //Ask user for correct number if length not 16
        //TODO: Add invalid char checking, correct internal space checking
        while (strlen(card_number) != 16)
        {
            
            std::cout<<"Sorry, invalid number. Please try again: ";
            std::cin>>card_number;
        }
        std::cout<<card_number;

       while (true)
       {
            bool not_valid = true;

            for (int i = 0; i < 16; i++)
            {   
                if (!(card_number[i] >= '0' && card_number[i] <= '9'))
                {
                    not_valid = false;
                    break;          // stop scanning, no need to look further
                }
            }

        if (not_valid) break;       // good input, leave the retry loop

        std::cout << "Sorry, invalid character. Please try again: ";
        std::cin >> card_number;
}
           
        
        
        
        


    //pass int arr to checkLuhn
    checkLuhn(card_number);

    //ask user if want continue
    std::cout<<std::endl<<"Would you like to check another number?"<<std::endl;
    std::cout<<std::endl<<"[y] to start               [n] to exit"<<std::endl;
    std::cin>>start;
    }
    

    //PROCESS
    
        
}
