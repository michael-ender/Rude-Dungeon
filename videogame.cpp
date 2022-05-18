#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h>
#include <ctime>
#include <ctype.h>

using namespace std;

//REALLY REALLY BIG THING YOU NEED TO IMPLEMENT:
//implement faulty catches when you enter in a LETTER in an if statement
//it catches if you enter in a wrong number but there's nothing there if you enter in a letter

//implement a high score thing

void shop_keep(int &coins, int &potions, int &damage_up, int &temp_sword) {
    //potions and other stuff you can buy in the store
    //you should update this to be mapping later but for now it's just going to be variables

    int damage_up_price = 20;
    int life_up_price = 40;
    int better_sword_price = 100;       //increase some amount every time you buy an upgrade

    //possibly come up with different name for better swords    

    cout << "\nWelcome to my happy humble shop :) Now buy some shit, I've got things to do";
    cout << "\nIf you don't buy anything I'll kill you in your sleep\n";
    bool at_the_sto;                         //if at_the_sto = 0, leave sto
    string big_ol_choice;                   //with it being a string, you can enter 0-3 and above or below and words and it won't mess up
    while (at_the_sto != true) {
        cout << "\nGIMME YO WALLET!...let's see...hmm...you got " << coins << " coins\n";
        cout << "[Enter 0 to leave]\n";
        cout << "1. Damage Up Potions - 20 coins\n";
        cout << "2. Life Up Potions - 40 coins\n";
        cout << "3. Sword Upgrade (10+ points) - 100 coins\n";
        cout << "Whatchu want boy?\n";
        cin >> big_ol_choice;
        if (big_ol_choice == "0") {
            at_the_sto = false;
            break;
        }
        else if (big_ol_choice == "1") {
            if (coins < damage_up_price) {
                cout << "\nYOU CAN'T AFFORD THAT SHIT!\n\n";
                continue;
            }
            damage_up += 1;
            coins -= damage_up_price;
        }
        else if (big_ol_choice == "2") {
            if (coins < life_up_price) {
                cout << "\nYOU CAN'T AFFORD THAT SHIT!\n\n";
                continue;
            }
            potions += 1;
            coins -= life_up_price;
        }
        else if (big_ol_choice == "3") {
            if (coins < better_sword_price) {
                cout << "\nYOU CAN'T AFFORD THAT SHIT!\n\n";
                continue;
            }
            temp_sword += 1;
            coins -= better_sword_price;
        }
        else {
            cout << "\nBoy if you don't enter in a number between 0 and 3\n";
        }
    }
    cout << "\nhave fun slayin all them bitches\n";
}

int main () {               //!!!!!!!!!!!!!!! MAIN GAME  !!!!!!!!!!!!!

    int potions = 5;        //number of health potions you have (maybe add different sizes)
    int damage_up = 5;      //number of damage up potions you have
    int health = 100;             //health of player
    int max_health = health;         //max health of player
    int coins = 0;          //how many coins the player has

    int bad_health;         //health of bad guy
    int attack = 5;             //attack of player
    int extra_attack = 0;        //attack when used a damage_up
    int bad_attack;         //attack of bad guy
    bool gametime = true;   //while true, game is playing (loop is staying active)
    bool wannaplay = true;  //asking player to play again at the end of the game
    int killed = 0;         //how many monsters you killed

    int dungeon_diff = 1;   //level of difficulty in dungeon
    int temp_dd = dungeon_diff;     //temporal variable for dungeon difficulty
    int dung_count = 0;             //number of dungeons you completed

    string choose;
    cout << "Would you like to explore some cave and maybe get some cool stuff or something? (Y/N)\n";
    cin >> choose;          //if player types y or Y then game starts, if n or N, then game ends
    while (gametime) {      //this loops the game for infinity until you die or something
        int randomNum;
        srand(time(0));
        while (wannaplay) {
            if (choose == "Y" || choose == "y") {
                cout << "Great! Let's kill a dude or something.\n";
                wannaplay = false;
            }
            else if (choose == "N" || choose == "n") {
                cout << "Aw man, aite. You're missin out though.\n";
                gametime = false;
                wannaplay = false;
            }
            else {
                cout << "Man you entered the wrong thing. Try N or Y\n";
                cin >> choose;
            }
        }

        if (gametime == false) {        //breaks out of entire thing if you choose n or N
            break;
        }
    
        cout << "You walked upon this frickin HUGE cave!\nThere's goblins and like other cave monsters\n";

        bad_health = 70;
        int temp_bad_health = 70;
        int back_health_back;       //used for when you leave and come back (shop keep)

        bad_attack = 5;
        int leave = 1;      //if 0 then they leave              //increase leave by one with each iteration of dungeons
        int decision;
        string temp_leave_game;        //safety variable
        int leave_game;  //if 0 leave game entirely, if 1 go to shop, if 2 enter dungeon

        /*do {
            cout << "Will you enter the cave or nah?\n";
            cout << "0. Leave completely like a widdle wimpy bitch\n";
            cout << "1. Go to Shop\n";
            cout << "2. Enter the dungeon!! YEAHHH!! DUNGEON SLAYING TIME!!!!\n";
            cin >> leave_game;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "You didn't enter a number\n\n";
            }
            if (leave_game > 2 || leave_game < 0) {
                cout << "Enter a number between 0-2\n";
            }
        } while(cin.fail() && (leave_game > 2 || leave_game < 0));
        */
        do {
            cout << "\nEnter in a number between 0-2\n";
            cout << "0. Leave completely like a widdle wimpy bitch\n";
            cout << "1. Go to Shop\n";
            cout << "2. Enter the dungeon!! YEAHHH!! DUNGEON SLAYING TIME!!!!\n";
            cin >> temp_leave_game;
            try {
                leave_game = stoi(temp_leave_game);
            }
            catch (exception &err) {
                cout << "Converstion failure: " << err.what() << endl;
                cout << "Don't enter a freakin letter dummy\n";
            }
        } while (leave_game > 2 || leave_game < 0);

        while (leave_game != 0) {
            while (health > 0 && leave != 0 && leave_game == 2 && dungeon_diff != 0) {                  //loop goes back to here to allow player and monster to attack
                cout << "\nHealth --> " << health << endl;                                                  //this is the whole game portion....do not mess with it
                cout << "Enemy health --> " << bad_health << endl;                                          //because this works
                cout << "\nWould you like to...\n";
                cout << "1. Use Potion ( " << potions << " ) \n";
                cout << "2. Use Increase Attack Potion ( " << damage_up << " ) \n";
                cout << "3. Attack!\n";
                cout << "4. Attempt to escape...like a bitch...\n";
                cin >> decision;
                switch (decision) {
                    case 1:                 //potion (if 0 potions, go back to choosing)
                        if (potions < 1) {
                            cout << "You don't have anymore potions\n";
                            continue;
                        }
                        else {
                            potions = potions - 1;                          //reduce potions by one if one is used
                            cout << "You chose a potion (heal for 20)\n";
                            health = health + 20;                           //potions heal for 20
                            if (health > max_health) {
                                health = max_health;                        //if the potion goes above max health, then reduce to ma
                            }
                            cout << "Your health is now " << health << endl;
                        }
                        break;
                    case 2:                 //damage potion (if 0, go back to beginning)
                        if (damage_up < 1) {
                            cout << "You don't have anymore potions\n";
                            continue;
                        }
                        else {
                            damage_up = damage_up - 1;
                            cout << "You chose a damage up potion!\n";
                            extra_attack = 10;                               //makes the extra attack 10                      
                        }
                        break;
                    case 3:                 //attack
                        cout << "\nYOU GONNA SMACK DOWN!\n";
                        randomNum = rand() % 4 + 1;
                        if (randomNum == 4) {                               //if the randomNum is 4, then it's a critical hit
                            cout << "CRITICAL HIT!\n";
                            attack = attack * 2;                            //critical hit is attack * 2
                            cout << "You hit the monster for " << attack + extra_attack << endl;
                            bad_health = bad_health - attack - extra_attack;
                            extra_attack = 0;
                            attack = attack / 2;                            //reset attack to regular      
                        }
                        else {
                            cout << "You hit the monster for " << attack + extra_attack << endl;
                            bad_health = bad_health - attack - extra_attack;
                            extra_attack = 0;
                        }
                        break;
                    case 4:             //escape
                        cout << "You attempt to escape!!\n";
                        sleep(2);
                        cout << "\nlike a bitch...\n\nANYWAYS!!!!\n\n";
                        randomNum = rand() % 2 + 1;
                        if (randomNum == 2) {
                            cout << "Yay! You get to escape with your tail between your legs...\n";
                            leave = 0;
                            continue;
                        }
                        else {
                            cout << "The monster's gaze is sexual so you're too scared to leave\n";
                        }
                        break;
                    default:            //error input
                        cout << "Enter an actual word dumbass\n";
                        continue;
                }
                if (bad_health > 0) {                       //skip if leave is 0
                    randomNum = rand() % 6 + 1;
                    if (randomNum == 6) {
                        cout << "MONSTER CRITICAL HIT! D:\n";
                        bad_attack = bad_attack * 2;
                        cout << "Monster hits you for " << bad_attack << endl;
                        health = health - bad_attack;
                        bad_attack = bad_attack / 2;
                    }
                    else {
                        cout << "Monster hits you for " << bad_attack << endl;
                        health = health - bad_attack;
                    }
                }  
                else {
                    killed++;                                                       //keeps track of how many monsters you killed
                    dungeon_diff--;                                                 //once dungeon_diff hits 0, you finished a dungeon
                    cout << "You've killed " << killed << " monster(s)!\n";
                    bad_health = temp_bad_health + 5;                               //health of monsters go up by 5
                    temp_bad_health = temp_bad_health + 5;
                    randomNum = rand() % 10 + 1;
                    coins += randomNum;                                             //random number of coins after each kill
                    cout << "You found " << randomNum << " coins!\n";
                    if (randomNum > 0 && randomNum <= 2) {                          // 1/5 chance to find health potion
                        cout << "You found a health potion!\n";
                        potions = potions + 2;
                    }
                    else if (randomNum >= 3 && randomNum < 5) {                     // 1/5 chance to find damage potion
                        cout << "You found a damage potion!\n";
                        damage_up = damage_up + 2;
                    }
                    else if (randomNum == 10) {                                     // 1/10 chance to get a better sword
                        cout << "YOU FOUND A BETTER SWORD!!!\n";
                        attack = attack + 10;
                    }
                } 
            }       //end of dungeon (leave_game == 2)

            if (dungeon_diff == 0) {        //random coin at the end of each dungeon (not level)
                cout << "Congrats! You've completed the dungeon! You found a ziplock bag full of coins!\n";
                randomNum = rand() % 50 + 20;
                coins += randomNum;
                cout << "You found " << randomNum << " coins!\n";
                temp_dd++;
                dungeon_diff = temp_dd;
                dung_count++;
                cout << "\nYou currently have " << coins << " coins\n";
                cout << "0. Leave Game\n";
                cout << "1. Pout to the shop keep with your broke ass!\n";
                cout << "2. Go to the scary spooky dungeon\n";
                cin >> leave_game;
                while (leave_game > 2 || leave_game < 0) {
                    if (leave_game == 0) {
                        break;
                    }
                    else if (leave_game == 1) {              //GO TO THE SHOP KEEEEEEP
                        int temp_sword = 0;
                        shop_keep(coins, potions, damage_up, temp_sword);
                        cout << "\nYou now have " << coins << " coins\n";
                        cout << potions << " health potions\n";
                        cout << damage_up << " damage potions\n";
                        attack += (temp_sword * 5);
                        cout << "Your attack damage is now " << attack << endl;
                    }
                    else if (leave_game == 2) {
                        leave = 1;                  //leave has to != 0 to enter dungeon
                    }
                    else {
                        cout << "\n\nbro fr??...\n\n";
                    }
                }
            }

            if (leave_game == 1) {              //GO TO THE SHOP KEEEEEEP if chosen from the beginning
                int temp_sword = 0;
                shop_keep(coins, potions, damage_up, temp_sword);
                cout << "\nYou now have " << coins << " coins\n";
                cout << potions << " health potions\n";
                cout << damage_up << " damage potions\n";
                attack += (temp_sword * 5);
                cout << "Your attack damage is now " << attack << endl;
            }

            int leave_this_hoe = 1;
            while (dungeon_diff != 0 && leave_this_hoe != 0 && leave_game != 2) {
                if (health <= 0) {
                    break;
                }
                cout << "\nYou currently have " << coins << " coins\n";
                cout << "0. Leave Game\n";
                cout << "1. Pout to the shop keep with your broke ass!\n";
                cout << "2. Go to the scary spooky dungeon\n";
                cin >> leave_game;
                if (leave_game == 0) {
                    leave_this_hoe = 0;
                }
                else if (leave_game == 1) {              //GO TO THE SHOP KEEEEEEP
                    int temp_sword = 0;
                    shop_keep(coins, potions, damage_up, temp_sword);
                    cout << "\nYou now have " << coins << " coins\n";
                    cout << potions << " health potions\n";
                    cout << damage_up << " damage potions\n";
                    attack += (temp_sword * 5);
                    cout << "Your attack damage is now " << attack << endl;
                }
                else if (leave_game == 2) {
                    leave = 1;                  //leave has to != 0 to enter dungeon
                    leave_this_hoe = 0;
                    continue;
                }
                else {
                    cout << "\n\nbro fr?? bro...\n\n";
                }
                /*
                cout << "\nYou currently have " << coins << " coins\n";
                cout << "0. Leave Game\n";
                cout << "1. Pout to the shop keep with your broke ass!\n";
                cout << "2. Go to the scary spooky dungeon\n";
                cin >> leave_game;
                */
            }

            /*
            while (leave_game > 2 || leave_game < 0) {

                cout << "0. Leave Game\n";
                cout << "1. Pout to the shop keep with your broke ass!\n";
                cout << "2. Go to the scary spooky dungeon\n";
                cin >> leave_game;
                if (leave_game == 2) {
                    leave = 1;              //leave has to != 0 to enter dungeon
                }
            }
            */

        }           //end of game

        if (health <= 0) {
            cout << "you died so bad so...sorry\n";
            gametime = false;
        }
        cout << "You killed " << killed << " monsters!\n";
        cout << "you completed " << dung_count << " dungeons";
        if (dung_count == 0) {
            cout << "\noof dude ZERO dungeons? that's sad...you suck actually\n\t\tAND nobody likes you\n";
        }
        cout << "...yeah...\n";
        sleep(2);
        cout << "\nBYE\n\n";
        gametime = false;
    }
    cout << "Have a good life or whatever\n";

    return 0;
}