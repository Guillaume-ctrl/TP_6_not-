#include "Case.hpp"

Case::Case(CaseType typeCase, Couleur couleur, unsigned int taxe, unsigned int prix,
    bool achetable, bool vendu, Player* acheteur,
    const char* caseName, unsigned int maison, unsigned int hotel)
    : m_typeCase(typeCase), m_couleur(couleur), m_taxe(taxe), m_prix(prix),
    m_achetable(achetable), m_vendu(vendu), m_acheteur(acheteur),
    m_caseName(caseName), m_numberOfHouse(0), m_numberMotel(0) {}

inline std::string Case::getName() const
{

}

// Getter and Setter implementations
Couleur Case::getCouleur() const {
    return m_couleur;
}

void Case::setCouleur(Couleur couleur) {
    m_couleur = couleur;
}

CaseType Case::getTypeCase() const {
    return m_typeCase;
}

void Case::setTypeCase(CaseType typeCase) {
    m_typeCase = typeCase;
}

unsigned int Case::getTaxe() const {
    return m_taxe;
}

void Case::setTaxe(unsigned int taxe) {
    m_taxe = taxe;
}

unsigned int Case::getPrix() const {
    return m_prix;
}

void Case::setPrix(unsigned int prix) {
    m_prix = prix;
}

bool Case::isAchetable() const {
    return m_achetable;
}

void Case::setAchetable(bool achetable) {
    m_achetable = achetable;
}

bool Case::isVendu() const {
    return m_vendu;
}

void Case::setVendu(bool vendu) {
    m_vendu = vendu;
}

std::string Case::getCaseName() const {
    return m_caseName;
}

Player* Case::getAcheteur() const {
    return m_acheteur;
}

void Case::setAcheteur(Player* acheteur) {
    m_acheteur = acheteur;
}


void Case::addHouse() {
    if (this->m_numberOfHouse < 4)
    {
        this->m_numberOfHouse += 1;
        this->m_taxe += 25;
    }
}

void Case::addMotel() {
    if (this->m_numberOfHouse < 1)
    {
        this->m_numberMotel += 1;
        this->m_taxe += 100;
    }
}

unsigned int Case::getNumberOfHouse() {
    return this->m_numberOfHouse;
}

unsigned int Case::getNumberMotel() {
    return this->m_numberMotel;
}

class Case plateau[TAILLE_PLATEAU] = {
    Case(DEPART, NO_COLOR, 0, 0, 0, 0, nullptr, "Case Départ"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, MAUVE, 300, 6000, 1, 0, nullptr, "Belleville"),
    Case(CAISSE_DE_COMMU, NO_COLOR, 0, 0, 0, 0, nullptr, "Caisse de Communauté"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, MAUVE, 300, 6000, 1, 0, nullptr, "Lecourbe"),
    Case(IMPOT_SUR_LE_REVENU, NO_COLOR, 20000, 0, 0, 0, nullptr, "Impôts"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, NO_COLOR, 1000, 20000, 1, 0, nullptr, "Gare Montparnasse"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, CIAN, 500, 10000, 1, 0, nullptr, "Vaugirard"),
    Case(CHANCE, NO_COLOR, 1000, 0, 0, 0, nullptr, "Carte Chance"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, CIAN, 500, 10000, 1, 0, nullptr, "Courcelles"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, CIAN, 600, 12000, 1, 0, nullptr, "Républiques"),
    Case(SIMPLE_VISITE, NO_COLOR, 0, 0, 0, 0, nullptr, "Simple Visite"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, ROSE, 700, 14000, 1, 0, nullptr, "La Villette"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, NO_COLOR, 750, 15000, 1, 0, nullptr, "Cie Électricité"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, ROSE, 700, 14000, 1, 0, nullptr, "Neuilly"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, ROSE, 800, 16000, 1, 0, nullptr, "Paradis"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, NO_COLOR, 1000, 20000, 1, 0, nullptr, "Gare de Lyon"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, ORANGE, 900, 18000, 1, 0, nullptr, "Mozart"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, NO_COLOR, 0, 0, 0, 0, nullptr, "Caisse de Communauté"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, ORANGE, 900, 18000, 1, 0, nullptr, "Saint-Michel"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, ORANGE, 1000, 20000, 1, 0, nullptr, "Pigalle"),
    Case(PARC_GRATUIT, NO_COLOR, 0, 0, 0, 0, nullptr, "Parc Gratuit"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, ROUGE, 1100, 22000, 1, 0, nullptr, "Matignon"),
    Case(CHANCE, NO_COLOR, 1000, 0, 0, 0, nullptr, "Carte Chance"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, ROUGE, 1100, 22000, 1, 0, nullptr, "Malesherbes"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, ROUGE, 1200, 24000, 1, 0, nullptr, "Henri-Martin"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, NO_COLOR, 1000, 20000, 1, 0, nullptr, "Gare du Nord"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, JAUNE, 1300, 26000, 1, 0, nullptr, "Saint-Honoré"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, JAUNE, 1300, 26000, 1, 0, nullptr, "La Bourse"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, NO_COLOR, 100, 15000, 1, 0, nullptr, "Cie des Eaux"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, JAUNE, 1400, 28000, 1, 0, nullptr, "La Fayette"),
    Case(ALLER_EN_PRISON, NO_COLOR, 0, 0, 0, 0, nullptr, "Allez en Prison"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, VERT, 1500, 30000, 1, 0, nullptr, "Breteuil"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, VERT, 1500, 30000, 1, 0, nullptr, "Foch"),
    Case(CAISSE_DE_COMMU, NO_COLOR, 1000, 0, 0, 0, nullptr, "Caisse de Communauté"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, VERT, 1575, 32000, 1, 0, nullptr, "Capucines"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, NO_COLOR, 1000, 20000, 1, 0, nullptr, "Gare Saint-Lazare"),
    Case(CHANCE, NO_COLOR, 1000, 0, 0, 0, nullptr, "Chance"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, BLEU, 1525, 35000, 1, 0, nullptr, "Champs-Élysées"),
    Case(TAXE_DE_LUXE, NO_COLOR, 10000, 0, 0, 0, nullptr, "Taxe de Luxe"),
    Case(TERRAIN_GARE_SERVICE_PUBLIC, BLEU, 2000, 40000, 1, 0, nullptr, "La Paix"),
};

// Initialization for each color group
ColorHouseCount redGroup =     { ROUGE,  0, 0, 3, 0 };    
ColorHouseCount blueGroup =    { BLEU,   0, 0, 2, 0 };
ColorHouseCount cyanGroup =    { CIAN,   0, 0, 3, 0 };
ColorHouseCount greenGroup =   { VERT,   0, 0, 3, 0 };
ColorHouseCount mauveGroup =   { MAUVE,  0, 0, 2, 0 };
ColorHouseCount pinkGroup =    { ROSE,   0, 0, 3, 0 };
ColorHouseCount orangeGroup =  { ORANGE, 0, 0, 3, 0 };
ColorHouseCount yellowGroup =  { JAUNE,  0, 0, 3, 0 };

std::vector<ColorHouseCount> allGroups = {
    redGroup, blueGroup, cyanGroup, greenGroup,
    mauveGroup, pinkGroup, orangeGroup, yellowGroup
};

Case Prison(PRISON, NO_COLOR, 0, 0, 0, 0, nullptr, "La Paix");