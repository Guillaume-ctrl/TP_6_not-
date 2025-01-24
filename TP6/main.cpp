#include <iostream>
#include "Game.hpp"
#include "Start.hpp"
#include "Land.hpp"
#include "Chance.hpp"
#include "IRS.hpp"
#include "Heps.hpp"
#include "Park.hpp"


void linkCase(Case* newCase, Case*& previousCase)
{
    newCase->setPreviousCase(previousCase);
    previousCase->setNextCase(newCase);
    previousCase = newCase; // advance
};

int main() 
{
    GGame = new Game;

    GGame->start();
    Case* startCase = new Start();
    Case* currentCase = startCase;
    Case* previousCase = startCase;



    ////
    //// 2) Fill the board squares in clockwise order
    ////
    //// Bd de Belleville (6,000 F → 90)
    //currentCase = new Land("Bd de Belleville", 90);
    //linkCase(currentCase,previousCase);
    //
    //// Caisse de Communauté (no price)
    //currentCase = new Case("Caisse de Communauté");
    //linkCase(currentCase,previousCase);
    //
    //// Rue Lecourbe (6,000 F → 90)
    //currentCase = new Land("Rue Lecourbe", 90);
    //linkCase(currentCase,previousCase);
    //
    //// Impôt sur le revenu (20,000 F → 300 if you choose lump‐sum)
    //currentCase = new IRS("Impôt sur le revenu", 300);
    //linkCase(currentCase,previousCase);
    //
    //// Gare Montparnasse (20,000 F → 300)
    //currentCase = new Railroad("Gare Montparnasse", 300);
    //linkCase(currentCase,previousCase);
    //
    //// Rue de Vaugirard (10,000 F → 150)
    //currentCase = new Land("Rue de Vaugirard", 150);
    //linkCase(currentCase,previousCase);
    //
    //// Chance
    //currentCase = new Chance("Chance");
    //linkCase(currentCase,previousCase);
    //
    //// Rue de Courcelles (10,000 F → 150)
    //currentCase = new Land("Rue de Courcelles", 150);
    //linkCase(currentCase,previousCase);
    //
    //// Avenue de la République (12,000 F → 180)
    //currentCase = new Land("Avenue de la République", 180);
    //linkCase(currentCase,previousCase);
    //
    //// En Prison / Simple Visite
    //currentCase = new Heps("En Prison");
    //linkCase(currentCase,previousCase);
    //
    //// Bd de la Villette (14,000 F → 210)
    //currentCase = new Land("Bd de la Villette", 210);
    //linkCase(currentCase,previousCase);
    //
    //// Compagnie d’Électricité (15,000 F → 225)
    //currentCase = new Utility("Compagnie d’Électricité", 225);
    //linkCase(currentCase,previousCase);
    //
    //// Avenue de Neuilly (14,000 F → 210)
    //currentCase = new Land("Avenue de Neuilly", 210);
    //linkCase(currentCase,previousCase);
    //
    //// Rue de Paradis (16,000 F → 240)
    //currentCase = new Land("Rue de Paradis", 240);
    //linkCase(currentCase,previousCase);
    //
    //// Gare de Lyon (20,000 F → 300)
    //currentCase = new Railroad("Gare de Lyon", 300);
    //linkCase(currentCase,previousCase);
    //
    //// Avenue Mozart (18,000 F → 270)
    //currentCase = new Land("Avenue Mozart", 270);
    //linkCase(currentCase,previousCase);
    //
    //// Caisse de Communauté
    //currentCase = new CommunityChest("Caisse de Communauté");
    //linkCase(currentCase,previousCase);
    //
    //// Bd Saint-Michel (18,000 F → 270)
    //currentCase = new Land("Bd Saint-Michel", 270);
    //linkCase(currentCase,previousCase);
    //
    //// Place Pigalle (20,000 F → 300)
    //currentCase = new Land("Place Pigalle", 300);
    //linkCase(currentCase,previousCase);
    //
    //// Parc Gratuit
    //currentCase = new Park("Parc Gratuit");
    //linkCase(currentCase,previousCase);
    //
    //// Avenue Matignon (22,000 F → 330)
    //currentCase = new Land("Avenue Matignon", 330);
    //linkCase(currentCase,previousCase);
    //
    //// Chance
    //currentCase = new Chance("Chance");
    //linkCase(currentCase,previousCase);
    //
    //// Bd Malesherbes (22,000 F → 330)
    //currentCase = new Land("Bd Malesherbes", 330);
    //linkCase(currentCase,previousCase);
    //
    //// Avenue Henri-Martin (24,000 F → 360)
    //currentCase = new Land("Avenue Henri-Martin", 360);
    //linkCase(currentCase,previousCase);
    //
    //// Gare du Nord (20,000 F → 300)
    //currentCase = new Railroad("Gare du Nord", 300);
    //linkCase(currentCase,previousCase);
    //
    //// Faubourg Saint-Honoré (26,000 F → 390)
    //currentCase = new Land("Faubourg Saint-Honoré", 390);
    //linkCase(currentCase,previousCase);
    //
    //// Place de la Bourse (26,000 F → 390)
    //currentCase = new Land("Place de la Bourse", 390);
    //linkCase(currentCase,previousCase);
    //
    //// Compagnie des Eaux (15,000 F → 225)
    //currentCase = new Utility("Compagnie des Eaux", 225);
    //linkCase(currentCase,previousCase);
    //
    //// Rue La Fayette (28,000 F → 420)
    //currentCase = new Land("Rue La Fayette", 420);
    //linkCase(currentCase,previousCase);
    //
    //// Allez en Prison
    //currentCase = new GoToJail("Allez en Prison");
    //linkCase(currentCase,previousCase);
    //
    //// Avenue de Breteuil (30,000 F → 450)
    //currentCase = new Land("Avenue de Breteuil", 450);
    //linkCase(currentCase,previousCase);
    //
    //// Avenue Foch (30,000 F → 450)
    //currentCase = new Land("Avenue Foch", 450);
    //linkCase(currentCase,previousCase);
    //
    //// Caisse de Communauté
    //currentCase = new CommunityChest("Caisse de Communauté");
    //linkCase(currentCase,previousCase);
    //
    //// Bd des Capucines (32,000 F → 480)
    //currentCase = new Land("Bd des Capucines", 480);
    //linkCase(currentCase,previousCase);
    //
    //// Gare Saint-Lazare (20,000 F → 300)
    //currentCase = new Railroad("Gare Saint-Lazare", 300);
    //linkCase(currentCase,previousCase);
    //
    //// Chance
    //currentCase = new Chance("Chance");
    //linkCase(currentCase,previousCase);
    //
    //// Champs-Élysées (35,000 F → 525)
    //currentCase = new Land("Champs-Élysées", 525);
    //linkCase(currentCase,previousCase);
    //
    //// Taxe de luxe (10,000 F → 150)
    //currentCase = new IRS("Taxe de luxe", 150);
    //linkCase(currentCase,previousCase);
    //
    //// Rue de la Paix (40,000 F → 600)
    //currentCase = new Land("Rue de la Paix", 600);
    //linkCase(currentCase,previousCase);
    //
    //startCase->setPreviousCase(currentCase);
    //currentCase->setNextCase(startCase);
    //
    ////
    //// 3) Close the loop: link the last square back to start
    ////
    //previousCase->setNextCase(startCase);
    //startCase->setPreviousCase(previousCase);

    delete GGame;
    return 0;
}
