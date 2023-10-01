class User {
public:
    std::string username;
    std::string email;
    std::stack<Artwork> favoriteArtworks;
    std::queue<Artwork> artworkQueue;
    std::list<Artwork> purchasedArtworks;
    std::deque<Artwork> viewedArtworks;

    User(const std::string& _username, const std::string& _email)
        : username(_username), email(_email) {}

    void addFavoriteArtwork(const Artwork& artwork) {
        favoriteArtworks.push(artwork);
    }

    void displayFavoriteArtworks() {
        std::cout << "Displaying favorite artworks:\n";
        std::stack<Artwork> tempStack = favoriteArtworks; // Create a temporary stack to preserve the original
        while (!tempStack.empty()) {
            tempStack.top().displayDetails();
            tempStack.pop();
        }
    }

    void enqueueArtwork(const Artwork& artwork) {
        artworkQueue.push(artwork);
    }

    void displayArtworkQueue() {
        std::cout << "Displaying artwork queue:\n";
        std::queue<Artwork> tempQueue = artworkQueue; // Create a temporary queue to preserve the original
        while (!tempQueue.empty()) {
            tempQueue.front().displayDetails();
            tempQueue.pop();
        }
    }

    void addToPurchasedArtworks(const Artwork& artwork) {
        purchasedArtworks.push_back(artwork);
    }

    void displayPurchasedArtworks() {
        std::cout << "Displaying purchased artworks:\n";
        for (const Artwork& artwork : purchasedArtworks) {
            artwork.displayDetails();
        }
    }

    void addToViewedArtworks(const Artwork& artwork) {
        viewedArtworks.push_back(artwork);
    }

    void displayViewedArtworks() {
        std::cout << "Displaying viewed artworks:\n";
        for (const Artwork& artwork : viewedArtworks) {
            artwork.displayDetails();
        }
    }

    // ... Other methods ...

    bool operator==(const User& other) const {
        return username == other.username;
    }

    // Save user data to a notepad file
    void saveToFile(const std::string& fileName) {
        std::ofstream outFile(fileName);

        if (!outFile) {
            std::cerr << "Error opening file for writing.\n";
            return;
        }

        outFile << username << "\n";
        outFile << email << "\n";
        outFile << favoriteArtworks.size() << "\n";
        std::stack<Artwork> tempFavoriteStack = favoriteArtworks;
        while (!tempFavoriteStack.empty()) {
            tempFavoriteStack.top().saveToFile(outFile);
            tempFavoriteStack.pop();
        }
        outFile << artworkQueue.size() << "\n";
        std::queue<Artwork> tempArtworkQueue = artworkQueue;
        while (!tempArtworkQueue.empty()) {
            tempArtworkQueue.front().saveToFile(outFile);
            tempArtworkQueue.pop();
        }
        outFile << purchasedArtworks.size() << "\n";
        for (const Artwork& artwork : purchasedArtworks) {
            artwork.saveToFile(outFile);
        }
        outFile << viewedArtworks.size() << "\n";
        for (const Artwork& artwork : viewedArtworks) {
            artwork.saveToFile(outFile);
        }

        outFile.close();
    }

    // Load user data from a notepad file
    static User loadFromFile(const std::string& fileName) {
        User user("", "");
        // Load user data from file and populate user's data structures

        return user;
    }
};
