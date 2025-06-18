#pragma once
#include "Produit.h"
#include "ErreurStockInsuffisant.h"
#include "ErreurArgumentInvalide.h"

class Console : public Produit {
private:
    int stock;
public:
    Console(const std::string& nom, double prix, int stock);

    int getStock() const override;
    void setStock(int nouveauStock) override;
    void setPrix(double nouveauPrix);

    double calculerPrixTTC() const override;
    void afficherDetailsProduit(std::ostream& os) const override;
};