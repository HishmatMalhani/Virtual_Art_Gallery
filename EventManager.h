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
