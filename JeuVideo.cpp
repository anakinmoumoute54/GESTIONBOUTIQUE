#include "JeuVideo.h"
#include <iostream>

JeuVideo::JeuVideo(const std::string& titre, const std::string& genre, double prix, int stock)
    : Produit(titre, prix), genre(genre) {
    setPrix(prix);
    setStock(stock);
}

std::string JeuVideo::getGenre() const { return genre; }
int JeuVideo::getStock() const { return stock; }

void JeuVideo::setStock(int nouveauStock) {
    if (nouveauStock < 0) {
        throw ErreurStockInsuffisant(nomProduit, nouveauStock);
    }
    stock = nouveauStock;
}

void JeuVideo::setPrix(double nouveauPrix) {
    if (nouveauPrix < 0) {
        throw ErreurArgumentInvalide("le prix est negatif !");
    }
    prixBase = nouveauPrix;
}

double JeuVideo::calculerPrixTTC() const { return prixBase * 1.20; }

void JeuVideo::afficherDetailsProduit(std::ostream& os) const {
    os << "Titre          : " << nomProduit << '\n'
       << "Genre          : " << genre << '\n'
       << "Prix HT        : " << std::fixed << std::setprecision(2) << prixBase << " eur\n"
       << "Prix TTC (20%) : " << calculerPrixTTC() << " eur\n"
       << "Stock          : " << stock << '\n';
}