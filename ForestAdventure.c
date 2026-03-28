#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    srand(time(NULL));
    int choice;
    int health = 100;
    int gold = 0;
    int potions = 0;
    int gameOver = 0;

    while(!gameOver) {
        clearScreen();
        printf("\033[1;32m"); 
        printf("🗡️  Forest Adventure Pro 🎮\n");
        printf("\033[0m"); 
        printf("Health: %d | Gold: %d | Potions: %d\n", health, gold, potions);
        printf("Choose your action:\n");
        printf("1. Explore the forest 🌲\n");
        printf("2. Farm gold 💰\n");
        printf("3. Visit the village 🏘️\n");
        printf("4. Rest at camp 🔥\n");
        printf("5. Check inventory 🎒\n");
        printf("6. Exit game ❌\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 6) {
            printf("\nThanks for playing! Goodbye 👋\n");
            break;
        }

        switch(choice) {
            case 1: { 
                int event = rand() % 5;
                if(event == 0) { 
                    int damage = rand() % 20 + 5;
                    health -= damage;
                    printf("\nA wild wolf attacks! You lose %d health 🐺\n", damage);
                } 
                else if(event == 1) { 
                    int found = rand() % 50 + 10;
                    gold += found;
                    printf("\nYou found %d gold coins hidden under leaves 💰\n", found);
                } 
                else if(event == 2) { 
                    if(potions == 0) {
                        printf("\nYou encounter a Goblin Boss ⚔️ but you have no potions! Retreat first.\n");
                        break;
                    }
                    int bossHealth = 50 + rand() % 50;
                    printf("\n⚔️ A Goblin Boss appears! HP: %d\n", bossHealth);
                    while(bossHealth > 0 && health > 0) {
                        int attack;
                        printf("Choose attack: 1. Sword ⚔️ 2. Magic 🔮 3. Potion 🍷\n");
                        scanf("%d", &attack);
                        if(attack == 1) bossHealth -= 15 + rand() % 10;
                        else if(attack == 2) bossHealth -= 10 + rand() % 20;
                        else if(attack == 3) {
                            if(potions > 0) {
                                health += 25;
                                potions--;
                                printf("You drank a potion. Health +25 ❤️\n");
                            } else printf("No potions left!\n");
                        }
                        if(bossHealth > 0) {
                            int damage = 10 + rand() % 15;
                            health -= damage;
                            printf("Goblin attacks! You lose %d health 🩸\n", damage);
                        } else {
                            int reward = rand() % 50 + 20;
                            gold += reward;
                            printf("You defeated the Goblin Boss! Earned %d gold 🎉\n", reward);
                        }
                    }
                } 
                else if(event == 3) { 
                    potions++;
                    printf("\nYou found a healing potion! 🍷\n");
                } 
                else {
                    printf("\nThe forest is calm. Nothing happens 🌳\n");
                }
                break;
            }

            case 2: { 
                int earned = rand() % 30 + 10;
                gold += earned;
                printf("\nYou spend time gathering resources and earn %d gold 💰\n", earned);
                break;
            }

            case 3: { 
                int villageChoice;
                printf("\nYou enter the village. What do you want to do?\n");
                printf("1. Buy potion (10 gold, +25 health) 💊\n");
                printf("2. Talk to villagers 🗣️\n");
                printf("Enter your choice: ");
                scanf("%d", &villageChoice);

                if(villageChoice == 1) {
                    if(gold >= 10) {
                        gold -= 10;
                        potions++;
                        printf("Potion purchased! 🍷 Total potions: %d\n", potions);
                    } else {
                        printf("Not enough gold! 💸\n");
                    }
                } else {
                    printf("Villagers tell you rumors of treasures and hidden bosses deep in the forest 🏞️\n");
                }
                break;
            }

            case 4: { 
                health += 20;
                printf("\nYou rest at camp. Health restored by 20 ❤️\n");
                break;
            }

            case 5: { 
                printf("\n🎒 Inventory:\n");
                printf("Health: %d\n", health);
                printf("Gold: %d\n", gold);
                printf("Potions: %d\n", potions);
                break;
            }

            default:
                printf("\n❌ Invalid choice, try again!\n");
        }

        if(health <= 0) {
            printf("\n💀 You died in the forest. Game Over!\n");
            gameOver = 1;
        }

        printf("\nPress Enter to continue...");
        getchar(); 
        getchar(); 
    }

    return 0;
}