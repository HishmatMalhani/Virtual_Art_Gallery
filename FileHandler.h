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