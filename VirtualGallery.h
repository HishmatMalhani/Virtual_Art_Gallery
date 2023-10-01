class VirtualGallery {
private:
    std::vector<Artwork> artworks;
    std::stack<Artwork> artworkStack;
    std::queue<Artwork> artworkQueue;
    std::list<Artwork> artworkLinkedList;
    std::deque<Artwork> artworkDeque;

public:
    void addArtwork(const Artwork& artwork) {
        artworks.push_back(artwork);
    }

    bool removeArtwork(const std::string& artworkTitle) {
        auto it = std::remove_if(artworks.begin(), artworks.end(),
            [&artworkTitle](const Artwork& artwork) {
                return artwork.title == artworkTitle;
            });

        if (it != artworks.end()) {
            artworks.erase(it, artworks.end());
            return true;
        }
        return false;
    }

    bool isEmpty() const {
        return artworks.empty();
    }

    int getNumArtworks() const {
        return artworks.size();
    }

    const std::vector<Artwork>& getArtworks() const {
        return artworks;
    }

    void displayAllArtworks() const {
        std::cout << "Displaying all artworks:\n";
        for (const Artwork& artwork : artworks) {
            artwork.displayDetails();
            std::cout << "-------------------------\n";
        }
    }

    void displayArtworkStack() {
        std::cout << "Displaying artwork stack:\n";
        while (!artworkStack.empty()) {
            artworkStack.top().displayDetails();
            artworkStack.pop();
        }
    }

    void enqueueArtwork(const Artwork& artwork) {
        artworkQueue.push(artwork);
    }

    void displayArtworkQueue() {
        std::cout << "Displaying artwork queue:\n";
        while (!artworkQueue.empty()) {
            artworkQueue.front().displayDetails();
            artworkQueue.pop();
        }
    }

    void displayArtworkLinkedList() {
        std::cout << "Displaying artwork linked list:\n";
        for (const Artwork& artwork : artworkLinkedList) {
            artwork.displayDetails();
        }
    }

    void displayArtworkDeque() {
        std::cout << "Displaying artwork deque:\n";
        while (!artworkDeque.empty()) {
            artworkDeque.front().displayDetails();
            artworkDeque.pop_front();
        }
    }

    void sortByYear() {
        std::sort(artworks.begin(), artworks.end());
    }

    // Save gallery data to a notepad file
    void saveToFile(const std::string& fileName) {
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

    // Load gallery data from a notepad file
    void loadFromFile(const std::string& fileName) {
        artworks.clear();
        std::ifstream inFile(fileName);

        if (!inFile) {
            std::cerr << "Error opening file for reading.\n";
            return;
        }

        int numArtworks;
        inFile >> numArtworks;
        inFile.ignore();

        for (int i = 0; i < numArtworks; ++i) {
            artworks.push_back(Artwork::loadFromFile(inFile));
        }

        inFile.close();
    }
};