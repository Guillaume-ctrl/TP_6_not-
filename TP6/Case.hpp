#pragma once
#include <string>
#include "Player.hpp"
#include <map>

/**
 * @brief Base class for a game board case.
 *
 * Represents a single case on the game board with various properties such as type, color,
 * ownership, and building information (houses/hotels).
 */

 /**
  * @enum Couleur
  * @brief Enumeration for the color groups of properties.
  */
enum Couleur {
    NO_COLOR = -1,  ///< No color (default/unassigned).
    ROUGE = 0x00, ///< Red color group.
    BLEU = 0x01, ///< Blue color group.
    CIAN = 0x02, ///< Cyan color group.
    VERT = 0x03, ///< Green color group.
    MAUVE = 0x04, ///< Mauve (purple) color group.
    ROSE = 0x05, ///< Pink color group.
    ORANGE = 0x06, ///< Orange color group.
    JAUNE = 0x07  ///< Yellow color group.
};

/**
 * @enum CaseType
 * @brief Enumeration for the types of cases on the game board.
 */
enum CaseType {
    TERRAIN_GARE_SERVICE_PUBLIC = 0x00, ///< Property, station, or utility.
    CHANCE = 0x01, ///< Chance card case.
    CAISSE_DE_COMMU = 0x02, ///< Community Chest card case.
    TAXE_DE_LUXE = 0x03, ///< Luxury tax case.
    DEPART = 0x04, ///< Start case.
    IMPOT_SUR_LE_REVENU = 0x05, ///< Income tax case.
    ALLER_EN_PRISON = 0x06, ///< Go to jail case.
    SIMPLE_VISITE = 0x07, ///< Just visiting jail case.
    PRISON = 0x08, ///< Jail case.
    PARC_GRATUIT = 0x09  ///< Free parking case.
};

/**
 * @struct ColorHouseCount
 * @brief Tracks house and hotel counts for a specific color group.
 */
struct ColorHouseCount {
    Couleur color;                   ///< Color group.
    unsigned int terrainCount;       ///< Number of properties in the group.
    bool hasHotel;                   ///< Indicates if any property has a hotel.
    unsigned int maxNumberOfTerrain; ///< Maximum number of properties in the group.
    unsigned int houseCount;         ///< Total number of houses in the group.
};

// External color group tracking variables
extern ColorHouseCount redGroup;
extern ColorHouseCount blueGroup;
extern ColorHouseCount cyanGroup;
extern ColorHouseCount greenGroup;
extern ColorHouseCount mauveGroup;
extern ColorHouseCount pinkGroup;
extern ColorHouseCount orangeGroup;
extern ColorHouseCount yellowGroup;

extern std::vector<ColorHouseCount> allGroups;

#define TAILLE_PLATEAU 40 ///< Number of cases on the game board.

/**
 * @class Case
 * @brief Represents a single case on the game board.
 *
 * A case has properties such as type, color, ownership status, and building counts.
 */
class Case {
public:
    /**
     * @brief Default constructor for Case.
     *
     * Initializes the case with default values.
     */
    Case()
        : m_typeCase(DEPART), m_couleur(ROUGE), m_taxe(0), m_prix(0),
        m_achetable(false), m_vendu(false), m_acheteur(nullptr),
        m_caseName("case not defined"), m_numberOfHouse(0), m_numberMotel(0) {}

    /**
     * @brief Constructor for Case.
     *
     * Initializes a case with specific properties.
     *
     * @param typeCase Type of the case.
     * @param couleur Color group of the case.
     * @param taxe Tax value for the case.
     * @param prix Purchase price of the case.
     * @param achetable Indicates if the case can be purchased.
     * @param vendu Indicates if the case is sold.
     * @param acheteur Pointer to the player who owns the case (if any).
     * @param caseName Name of the case.
     * @param maison Number of houses on the case.
     * @param hotel Number of hotels on the case.
     */
    Case(CaseType typeCase,
        Couleur couleur = ROUGE,
        unsigned int taxe = 0,
        unsigned int prix = 0,
        bool achetable = false,
        bool vendu = false,
        Player* acheteur = nullptr,
        const char* caseName = "case not defined",
        unsigned int maison = 0,
        unsigned int hotel = 0);

    /**
     * @brief Get the name of the case.
     * @return The name of the case.
     */
    std::string getName() const;

    // Getter and Setter methods

    /**
     * @brief Get the color of the case.
     * @return The color of the case.
     */
    Couleur getCouleur() const;

    /**
     * @brief Set the color of the case.
     * @param couleur The new color for the case.
     */
    void setCouleur(Couleur couleur);

    /**
     * @brief Get the type of the case.
     * @return The type of the case.
     */
    CaseType getTypeCase() const;

    /**
     * @brief Set the type of the case.
     * @param typeCase The new type for the case.
     */
    void setTypeCase(CaseType typeCase);

    /**
     * @brief Get the tax value for the case.
     * @return The tax value.
     */
    unsigned int getTaxe() const;

    /**
     * @brief Set the tax value for the case.
     * @param taxe The new tax value.
     */
    void setTaxe(unsigned int taxe);

    /**
     * @brief Get the purchase price of the case.
     * @return The purchase price.
     */
    unsigned int getPrix() const;

    /**
     * @brief Set the purchase price of the case.
     * @param prix The new purchase price.
     */
    void setPrix(unsigned int prix);

    /**
     * @brief Check if the case can be purchased.
     * @return True if the case is purchasable, false otherwise.
     */
    bool isAchetable() const;

    /**
     * @brief Set whether the case can be purchased.
     * @param achetable True if the case can be purchased, false otherwise.
     */
    void setAchetable(bool achetable);

    /**
     * @brief Check if the case has been sold.
     * @return True if the case is sold, false otherwise.
     */
    bool isVendu() const;

    /**
     * @brief Set whether the case is sold.
     * @param vendu True if the case is sold, false otherwise.
     */
    void setVendu(bool vendu);

    /**
     * @brief Get the name of the case.
     * @return The name of the case.
     */
    std::string getCaseName() const;

    /**
     * @brief Get the owner of the case.
     * @return A pointer to the owner (Player object), or nullptr if unowned.
     */
    Player* getAcheteur() const;

    /**
     * @brief Set the owner of the case.
     * @param acheteur Pointer to the new owner (Player object).
     */
    void setAcheteur(Player* acheteur);

    /**
     * @brief Add a house to the case.
     */
    void addHouse();

    /**
     * @brief Add a hotel to the case.
     */
    void addMotel();

    /**
     * @brief Get the number of houses on the case.
     * @return The number of houses.
     */
    unsigned int getNumberOfHouse();

    /**
     * @brief Get the number of hotels on the case.
     * @return The number of hotels.
     */
    unsigned int getNumberMotel();

private:
    Couleur m_couleur;                ///< Color group of the case.
    CaseType m_typeCase;              ///< Type of the case.
    unsigned int m_taxe;              ///< Tax value of the case.
    unsigned int m_prix;              ///< Purchase price of the case.
    bool m_achetable;                 ///< Indicates if the case is purchasable.
    bool m_vendu;                     ///< Indicates if the case has been sold.
    Player* m_acheteur;               ///< Pointer to the owner of the case.
    std::string m_caseName;           ///< Name of the case.
    unsigned int m_numberOfHouse;     ///< Number of houses on the case.
    unsigned int m_numberMotel;       ///< Number of hotels on the case.
};

// External declarations
extern Case plateau[TAILLE_PLATEAU];
extern Case Prison;
