#pragma once
#include <stdexcept>
#include <string>

class ErreurStockInsuffisant : public std::runtime_error {
private:
    std::string produit;
    int quantite;
public:
    ErreurStockInsuffisant(const std::string& nomProduit, int qte);
    std::string getTitreProduit() const;
    int getQuantiteDemandee() const;
};