#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <deque>
#include <algorithm>
#include <fstream>
#include <string>
#include"Artwork.h"
#include"VirtualGallery.h"
#include"User.h"
#include"GalleryDisplay.h"
#include"SearchEngine.h"
#include"FileHandler.h"
#include"SortManager.h"
#include"Event.h"
#include"EventManager.h"
#include"UserInterface.h"
using namespace std;

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

