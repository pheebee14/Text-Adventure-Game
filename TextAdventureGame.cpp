#include <iostream>
#include <thread>
#include <chrono>

//hour 5: reflect on todays code and think of any way to optimize/speed this up.
//SAVE FOR HOUR 4 DEBUGGING SESSION DEBUGGGGGG!!

namespace character_selection {
    std::string race_type;
    std::string status_type;
}

namespace choices {
    char normalchoice;
    int significantchoice;
    char extraordinarychoice;
    char endingchoice;
}

namespace player_stats {
    using namespace character_selection;
    std::string race = race_type;
    std::string status = status_type;
    int level = 0;
    double hp = 0;
    double money = 0;
    int dmg = 0;
    int defense = 0;
}

void load_stats(){
    using namespace player_stats;
    std::cout << "** STATS **";
    std::cout << "*******************************" << std::endl;
    std::cout << "RACE: " << race << std::endl;
    std::cout << "STATUS: " << status << std::endl;
    std::cout << "LEVEL: " << level << std::endl;
    std::cout << "HP: " << hp << std::endl;
    std::cout << "MONEY: " << money << std::endl;
    std::cout << "DAMAGE: " << dmg << std::endl;
    std::cout << "DEFENSE: " << defense << std::endl;
    std::cout << "*******************************" << std::endl;
}

void SelectCharacter () {
    using namespace character_selection;
    do {
        std::cout << "Choose your race (human/elf/orc/fairy) (all lowercase): ";
        std::cin >> race_type; 
        if (race_type != "human" && race_type != "elf" && race_type != "orc" && race_type != "fairy"){
            std::cout << "Enter a valid race!" << std::endl;
        }
    }while (race_type != "human" && race_type != "elf" && race_type != "orc" && race_type != "fairy");

    do {
        std::cout << "Choose your status (peasant/noble/king/farmer) (all lowercase): ";
        std::cin >> status_type;
        if (status_type != "peasant" && status_type != "noble" && status_type != "king" && status_type != "farmer"){
            std::cout << "Enter a valid status!" << std::endl;
        }
    }while (status_type != "peasant" && status_type != "noble" && status_type != "king" && status_type != "farmer");

    std::cout << "You've completed character selection." << std::endl;
}

std::string status_routes(std::string status_type) {
    using namespace character_selection;
    using namespace choices;
    do {
        if (status_type == "peasant"){
            std::cout << "You awake in a daze, laying in a haystack. Get up? (y/n): ";
            std::cin >> normalchoice;
            if (normalchoice != 'y' && normalchoice != 'Y' && normalchoice != 'n' && normalchoice != 'N'){
                std::cout << "Enter a valid choice! Yes or No!" << std::endl;
            }
            else if (normalchoice == 'n' || normalchoice == 'N'){
                do{
                    std::cout << "You keep sleeping.." << std::endl;
                    std::cout << "Get up? (y/n) ";
                    std::cin >> normalchoice;
                }while(normalchoice == 'n' || normalchoice == 'N');
            }
        }
        else if (status_type == "noble"){
            std::cout << "You awake in the comfortable bed of your manor. A maid is beside you. She calls out: 'My lord, breakfast is ready..'" << std::endl;
            std::cout << "Would you like to come and eat..? (y/n): ";
            std::cin >> normalchoice;
            if (normalchoice != 'y' && normalchoice != 'Y' && normalchoice != 'n' && normalchoice != 'N'){
                std::cout << "Enter a valid choice! Yes or No!" << std::endl;
            }
            else if (normalchoice == 'n' || normalchoice == 'N'){
                do{
                    std::cout << "You keep sleeping.." << std::endl;
                    std::cout << "Get up? (y/n) ";
                    std::cin >> normalchoice;
                }while(normalchoice == 'n' || normalchoice == 'N');
            }
        }    
        else if (status_type == "king"){
            std::cout << "You awake in a royal bed in your castle, your three wives are laying beside you. They all call out: '5 more minutes..'" << std::endl;
            std::cout << "Get up? Or indulge in your wive's wishes. (y/n): ";
            std::cin >> normalchoice;
            if (normalchoice != 'y' && normalchoice != 'Y' && normalchoice != 'n' && normalchoice != 'N'){
                std::cout << "Enter a valid choice! Yes or No!" << std::endl;
            }
            else if (normalchoice == 'n' || normalchoice == 'N'){
                do{
                    std::cout << "You keep sleeping.." << std::endl;
                    std::cout << "Get up? (y/n) ";
                    std::cin >> normalchoice;
                }while(normalchoice == 'n' || normalchoice == 'N');
            }
        }
    }while (normalchoice != 'y' && normalchoice != 'Y' && normalchoice != 'n' && normalchoice != 'N');

    return status_type;
}

void peasant_gameplay() {
    using namespace character_selection;
    using namespace choices;

    std::cout << "You get up from the haystack. Looking around, you see nothing but a forest in front, and the surrounding area are wheat fields." << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Go to the forest (1): " << std::endl;
    std::cout << "Explore the wheat fields (2): " << std::endl;
    std::cout << "A magic mirror is next to you, check yourself out? (3): " << std::endl;
    std::cout << "What do you do? ";
    std::cin >> significantchoice;

    switch (significantchoice){
        case 1: std::cout << "You head to the entrance of the forest. The forest splits, left or right? (l/r): " << std::endl; break;
        case 2: std::cout << "You explore through the tall wheat fields for a while, until you find a barn house. Barn house or keep going? (b/g): " << std::endl; break;
        case 3: load_stats(); break;
        default: "1 2 OR 3!!"; break;

    }
}

int main() {
    std::cout << "Welcome to Pheeb's fantasy RPG game!" << std::endl;
    using namespace character_selection;
    using namespace choices;

    SelectCharacter();

    std::cout << "---------- MAIN GAME ----------" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Tip: Did you know? Your choices have an impact on your gameplay. :) \n" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::string status_enroute = status_routes(status_type);

    if (status_enroute == "peasant"){
        peasant_gameplay();
    }

    return 0;

}