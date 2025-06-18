#include "Console.h"
#include <iomanip>

Console::Console(const std::string& nom, double prix, int stock)
    : Produit(nom, prix) {
    setPrix(prix);
    setStock(stock);
}

int Console::getStock() const { return stock; }

void Console::setStock(int nouveauStock) {
    if (nouveauStock < 0) {
        throw ErreurStockInsuffisant(nomProduit, nouveauStock);
    }
    stock = nouveauStock;
}

void Console::setPrix(double nouveauPrix) {
    if (nouveauPrix < 0) {
        throw ErreurArgumentInvalide("le prix est negatif !");
    }
    prixBase = nouveauPrix;
}

double Console::calculerPrixTTC() const { return prixBase * 1.20; }

void Console::afficherDetailsProduit(std::ostream& os) const {
    os << "Console        : " << nomProduit << '\n'
       << "Prix HT        : " << std::fixed << std::setprecision(2) << prixBase << " eur\n"
       << "Prix TTC (20%) : " << calculerPrixTTC() << " eur\n"
       << "Stock          : " << stock << '\n';
}