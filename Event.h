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
