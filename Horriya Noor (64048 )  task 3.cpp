/*Lab Task 3:
In recording scores for a golf tournament, we enter the name and score of the player as the player finishes. This information is to be retrieved in each of the following ways: 
•	Scores and names can be printed in order by ascending or by descending scores. 
•	Given the name of a player, other players with the same score can be printed. 
For that we have to design a structure which keeps the information in a way that each player has information of the player next to it and the one behind it as well.
Implement the above scenario using an appropriate data structure.
 Your Application should do the following

•	Add new Player ( it should insert values in sorted order)
•	Delete a player ( user enters name of player to be deleted)
•	Display 
o	whole list (all players with their scores
o	Display player with lowest scores in the list.
o	Display all those players having same score entered by user.
o	Display Backward  From a player ( it should print data of all the players behind a player)
*/
#include <iostream>
#include <string>
using namespace std;

struct Player {
    string name;
    int score;
    Player* prev;
    Player* next;
};

// Insert player in sorted order (ascending by score)
void addPlayer(Player*& head, string name, int score) {
    Player* newPlayer = new Player{name, score, nullptr, nullptr};

    // Case 1: Empty list
    if (head == nullptr) {
        head = newPlayer;
        return;
    }

    Player* temp = head;

    // Case 2: Insert at beginning
    if (score < head->score) {
        newPlayer->next = head;
        head->prev = newPlayer;
        head = newPlayer;
        return;
    }

    // Case 3: Insert in middle or end
    while (temp->next != nullptr && temp->next->score <= score) {
        temp = temp->next;
    }

    newPlayer->next = temp->next;
    if (temp->next != nullptr) {
        temp->next->prev = newPlayer;
    }
    temp->next = newPlayer;
    newPlayer->prev = temp;
}

// Delete player by name
void deletePlayer(Player*& head, string name) {
    Player* temp = head;

    while (temp != nullptr && temp->name != name) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Player not found!\n";
        return;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;  // deleting head
    }
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout << "Player deleted successfully.\n";
}

// Display all players
void display(Player* head) {
    Player* temp = head;
    cout << "\nPlayers List:\n";
    while (temp != nullptr) {
        cout << temp->name << " (" << temp->score << ")\n";
        temp = temp->next;
    }
}

// Display lowest score player
void displayLowest(Player* head) {
    if (head == nullptr) {
        cout << "No players in list.\n";
        return;
    }
    cout << "Lowest score player: " << head->name << " (" << head->score << ")\n";
}

// Display all players with a given score
void displaySameScore(Player* head, int score) {
    bool found = false;
    Player* temp = head;
    cout << "Players with score " << score << ":\n";
    while (temp != nullptr) {
        if (temp->score == score) {
            cout << temp->name << " (" << temp->score << ")\n";
            found = true;
        }
        temp = temp->next;
    }
    if (!found) cout << "No players with this score.\n";
}

// Display backward from a given player
void displayBackward(Player* head, string name) {
    Player* temp = head;

    while (temp != nullptr && temp->name != name) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Player not found!\n";
        return;
    }

    cout << "Displaying backward from " << temp->name << ":\n";
    while (temp != nullptr) {
        cout << temp->name << " (" << temp->score << ")\n";
        temp = temp->prev;
    }
}

int main() {
    Player* head = nullptr;
    int choice, score;
    string name;

    do {
        cout << "\n--- Golf Tournament Menu ---\n";
        cout << "1. Add New Player\n";
        cout << "2. Delete Player\n";
        cout << "3. Display All Players\n";
        cout << "4. Display Player with Lowest Score\n";
        cout << "5. Display Players with Same Score\n";
        cout << "6. Display Backward from Player\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter player name: ";
                cin >> name;
                cout << "Enter score: ";
                cin >> score;
                addPlayer(head, name, score);
                break;
            case 2:
                cout << "Enter player name to delete: ";
                cin >> name;
                deletePlayer(head, name);
                break;
            case 3:
                display(head);
                break;
            case 4:
                displayLowest(head);
                break;
            case 5:
                cout << "Enter score: ";
                cin >> score;
                displaySameScore(head, score);
                break;
            case 6:
                cout << "Enter player name: ";
                cin >> name;
                displayBackward(head, name);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}