#pragma once
#include <string>
#include <iostream>

class Produit {
protected:
    std::string nomProduit;
    double prixBase;
    Produit(const std::string& nom, double prix);
public:
    virtual ~Produit() = default;

    std::string getNomProduit() const;
    double getPrixBase() const;

    virtual double calculerPrixTTC() const = 0;
    virtual void afficherDetailsProduit(std::ostream& os) const = 0;
    virtual void setStock(int nouveauStock) = 0;
    virtual int getStock() const = 0;
};

std::ostream& operator<<(std::ostream& os, const Produit& produit);