class SearchEngine {
private:
    std::vector<Artwork> artworks;

public:
    void setArtworks(const std::vector<Artwork>& _artworks) {
        artworks = _artworks;
    }

    std::vector<Artwork> searchByArtist(const std::string& artistName) {
        std::vector<Artwork> searchResults;
        for (const Artwork& artwork : artworks) {
            if (artwork.artist == artistName) {
                searchResults.push_back(artwork);
            }
        }
        return searchResults;
    }

    std::vector<Artwork> searchByYearRange(int startYear, int endYear) {
        std::vector<Artwork> searchResults;
        for (const Artwork& artwork : artworks) {
            if (artwork.year >= startYear && artwork.year <= endYear) {
                searchResults.push_back(artwork);
            }
        }
        return searchResults;
    }

    std::vector<Artwork> searchByPriceRange(double minPrice, double maxPrice) {
        std::vector<Artwork> searchResults;
        for (const Artwork& artwork : artworks) {
            if (artwork.price >= minPrice && artwork.price <= maxPrice) {
                searchResults.push_back(artwork);
            }
        }
        return searchResults;
    }

    
    // ... Other search methods ...

    // Save search results to a notepad file
    void saveSearchResults(const std::vector<Artwork>& searchResults, const std::string& fileName) {
        std::ofstream outFile(fileName);

        if (!outFile) {
            std::cerr << "Error opening file for writing.\n";
            return;
        }

        outFile << searchResults.size() << "\n";
        for (const Artwork& artwork : searchResults) {
            artwork.saveToFile(outFile);
        }

        outFile.close();
    }
};
