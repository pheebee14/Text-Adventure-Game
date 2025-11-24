#include <iostream>
#include <thread>
#include <chrono>

//hour 5: reflect on todays code and think of any way to optimize/speed this up.
//SAVE FOR HOUR 4 DEBUGGING SESSION DEBUGGGGGG!!

void peasant_initialise_route();
void peasant_left_forest_route();

namespace character_selection {
    std::string race_type;
    std::string status_type;
}

namespace choices {
    char normalchoice;
    int significantchoice;
    char extraordinarychoice;
    char endingchoice;
    std::string typechoice;
}

namespace helpers {
    bool hasprincess = false;
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
    std::string clothing = "You are naked.";
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
    std::cout << "CLOTHING? " << clothing << std::endl;
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
        peasant_initialise_route();
    }

    return 0;

}

void peasant_initialise_route() {
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
        case 1:
            std::cout << "You head to the entrance of the forest. The forest splits, left or right? (l/r) (lowercase): ";
            std::cin >> extraordinarychoice;
            switch (extraordinarychoice){
                case 'l':
                    std::cout << "-----------------------" << std::endl;
                    std::cout << "LEFT ROUTE - FOREST" << '\n' << std::endl;
                    peasant_left_forest_route();
                    break;
            }
            break;

        case 2: std::cout << "You explore through the tall wheat fields for a while, until you find a barn house. Barn house or keep going? (b/g) (lowercase): " << std::endl; break;
        case 3: load_stats(); break;
        default: "1 2 OR 3!!"; break;

    }
    
}

void peasant_left_forest_route() {
    using namespace choices;
    using namespace helpers;
    std::cout << "You take the left route in the forest, walking along the path, until you see an injured princess bleeding, laying against a tree stump." << std::endl;
    std::cout << "Do you save her, or keep walking forward? (s/w) (lowercase): ";
    std::cin >> extraordinarychoice;

    switch (extraordinarychoice){
        case 's':
            hasprincess = true;
            std::cout << "You move to the princess, scooping her up, continuing to walk along the path." << std::endl; break;
        case 'w':
            std::cout << "You continue to walk along the path, leaving the princess to fend for herself against the tree stump." << std::endl; break;
    }

    std::cout << "As you continue to walk along trail on the left forest path, you discover a group of knights blocking your pathway. Together they speak in unison:" << std::endl;
    if (hasprincess == true){
        std::cout << "Lowly peasant. What are you doing with the princess?! Put her down this instant!" << std::endl;
    }
    else {
        std::cout << "Lowly peasant. Have you seen the princess in any moment of your pathetic day? (y/n) (lowercase): ";
        std::cin >> extraordinarychoice;
        switch (extraordinarychoice) {
            case 'y':
                std::cout << "Where is she?! Tell us now! (She's up your ***/She's in the forest somewhere!): ";
                std::cin >> typechoice;
                break;
            case 'n':
                std::cout << "Then don't let us waste anymore time! Begone peasant! " << std::endl; break;
        }
    }

    if (typechoice == "She's up your ***"){
        std::cout << "HOW DARE YOU SPEAK SUCH INSOLENCE?! KILL HIM NOW!" << std::endl;
        std::cout << "-------------------------------------------------" << std::endl;
        std::cout << "YOU - DIED" << std::endl;
    }
    else if (typechoice == "She's in the forest somewhere!"){
        std::cout << "Well no crap peasant! You're too dumb! We're not wasting our time on you!" << std::endl;
        std::cout << "The group of knights walk away from you." << std::endl;
    }

    std::cout << "You negotiate with the group of knight's, and they agree to accompany you to the kingdom castle." << std::endl;
}
