#pragma once
#include "Produit.h"
#include "ErreurStockInsuffisant.h"
#include "ErreurArgumentInvalide.h"

class JeuVideo : public Produit {
private:
    std::string genre;
    int stock;
public:
    JeuVideo(const std::string& titre, const std::string& genre, double prix, int stock);

    std::string getGenre() const;
    int getStock() const override;

    void setStock(int nouveauStock) override;
    void setPrix(double nouveauPrix);

    double calculerPrixTTC() const override;
    void afficherDetailsProduit(std::ostream& os) const override;
};