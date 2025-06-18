#include "Boutique.h"
#include <iostream>

int Boutique::totalProduitsVendus = 0;

void Boutique::incrementerTotalVentes(int quantite) {
    totalProduitsVendus += quantite;
}

int Boutique::getTotalProduitsVendus() {
    return totalProduitsVendus;
}

void Boutique::ajouterJeu(const JeuVideo& jeu) {
    jeux.push_back(jeu);
}

void Boutique::ajouterConsole(const Console& console) {
    consoles.push_back(console);
}

void Boutique::afficherInventaireComplet() const {
    std::cout << "\n================ Inventaire Jeux Video ================\n";
    for (const auto& jeu : jeux) {
        std::cout << jeu << '\n';
    }

    std::cout << "\n================ Inventaire Consoles ==================\n";
    for (const auto& console : consoles) {
        std::cout << console << '\n';
    }
}

void Boutique::vendreJeu(const std::string& titreJeu, int quantite) {
    for (auto& jeu : jeux) {
        if (jeu.getNomProduit() == titreJeu) {
            if (jeu.getStock() < quantite) {
                throw ErreurStockInsuffisant(titreJeu, quantite);
            }
            jeu.setStock(jeu.getStock() - quantite);
            incrementerTotalVentes(quantite);
            std::cout << quantite << " exemplaire(s) de " << titreJeu << " vendu(s).\n";
            return;
        }
    }
    std::cout << "Jeu video non trouve : " << titreJeu << '\n';
}

void Boutique::vendreConsole(const std::string& nomConsole, int quantite) {
    for (auto& console : consoles) {
        if (console.getNomProduit() == nomConsole) {
            if (console.getStock() < quantite) {
                throw ErreurStockInsuffisant(nomConsole, quantite);
            }
            console.setStock(console.getStock() - quantite);
            incrementerTotalVentes(quantite);
            std::cout << quantite << " console(s) " << nomConsole << " vendue(s).\n";
            return;
        }
    }
    std::cout << "Console non trouvee : " << nomConsole << '\n';
}