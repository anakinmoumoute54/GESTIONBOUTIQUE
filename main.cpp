#include <iostream>
#include "Boutique.h"

int main() {
    Boutique boutique;

    std::cout << "Creation de jeux video et de console\n";

    try {
        JeuVideo fc25("FC25", "Sport", 80, 7);
        JeuVideo mariobros("MarioBros", "Aventure", 85, 10);
        Console ps5("PS5", 450, 8);
        Console nintendoSwitch("NintendoSwitch", 300, 15);

        boutique.ajouterJeu(fc25);
        boutique.ajouterJeu(mariobros);
        boutique.ajouterConsole(ps5);
        boutique.ajouterConsole(nintendoSwitch);
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la creation des produits : " << e.what() << '\n';
    }

    boutique.afficherInventaireComplet();

    std::cout << "\nVentes valides \n";
    try {
        boutique.vendreJeu("FC25", 7);
        boutique.vendreConsole("PS5", 8);
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\nTotal produits vendus : " << Boutique::getTotalProduitsVendus() << '\n';
    boutique.afficherInventaireComplet();

    std::cout << "\n Tests de valeurs invalides \n";

    try {
        JeuVideo jeuErreur("ErreurGame", "Test", -10, 1);
    } catch (const ErreurArgumentInvalide& e) {
        std::cerr << "Erreur creation jeu video : " << e.what() << '\n';
    }

    try {
        Console mauvaiseConsole("ErreurConsole", 200, -3);
    } catch (const ErreurStockInsuffisant& e) {
        std::cerr << "Erreur creation console : " << e.what() << '\n';
    }

    std::cout << "\n Tests des mutateurs \n";
    try {
        JeuVideo temp("Temp", "Test", 50, 1);
        temp.setPrix(-25);
    } catch (const ErreurArgumentInvalide& e) {
        std::cerr << "Erreur modification prix : " << e.what() << '\n';
    }

    try {
        Console tempConsole("TempConsole", 150, 5);
        tempConsole.setStock(-2);
    } catch (const ErreurStockInsuffisant& e) {
        std::cerr << "Erreur modification stock : " << e.what() << '\n';
    }

    std::cout << "\n Tests ventes impossibles \n";
    try {
        boutique.vendreJeu("MarioBros", 50);
    } catch (const ErreurStockInsuffisant& e) {
        std::cerr << "Erreur vente MarioBros : " << e.what() << '\n';
    }

    try {
        boutique.vendreConsole("NintendoSwitch", 20);
    } catch (const ErreurStockInsuffisant& e) {
        std::cerr << "Erreur vente NintendoSwitch : " << e.what() << '\n';
    }

    std::cout << "\nFin du test. Merci d'avoir utilise la boutique !" << std::endl;
    return 0;
}