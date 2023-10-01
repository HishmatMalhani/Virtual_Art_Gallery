class GalleryDisplay {
private:
    std::vector<Artwork> displayedArtworks;
    std::stack<Artwork> displayedArtworkStack;
    std::queue<Artwork> displayedArtworkQueue;
    std::list<Artwork> displayedArtworkList;
    std::deque<Artwork> displayedArtworkDeque;

public:
    void setDisplayedArtworks(const std::vector<Artwork>& artworks) {
        displayedArtworks = artworks;
    }

    void addToDisplayedArtworkStack(const Artwork& artwork) {
        displayedArtworkStack.push(artwork);
    }

    void displayArtworkStack() {
        std::cout << "Displaying artwork stack:\n";
        while (!displayedArtworkStack.empty()) {
            displayedArtworkStack.top().displayDetails();
            displayedArtworkStack.pop();
        }
    }

    void enqueueDisplayedArtwork(const Artwork& artwork) {
        displayedArtworkQueue.push(artwork);
    }

    void displayArtworkQueue() {
        std::cout << "Displaying artwork queue:\n";
        while (!displayedArtworkQueue.empty()) {
            displayedArtworkQueue.front().displayDetails();
            displayedArtworkQueue.pop();
        }
    }

    void addToDisplayedArtworkList(const Artwork& artwork) {
        displayedArtworkList.push_back(artwork);
    }

    void displayArtworkList() {
        std::cout << "Displaying artwork list:\n";
        for (const Artwork& artwork : displayedArtworkList) {
            artwork.displayDetails();
        }
    }

    void addToDisplayedArtworkDeque(const Artwork& artwork) {
        displayedArtworkDeque.push_back(artwork);
    }

    void displayArtworkDeque() {
        std::cout << "Displaying artwork deque:\n";
        while (!displayedArtworkDeque.empty()) {
            displayedArtworkDeque.front().displayDetails();
            displayedArtworkDeque.pop_front();
        }
    }

    void sortByYear() {
        std::sort(displayedArtworks.begin(), displayedArtworks.end());
    }

    // Save displayed artworks to a notepad file
    void saveToFile(const std::string& fileName) {
        std::ofstream outFile(fileName);

        if (!outFile) {
            std::cerr << "Error opening file for writing.\n";
            return;
        }

        outFile << displayedArtworks.size() << "\n";
        for (const Artwork& artwork : displayedArtworks) {
            artwork.saveToFile(outFile);
        }

        outFile.close();
    }

    // Load displayed artworks from a notepad file
    void loadFromFile(const std::string& fileName) {
        displayedArtworks.clear();
        std::ifstream inFile(fileName);

        if (!inFile) {
            std::cerr << "Error opening file for reading.\n";
            return;
        }

        int numArtworks;
        inFile >> numArtworks;
        inFile.ignore();

        for (int i = 0; i < numArtworks; ++i) {
            displayedArtworks.push_back(Artwork::loadFromFile(inFile));
        }

        inFile.close();
    }
};