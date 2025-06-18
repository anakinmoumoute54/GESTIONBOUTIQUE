#include "Produit.h"

Produit::Produit(const std::string& nom, double prix) : nomProduit(nom), prixBase(prix) {}

std::string Produit::getNomProduit() const { return nomProduit; }
double Produit::getPrixBase() const { return prixBase; }

std::ostream& operator<<(std::ostream& os, const Produit& produit) {
    produit.afficherDetailsProduit(os);
    return os;
}