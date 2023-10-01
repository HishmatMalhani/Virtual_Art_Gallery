#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <deque>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;



class Artwork {
public:
    std::string title;
    std::string artist;
    int year;
    double price;

    Artwork(const std::string& _title, const std::string& _artist, int _year, double _price)
        : title(_title), artist(_artist), year(_year), price(_price) {}

    void displayDetails() const {
        std::cout << "Title: " << title << "\n";
        std::cout << "Artist: " << artist << "\n";
        std::cout << "Year: " << year << "\n";
        std::cout << "Price: $" << price << "\n";
    }

    void saveToFile(std::ofstream& outFile) const {
        outFile << title << "\n";
        outFile << artist << "\n";
        outFile << year << "\n";
        outFile << price << "\n";
    }

    static Artwork loadFromFile(std::ifstream& inFile) {
        std::string title, artist;
        int year;
        double price;

        std::getline(inFile, title);
        std::getline(inFile, artist);
        inFile >> year >> price;
        inFile.ignore(); // Consume newline

        return Artwork(title, artist, year, price);
    }

    bool operator<(const Artwork& other) const {
        return year < other.year;
    }

    bool operator==(const Artwork& other) const {
        return title == other.title && artist == other.artist && year == other.year && price == other.price;
    }
};

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




class FileHandler {
public:
    void saveToFile(const std::string& fileName, const std::string& data) {
        std::ofstream outFile(fileName);
        if (!outFile) {
            std::cerr << "Error opening file for writing.\n";
            return;
        }
        outFile << data;
        outFile.close();
    }

    std::string loadFromFile(const std::string& fileName) {
        std::ifstream inFile(fileName);
        if (!inFile) {
            std::cerr << "Error opening file for reading.\n";
            return "";
        }
        std::string data;
        std::string line;
        while (getline(inFile, line)) {
            data += line + "\n";
        }
        inFile.close();
        return data;
    }
};



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








class Event {
private:
    std::string name;
    std::string date;
    std::string startTime;
    std::string endTime;

public:
    Event(const std::string& _name, const std::string& _date,
          const std::string& _startTime, const std::string& _endTime)
        : name(_name), date(_date), startTime(_startTime), endTime(_endTime) {
        // You can initialize other attributes if needed
    }

    std::string getName() const {
        return name;
    }

    void displayDetails() const {
        std::cout << "Event Name: " << name << "\n";
        std::cout << "Date: " << date << "\n";
        std::cout << "Time: " << startTime << " - " << endTime << "\n";
        // Display other event details
    }
    

    std::string serialize() const {
        std::string serializedData = name + "\n" + date + "\n" + startTime + "\n" + endTime + "\n";
        // Serialize other attributes if needed
        // serializedData += otherAttribute1 + "\n";
        // serializedData += otherAttribute2 + "\n";
        // ...

        return serializedData;
    }

    // Other methods and attributes
};









class EventManager {
private:
    std::deque<Event> events;

public:
    void addEvent(const std::string& name, const std::string& date,
                  const std::string& startTime, const std::string& endTime) {
        Event newEvent(name, date, startTime, endTime);
        events.push_back(newEvent);
    }

    void removeEvent(const std::string& eventName) {
        events.erase(std::remove_if(events.begin(), events.end(),
            [eventName](const Event& event) {
                return event.getName() == eventName;
            }), events.end());
    }

    void displayEvents() const {
        std::cout << "Upcoming Events:\n";
        for (const Event& event : events) {
            event.displayDetails();
        }
    }

    void saveToFile(const std::string& fileName) const {
        std::ofstream outFile(fileName);

        if (!outFile) {
            std::cerr << "Error opening file for writing.\n";
            return;
        }

        for (const Event& event : events) {
            outFile << event.serialize() << "\n";
        }

        outFile.close();
    }

    void loadFromFile(const std::string& fileName) {
    	events.clear();
    	std::ifstream inFile(fileName);

    	if (!inFile) {
        	std::cerr << "Error opening file for reading.\n";
        	return;
    }

    	std::string line;
    	while (std::getline(inFile, line)) {
        Event event(line, "", "", ""); // Assuming line contains event name
        events.push_back(event);
    }

    inFile.close();
	}
};





class UserInterface {
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



int main() {
    // Create User
    User user("John Doe", "john@example.com");

    // Create Artworks
    Artwork artwork1("Mona Lisa", "Leonardo da Vinci", 1503, 1000000.0);
    Artwork artwork2("Starry Night", "Vincent van Gogh", 1889, 800000.0);
    Artwork artwork3("The Persistence of Memory", "Salvador Dali", 1931, 1200000.0);
	Artwork artwork4("Girl with a Pearl Earring", "Johannes Vermeer", 1665, 900000.0);
	Artwork artwork5("The Starry Night", "Vincent van Gogh", 1889, 750000.0);
	Artwork artwork6("The Scream", "Edvard Munch", 1893, 850000.0);
	Artwork artwork7("Mona Lisa", "Leonardo da Vinci", 1503, 3000000.0);
	Artwork artwork8("Water Lilies", "Claude Monet", 1919, 950000.0);
	Artwork artwork9("The Birth of Venus", "Sandro Botticelli", 1484, 1100000.0);
	Artwork artwork10("Guernica", "Pablo Picasso", 1937, 1400000.0);
	Artwork artwork11("American Gothic", "Grant Wood", 1930, 950000.0);
	Artwork artwork12("The Last Supper", "Leonardo da Vinci", 1498, 2500000.0);
	Artwork artwork13("Les Demoiselles d'Avignon", "Pablo Picasso", 1907, 1300000.0);
	Artwork artwork14("The Persistence of Memory", "Salvador Dali", 1931, 1200000.0);
	Artwork artwork15("The Creation of Adam", "Michelangelo", 1512, 1800000.0);
	Artwork artwork16("Impression, Sunrise", "Claude Monet", 1872, 900000.0);
	Artwork artwork17("The Son of Man", "René Magritte", 1964, 950000.0);
	Artwork artwork18("Nighthawks", "Edward Hopper", 1942, 1000000.0);
	Artwork artwork19("Whistler's Mother", "James McNeill Whistler", 1871, 850000.0);
	Artwork artwork20("Campbell's Soup Cans", "Andy Warhol", 1961, 1200000.0);

	

    // Create Virtual Gallery
    VirtualGallery gallery;
    gallery.addArtwork(artwork1);
    gallery.addArtwork(artwork2);
    gallery.addArtwork(artwork3);
    gallery.addArtwork(artwork4);
    gallery.addArtwork(artwork5);
    gallery.addArtwork(artwork6);
    gallery.addArtwork(artwork7);
    gallery.addArtwork(artwork8);
    gallery.addArtwork(artwork9);
    gallery.addArtwork(artwork10);
    gallery.addArtwork(artwork11);
    gallery.addArtwork(artwork12);
    gallery.addArtwork(artwork13);
    gallery.addArtwork(artwork14);
    gallery.addArtwork(artwork15);
    gallery.addArtwork(artwork16);
    gallery.addArtwork(artwork17);
    gallery.addArtwork(artwork18);
    gallery.addArtwork(artwork19);
    gallery.addArtwork(artwork20);
    

    // Create SearchEngine
 	SearchEngine searchEngine;
    searchEngine.setArtworks(gallery.getArtworks());

    // Create SortManager
    SortManager sortManager;

    // Create FileHandler
    FileHandler fileHandler;

    // Create EventManager
    EventManager eventManager;
    eventManager.addEvent("Art Exhibition", "2023-09-01", "10:00 AM", "6:00 PM");
    eventManager.addEvent("Gallery Opening", "2023-09-15", "6:00 PM", "8:00 PM");
	eventManager.addEvent("Artist Meet-and-Greet", "2023-09-20", "3:00 PM", "5:00 PM");
	eventManager.addEvent("Art Workshop", "2023-09-25", "10:00 AM", "1:00 PM");
	eventManager.addEvent("Exhibition Tour", "2023-10-05", "2:00 PM", "3:30 PM");
	eventManager.addEvent("Art Talk: Modern Art Trends", "2023-10-15", "4:00 PM", "6:00 PM");
	eventManager.addEvent("Art Auction", "2023-10-30", "7:00 PM", "10:00 PM");
	eventManager.addEvent("Family Day at the Gallery", "2023-11-05", "11:00 AM", "3:00 PM");
	eventManager.addEvent("Artists' Panel Discussion", "2023-11-15", "5:00 PM", "7:00 PM");
	eventManager.addEvent("Art Film Screening", "2023-11-25", "6:30 PM", "9:00 PM");
	eventManager.addEvent("Gallery Closing Reception", "2023-12-10", "7:00 PM", "9:00 PM");
	eventManager.addEvent("Art Exhibition: Nature's Beauty", "2023-09-10", "10:00 AM", "5:00 PM");
	eventManager.addEvent("Artist Workshop: Acrylic Painting", "2023-09-18", "2:00 PM", "4:00 PM");
	eventManager.addEvent("Gallery Talk: Impressionism", "2023-09-22", "6:30 PM", "7:30 PM");
	eventManager.addEvent("Art Auction: Masterpieces Collection", "2023-09-29", "7:00 PM", "9:00 PM");
	eventManager.addEvent("Art and Wine Evening", "2023-10-08", "7:00 PM", "10:00 PM");
	eventManager.addEvent("Artists' Retreat: Creative Exploration", "2023-10-12", "9:00 AM", "6:00 PM");
	eventManager.addEvent("Gallery Anniversary Celebration", "2023-10-20", "4:00 PM", "8:00 PM");
	eventManager.addEvent("Art Talk: Symbolism in Art", "2023-10-28", "3:00 PM", "5:00 PM");
	eventManager.addEvent("Artistic Photography Workshop", "2023-11-03", "11:00 AM", "2:00 PM");
	eventManager.addEvent("Exhibition Opening: Emerging Artists", "2023-11-12", "5:30 PM", "8:00 PM");
	eventManager.addEvent("Art and Music Night", "2023-11-20", "7:30 PM", "10:00 PM");
	eventManager.addEvent("Gallery Tour: Art Through the Ages", "2023-11-27", "1:00 PM", "3:00 PM");
	eventManager.addEvent("Holiday Art Market", "2023-12-05", "10:00 AM", "6:00 PM");
	eventManager.addEvent("Interactive Sculpture Workshop", "2023-12-15", "3:00 PM", "6:00 PM");



    // Create UserInterface
    UserInterface ui(user, gallery, searchEngine, sortManager, fileHandler, eventManager);
	ui.setUser(user);
	ui.setGallery(gallery);
	ui.setSearchEngine(searchEngine);
	ui.setSortManager(sortManager);
	ui.setFileManager(fileHandler);
	ui.setEventManager(eventManager);

    // Run the user interface
    ui.run();

    // Save events to a file
    eventManager.saveToFile("events.txt");

    // Load events from file
    EventManager loadedEventManager;
    loadedEventManager.loadFromFile("events.txt");

    // Display loaded events
    loadedEventManager.displayEvents();

    return 0;
}
