class SortManager {
private:
    std::vector<Artwork> artworks;

public:
    void setArtworks(const std::vector<Artwork>& _artworks) {
        artworks = _artworks;
    }

    void sortArtworksByTitle() {
        std::sort(artworks.begin(), artworks.end(), [](const Artwork& a, const Artwork& b) {
            return a.title < b.title;
        });
    }

    void sortArtworksByArtist() {
        std::sort(artworks.begin(), artworks.end(), [](const Artwork& a, const Artwork& b) {
            return a.artist < b.artist;
        });
    }

    void sortArtworksByYear() {
        std::sort(artworks.begin(), artworks.end(), [](const Artwork& a, const Artwork& b) {
            return a.year < b.year;
        });
    }

    void sortArtworksByPrice() {
        std::sort(artworks.begin(), artworks.end(), [](const Artwork& a, const Artwork& b) {
            return a.price < b.price;
        });
    }

    // ... Other sorting methods ...

    // Save sorted artworks to a notepad file
    void saveSortedArtworks(const std::string& fileName) {
        std::ofstream outFile(fileName);

        if (!outFile) {
            std::cerr << "Error opening file for writing.\n";
            return;
        }

        outFile << artworks.size() << "\n";
        for (const Artwork& artwork : artworks) {
            artwork.saveToFile(outFile);
        }

        outFile.close();
    }
};