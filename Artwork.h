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
