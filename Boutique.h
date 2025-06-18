#pragma once
#include <vector>
#include <string>
#include "JeuVideo.h"
#include "Console.h"

class Boutique {
private:
    std::vector<JeuVideo> jeux;
    std::vector<Console> consoles;
    static int totalProduitsVendus;
public:
    static void incrementerTotalVentes(int quantite);
    static int getTotalProduitsVendus();

    void ajouterJeu(const JeuVideo& jeu);
    void ajouterConsole(const Console& console);
    void afficherInventaireComplet() const;

    void vendreJeu(const std::string& titreJeu, int quantite);
    void vendreConsole(const std::string& nomConsole, int quantite);
};