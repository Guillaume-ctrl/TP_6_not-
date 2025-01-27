#include "Game.hpp"
#include <iostream>
#include "Dice.hpp"
#include <stdexcept>
#include "Bank.hpp"

Game* GGame = nullptr;

Game::Game()
{
    this->m_hotel_count = 12;
    this->m_house_count = 32;
    this->m_bank = nullptr;
    this->m_current_player = 0;

    /* Handle Player name input */
    std::string inputName = "";

    while (true)
    {
        std::cout << "Enter player name (leave empty to stop): ";
        std::getline(std::cin, inputName);

        if (inputName.empty() && this->canStart())
        {
            std::cout << "Game can now start!" << std::endl;
            break;
        }

        bool bAddedPlayer = this->addPlayer(inputName);
        if (!bAddedPlayer)
        {
            std::cerr << "Failed to add Player: " << inputName << std::endl;
        }
    }
}

Game::~Game()
{
    delete this->m_bank;
    for (int i = 0; i < this->m_player_list.size(); i++) {
        delete this->m_player_list[i];
    }
}

bool Game::addPlayer(const std::string& playerName)
{
    if(playerName.empty())
        return false;

    if(this->m_player_list.size() >= 8)
        return false;
    
    this->m_player_list.push_back(new Player(playerName));
    
    return true;
}

bool Game::canStart() const
{
    return m_player_list.size() >= 2;
}

void Game::start()
{
    std::cout << "The game begin ! " << std::endl;
}

void Game::play() 
{
    Player* player = m_player_list[this->m_current_player];
    if (player->getOut()) {
        this->m_current_player = (this->m_current_player + 1) % this->m_player_list.size();
        return;
    }
    if (player->getInPrison())
    {
        std::cout << "Your are in prison, you have 3 option to go out : " << std::endl;
        std::cout << "Option 1 : Pay 50 mono " << std::endl;
        std::cout << "Option 2 : try to exchange a Get out of Jail free card with another player or by using your own" << std::endl;
        std::cout << "Option 3 : Roll the dice and try to catch a double " << std::endl;
        std::cout << "Now answer by typing 1 or 2 or 3" << std::endl;
        std::string response;
        std::getline(std::cin, response);

        // Check the user's response
        if (response == "1") {
            std::cout << "You chose to but it, CONGRATULATION!" << std::endl;
            std::cout << "You now have : " << player->setDeductMoney(50) << " mono" << std::endl;
            BBank.addMoney(50);
            player->setInPrison(0);
        }
        else if (response == "2") {
            std::cout << "You choose card." << std::endl;
        }
        else if (response == "3") {
            std::cout << "You choose to not pay. Let s see if you are lucky!" << std::endl;
            if (DDice.roll() == DDice.roll()) {
                std::cout << "You are lucky!" << std::endl;
                player->setInPrison(0);
            }
            else {
                std::cout << "Looser..." << std::endl;
            }
        }
        else {
            throw std::runtime_error("An error occurred!");
        }
    }
    else {
        std::cout << "Hi " << player->getName() << " it s time to roll the dice!" << std::endl;
        int number = DDice.roll() + DDice.roll();
        unsigned int currentPlayerPosition = player->getPosition();
        unsigned int newPosition = (currentPlayerPosition + number) % TAILLE_PLATEAU;
        player->setPosition(newPosition);

        Case* CaseCourante = &plateau[newPosition];
        displayInfoCase(CaseCourante);

        switch (CaseCourante->getTypeCase()) {
        case TERRAIN_GARE_SERVICE_PUBLIC:
        {
            // Code for TERRAIN_GARE_SERVICE_PUBLIC
            // If the terrain is not owned yet, propose to the player if he/she wants to buy it
            if (CaseCourante->getAcheteur() == nullptr && CaseCourante->isAchetable())
            {
                std::cout << "You have : " << (int) player->getMoneyValue() << std::endl;
                if (player->getMoneyValue() < CaseCourante->getPrix())
                {
                    std::cout << "Sorry you cannot buy it yet" << std::endl;
                }
                else {
                    std::cout << "This area has not been sold yet, do you want to buy it ? y or n" << std::endl;
                    std::string response;
                    std::getline(std::cin, response);

                    // Check the user's response
                    if (response == "y" || response == "Y") {
                        std::cout << "You chose to but it, CONGRATULATION!" << std::endl;

                        CaseCourante->setAcheteur(player);
                        CaseCourante->setAchetable(0);
                        CaseCourante->setVendu(1);

                        std::cout << "You now have : " << player->setDeductMoney(CaseCourante->getPrix()) << " mono" << std::endl;
                    }
                    else if (response == "n" || response == "N") {
                        std::cout << "You chose not to continue." << std::endl;
                        // Add the action you want to perform for "no" here
                    }
                    else {
                        throw std::runtime_error("An error occurred!");
                    }
                }

            }
            else if (CaseCourante->getAcheteur() == player)
            {
                std::cout << "You are at home." << std::endl;
                uint8_t countRouge = 0;
                uint8_t countBleu = 0;
                uint8_t countCian = 0;
                uint8_t countVert = 0;
                uint8_t countMauve = 0;
                uint8_t countRose = 0;
                uint8_t countOrange = 0;
                uint8_t countJaune = 0;
                bool thereIsAtLeastOne = 0;
                // Counting how many terrain the player have by color 
                for (int i = 0; i < TAILLE_PLATEAU; i++) {
                    Couleur c = plateau[i].getCouleur();
                    if (plateau[i].getAcheteur() == player && c != NO_COLOR) {
                        switch (c) {
                        case ROUGE:
                            ++countRouge; // Increment Red
                            break;
                        case BLEU:
                            ++countBleu; // Increment Blue
                            break;
                        case CIAN:
                            ++countCian; // Increment Cyan
                            break;
                        case VERT:
                            ++countVert; // Increment Green
                            break;
                        case MAUVE:
                            ++countMauve; // Increment Mauve
                            break;
                        case ROSE:
                            ++countRose; // Increment Pink
                            break;
                        case ORANGE:
                            ++countOrange; // Increment Orange
                            break;
                        case JAUNE:
                            ++countJaune; // Increment Yellow
                            break;
                        case NO_COLOR:
                            // Do nothing for NO_COLOR
                            break;
                        default:
                            std::cerr << "Unknown Color!" << std::endl;
                            break;
                        }
                    }
                }
                // Say to the user, that he has completed at least one group of color if there is some
                if (countRouge >= 3) {
                    std::cout << "You have all the Rouge color case!" << std::endl;
                    thereIsAtLeastOne = true;
                }
                if (countOrange >= 3) {
                    std::cout << "You have all the Orange color case!" << std::endl;
                    thereIsAtLeastOne = true;
                }
                if (countRose >= 3) {
                    std::cout << "You have all the Rose color case!" << std::endl;
                    thereIsAtLeastOne = true;
                }
                if (countCian >= 3) {
                    std::cout << "You have all the Cian color case!" << std::endl;
                    thereIsAtLeastOne = true;
                }
                if (countBleu >= 2) {
                    std::cout << "You have all the Bleu color case!" << std::endl;
                    thereIsAtLeastOne = true;
                }
                if (countVert >= 3) {
                    std::cout << "You have all the Vert color case!" << std::endl;
                    thereIsAtLeastOne = true;
                }
                if (countMauve >= 2) {
                    std::cout << "You have all the Mauve color case!" << std::endl;
                    thereIsAtLeastOne = true;
                }
                if (countJaune >= 3) {
                    std::cout << "You have all the Jaune color case!" << std::endl;
                    thereIsAtLeastOne = true;
                }

                // If the player have at list all the cases of a color group
                if (thereIsAtLeastOne) {
                    std::cout << "At least one color group is complete!" << std::endl;
                    std::cout << "Do you want to add a House/Motel ? y or n" << std::endl;
                    std::string response;

                    std::getline(std::cin, response);

                    // Check the user's response
                    if (response == "y" || response == "Y") {
                        std::cout << "You chose to add a House/Motel!" << std::endl;

                        // Pick up the color group of the current case and verify that the player own all the terrain of this color
                        Couleur couleurDuGroupeDeMaison = CaseCourante->getCouleur();
                        for (auto& group : allGroups) {
                            if (group.color == couleurDuGroupeDeMaison && group.terrainCount >= group.maxNumberOfTerrain) {
                                if (group.houseCount < 4) {
                                    CaseCourante->addHouse();
                                    group.houseCount++;
                                }
                                else {
                                    CaseCourante->addMotel();
                                    group.hasHotel = true;
                                }
                            }
                        }
                    }
                    else if (response == "n" || response == "N") {
                        std::cout << "You chose not to continue." << std::endl;
                        // Add the action you want to perform for "no" here
                    }
                    else {
                        throw std::runtime_error("An error occurred! Invalid input.");
                    }
                }
                else {
                    std::cout << "No complete color group yet." << std::endl;
                }
            }
            else if (CaseCourante->getAcheteur() != player && CaseCourante->isVendu()) {
                //Else : The player is gonna pay to stay in this property
                std::cout << "You are at the " << CaseCourante->getCaseName() << "The cost rent is : " << CaseCourante->getPrix() << " mono" << std::endl;
                std::cout << "You have : " << player->setDeductMoney(CaseCourante->getTaxe()) << " mono" << std::endl;
                Player* proprietaire = CaseCourante->getAcheteur();
                proprietaire->addMoney((int) CaseCourante->getPrix());
            }

            break;
        }

        case CHANCE:
        {
            // Code for CHANCE
            player->addCard(CARTE_CHANCE);
            Dice ChanceDice(1);
            int number = ChanceDice.roll();
            std::cout << "Let s roll the Chance dice! This is the result : " << std::endl;
            if (number == 1)
            {
                std::cout << "Unfortunatly you have to pay : " << CaseCourante->getTaxe() << std::endl;
                std::cout << "You still have : " << (int) player->setDeductMoney(CaseCourante->getTaxe()) << std::endl;
            }
            else if (number == 0) {
                std::cout << "Congratulation, you avoided it well!" << std::endl;
            }
            else {
                throw std::runtime_error("An error occurred!");
            }

            break;
        }

        case CAISSE_DE_COMMU:
        {
            // Code for CAISSE_DE_COMMU
            player->addCard(CARTE_CAISSE_DE_COMMUNAUTE);
            break;
        }
        case TAXE_DE_LUXE:
        {
            // Code for TAXE_DE_LUXE
            std::cout << "You have to pay 10000 mono to the bank!" << std::endl;
            player->setDeductMoney(10000);
            BBank.addMoney(10000);
            break;
        }
        case DEPART:
        {
            // Code for DEPART
            std::cout << "CONGRATULATION you won 20000 mono!" << std::endl;
            player->addMoney(20000);
            break;
        }
        case IMPOT_SUR_LE_REVENU:
        {
            // Code for IMPOT_SUR_LE_REVENU
            std::cout << "You have to pay 200 mono to the bank!" << std::endl;
            player->setDeductMoney(200);
            BBank.addMoney(200);
            break;
        }
        case ALLER_EN_PRISON:
        {
            // Code for ALLER_EN_PRISON
            player->addCard(CARTE_ALLER_EN_PRISON);
            player->setPosition(10);
            break;
        }
        case SIMPLE_VISITE:
            // Code for SIMPLE_VISITE

            break;

        case PRISON:
            // Code for PRISON
            break;

        case PARC_GRATUIT:
        {
            // Code for PARC_GRATUIT
            unsigned int moneyInBank = BBank.getMoney();
            player->addMoney(moneyInBank);
            BBank.deductMoney(moneyInBank);
            break;
        }
        default:
            // Code for an unrecognized case (if needed)
            break;
        }
    }
    this->m_current_player = (this->m_current_player + 1) % this->m_player_list.size();
}

bool Game::hasEnded()
{
    unsigned int nbPlayer = this->m_player_list.size();

    for (int i = 0; i < this->m_player_list.size(); i++)
    {
        Player* player = this->m_player_list[i];
        if (player->getOut()) {
            nbPlayer--;
        }
    }

    if (nbPlayer == 1) return 1;
    if (nbPlayer > 1 ) return 0;
}


void Game::checkPlayer() {
    for (int i = 0; i < this->m_player_list.size(); i++)
    {
        Player* player = this->m_player_list[i];
        if ((int)player->getMoneyValue() < 0 && !player->getOut()) {
            std::cout << "Player " << player->getName() << " out" << std::endl;
            player->setOut(1);
        }
    }
}

void Game::displayInfoCase(Case* c) const {
    if (!c) {
        std::cout << "Invalid case pointer!" << std::endl;
        return;
    }

    std::cout << "----- Case Information -----" << std::endl;

    // Display the case name
    std::cout << "Case Name: " << c->getCaseName() << std::endl;

    // Display the type of the case
    std::cout << "Case Type: ";
    switch (c->getTypeCase()) {
    case TERRAIN_GARE_SERVICE_PUBLIC: std::cout << "Terrain/Gare/Service Public"; break;
    case CHANCE:                      std::cout << "Chance"; break;
    case CAISSE_DE_COMMU:             std::cout << "Caisse de Communauté"; break;
    case TAXE_DE_LUXE:                std::cout << "Taxe de Luxe"; break;
    case DEPART:                      std::cout << "Départ"; break;
    case IMPOT_SUR_LE_REVENU:         std::cout << "Impôt sur le Revenu"; break;
    case ALLER_EN_PRISON:             std::cout << "Aller en Prison"; break;
    case SIMPLE_VISITE:               std::cout << "Simple Visite"; break;
    case PRISON:                      std::cout << "Prison"; break;
    case PARC_GRATUIT:                std::cout << "Parc Gratuit"; break;
    default:                          std::cout << "Inconnu"; break;
    }
    std::cout << std::endl;

    // Display the color
    std::cout << "Color: ";
    switch (c->getCouleur()) {
    case NO_COLOR: std::cout << "No Color"; break;
    case MAUVE:    std::cout << "Mauve"; break;
    case CIAN:     std::cout << "Cian"; break;
    case ROSE:     std::cout << "Rose"; break;
    case ORANGE:   std::cout << "Orange"; break;
    case ROUGE:    std::cout << "Rouge"; break;
    case JAUNE:    std::cout << "Jaune"; break;
    case VERT:     std::cout << "Vert"; break;
    case BLEU:     std::cout << "Bleu"; break;
    default:       std::cout << "Inconnu"; break;
    }
    std::cout << std::endl;

    // Display financial information
    std::cout << "Taxe: " << c->getTaxe() << std::endl;
    std::cout << "Prix: " << c->getPrix() << std::endl;

    // Display whether the case is buyable or sold
    std::cout << "Achetable: " << (c->isAchetable() ? "Oui" : "Non") << std::endl;
    std::cout << "Vendu: " << (c->isVendu() ? "Oui" : "Non") << std::endl;

    // Display the player who purchased the case
    if (c->getAcheteur() != nullptr) {
        std::cout << "Acheteur: " << c->getAcheteur()->getName() << std::endl; // Assuming Player class has a getName() method
    }
    else {
        std::cout << "Acheteur: Aucun" << std::endl;
    }

    std::cout << "----------------------------" << std::endl;
}

Player* Game::getBank() const
{
    return this->m_bank;
}
