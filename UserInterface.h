class UserInterface{
private:
    User& user;
    VirtualGallery& gallery;
    SearchEngine& searchEngine;
    SortManager& sortManager;
    FileHandler& fileHandler;
    EventManager& eventManager;

public:
    // Constructor that takes all necessary objects as parameters
    UserInterface(User& _user, VirtualGallery& _gallery, SearchEngine& _searchEngine,
                  SortManager& _sortManager, FileHandler& _fileHandler, EventManager& _eventManager)
        : user(_user), gallery(_gallery), searchEngine(_searchEngine),
          sortManager(_sortManager), fileHandler(_fileHandler), eventManager(_eventManager) {
        // Other initialization code, if needed
    }
    void setUser(const User& user) {
        this->user = user;
    }

    void setGallery(const VirtualGallery& gallery) {
        this->gallery = gallery;
    }

    void setSearchEngine(const SearchEngine& searchEngine) {
        this->searchEngine = searchEngine;
    }

    void setSortManager(const SortManager& sortManager) {
        this->sortManager = sortManager;
    }

    void setFileManager(const FileHandler& fileHandler) {
        this->fileHandler = fileHandler;
    }

    void setEventManager(const EventManager& eventManager) {
        this->eventManager = eventManager;
    }

    void searchArtwork() {
        int choice;
        std::cout << "Choose a search method:\n"
                  << "1. Search by artist\n"
                  << "2. Search by year range\n"
                  << "3. Search by price range\n";
        std::cin >> choice;

        if (choice == 1) {
            std::string artistName;
            std::cout << "Enter artist name: ";
            std::cin.ignore();
            std::getline(std::cin, artistName);
            std::vector<Artwork> searchResults = searchEngine.searchByArtist(artistName);

            // Display the search results
            for (const Artwork& artwork : searchResults) {
                artwork.displayDetails();
            }
        } else if (choice == 2) {
            int startYear, endYear;
            std::cout << "Enter start year: ";
            std::cin >> startYear;
            std::cout << "Enter end year: ";
            std::cin >> endYear;
            std::vector<Artwork> searchResults = searchEngine.searchByYearRange(startYear, endYear);

            // Display the search results
            for (const Artwork& artwork : searchResults) {
                artwork.displayDetails();
            }
        } else if (choice == 3) {
            double minPrice, maxPrice;
            std::cout << "Enter minimum price: ";
            std::cin >> minPrice;
            std::cout << "Enter maximum price: ";
            std::cin >> maxPrice;
            std::vector<Artwork> searchResults = searchEngine.searchByPriceRange(minPrice, maxPrice);

            // Display the search results
            for (const Artwork& artwork : searchResults) {
                artwork.displayDetails();
            }
        } else {
            std::cout << "Invalid choice.\n";
        }
    }

    void run() {
        std::cout << "Welcome to the Virtual Art Gallery!\n";

        int choice;
        do {
            std::cout << "1. Display Artworks\n"
                      << "2. Search Artwork\n"
                      << "3. Sort Artworks\n"
                      << "4. View Events\n"
                      << "5. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    displayArtworks();
                    break;
                case 2:
                    searchArtwork();
                    break;
                case 3:
                    sortArtworks();
                    break;
                case 4:
                    viewEvents();
                    break;
                case 5:
                    std::cout << "Exiting the program.\n";
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 5);
    }

    void displayArtworks() {
        gallery.displayAllArtworks();
    }

    void sortArtworks() {
        sortManager.sortArtworksByYear();
        std::cout << "Artworks sorted by year.\n";
    }

    void viewEvents() {
        eventManager.displayEvents();
    }

    // ... Implement other methods ...

};
