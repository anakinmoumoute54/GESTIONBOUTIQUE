#include "ErreurStockInsuffisant.h"

ErreurStockInsuffisant::ErreurStockInsuffisant(const std::string& nomProduit, int qte)
    : std::runtime_error("Stock insuffisant pour le produit : " + nomProduit),
      produit(nomProduit), quantite(qte) {}

std::string ErreurStockInsuffisant::getTitreProduit() const { return produit; }
int ErreurStockInsuffisant::getQuantiteDemandee() const { return quantite; }