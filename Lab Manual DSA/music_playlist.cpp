// Doubly Linked List:
// 1.Music playlist creation
// -Design a system to keep track of songs in a playlist
// -Song details are represented by nodes in a doubly linked list.
// -Navigate through previous and next song in the list
// -Display the songs according to producer, singer and genre.
// -Other customisations if you want to add

#include <iostream>
#include <string>

using namespace std;

class Song {
public:
    string title;
    string singer;
    string genre;
    Song* next;
    Song* prev;

    Song(string title, string singer, string genre) {
        this->title = title;
        this->singer = singer;
        this->genre = genre;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class Playlist {
public:
    Song* head;
    Song* currentSong;

    Playlist() {
        head = nullptr;
        currentSong = nullptr;
    }

    void addSong(string title, string singer, string genre) {
        Song* newSong = new Song(title, singer, genre);
        if (head == nullptr) {
            head = newSong;
        } else {
            Song* lastSong = head;
            while (lastSong->next != nullptr) {
                lastSong = lastSong->next;
            }
            lastSong->next = newSong;
            newSong->prev = lastSong;
        }
    }

    void removeSong(string title, string singer) {
        if (head == nullptr) {
            cout << "Playlist is empty. Cannot remove a song.\n";
            return;
        }

        Song* currentSong = head;
        while (currentSong != nullptr) {
            if (currentSong->title == title && currentSong->singer == singer) {
                // If the song to be removed is the current song, update currentSong
                if (currentSong == this->currentSong) {
                    this->currentSong = nullptr;
                }

                if (currentSong->prev != nullptr) {
                    currentSong->prev->next = currentSong->next;
                } else {
                    head = currentSong->next;
                }

                if (currentSong->next != nullptr) {
                    currentSong->next->prev = currentSong->prev;
                }

                delete currentSong;
                cout << "Song removed from the playlist successfully!\n";
                return;
            }
            currentSong = currentSong->next;
        }

        cout << "Song not found in the playlist.\n";
    }

    void displayPlaylist() {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        Song* currentSong = head;
        while (currentSong != nullptr) {
            cout << "Title: " << currentSong->title << " | Singer: " << currentSong->singer
                 << " | Genre: " << currentSong->genre << "\n";
            currentSong = currentSong->next;
        }
    }

    void playSong(string songTitle) {
        Song* song = head;
        while (song != nullptr) {
            if (song->title == songTitle) {
                currentSong = song;
                cout << "Now playing: " << currentSong->title << "\n";
                return;
            }
            song = song->next;
        }
        cout << "Song not found in the playlist.\n";
    }

    void navigateForward() {
        if (head == nullptr) {
            cout << "Playlist is empty. Cannot navigate.\n";
            return;
        }

        if (currentSong == nullptr) {
            currentSong = head;
        } else if (currentSong->next != nullptr) {
            currentSong = currentSong->next;
        } else {
            cout << "End of playlist reached. Cannot navigate forward.\n";
            return;
        }

        cout << "Now playing: " << currentSong->title << "\n";
    }

    void navigateBackward() {
        if (head == nullptr) {
            cout << "Playlist is empty. Cannot navigate.\n";
            return;
        }

        if (currentSong == nullptr) {
            currentSong = head;
        } else if (currentSong->prev != nullptr) {
            currentSong = currentSong->prev;
        } else {
            cout << "Beginning of playlist reached. Cannot navigate backward.\n";
            return;
        }

        cout << "Now playing: " << currentSong->title << "\n";
    }

    void displayBySinger(string singer) {
        if (head == nullptr) {
            cout << "Playlist is empty. Cannot display by singer.\n";
            return;
        }

        Song* currentSong = head;
        while (currentSong != nullptr) {
            if (currentSong->singer == singer) {
                cout << "Title: " << currentSong->title << " | Singer: " << currentSong->singer
                     << " | Genre: " << currentSong->genre << "\n";
            }
            currentSong = currentSong->next;
        }
    }

    void displayByGenre(string genre) {
        if (head == nullptr) {
            cout << "Playlist is empty. Cannot display by genre.\n";
            return;
        }

        Song* currentSong = head;
        while (currentSong != nullptr) {
            if (currentSong->genre == genre) {
                cout << "Title: " << currentSong->title << " | Singer: " << currentSong->singer
                     << " | Genre: " << currentSong->genre << "\n";
            }
            currentSong = currentSong->next;
        }
    }

};

int main() {
    Playlist myPlaylist;
    int choice;
    string title, singer, genre, songTitle;

    cout << "\nWelcome to the Music Playlist System!\n";

    do {
        cout << "\n1) Add Song\n";
        cout << "2) Display Playlist\n";
        cout << "3) Play a Song\n";
        cout << "4) Navigate Forward\n";
        cout << "5) Navigate Backward\n";
        cout << "6) Display by Singer\n";
        cout << "7) Display by Genre\n";
        cout << "8) Remove song from playlist\n";
        cout << "9) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: cout << "\nEnter song title: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << "Enter singer: ";
                    getline(cin, singer);
                    cout << "Enter genre: ";
                    getline(cin, genre);
                    myPlaylist.addSong(title, singer, genre);
                    cout << "\nSong added into the playlist successfully!\n";
                    break;
            case 2: cout << "\n---- Displaying Playlist ----\n";
                    myPlaylist.displayPlaylist();
                    break;
            case 3: cout << "\nEnter the song title to play: ";
                    cin.ignore();
                    getline(cin, songTitle);
                    myPlaylist.playSong(songTitle);
                    break;
            case 4: myPlaylist.navigateForward();
                    break;
            case 5: myPlaylist.navigateBackward();
                    break;
            case 6: cout << "\nEnter singer to display songs: ";
                    cin.ignore();
                    getline(cin, singer);
                    cout << "\n---- Displaying by Singer ----\n";
                    myPlaylist.displayBySinger(singer);
                    break;
            case 7: cout << "\nEnter genre to display songs: ";
                    cin.ignore();
                    getline(cin, genre);
                    cout << "\n---- Displaying by Genre ----\n";
                    myPlaylist.displayByGenre(genre);
                    break;
            case 8: cout << "\nEnter song title to delete from playlist: ";
                    getline(cin, songTitle);
                    cout << "Enter singer: ";
                    getline(cin, singer);
                    myPlaylist.removeSong(songTitle, singer);
                    break;
            case 9: cout << "\nExiting Music Playlist System.. Goodbye!\n";
                    break;
            default: 
                    cout << "\nEnter a valid choice!\n";
        }

    } while (choice != 9);

    return 0;
}
