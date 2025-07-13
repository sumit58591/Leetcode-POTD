#include <bits/stdc++.h>
using namespace std;

int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());
    int i = players.size() - 1, j = trainers.size() - 1;
    int countOutput = 0;
    while(i >= 0 and j >= 0) {
        if(players[i] <= trainers[j]) {
            countOutput++;
            i--; j--;
        } else {
            i--;
        }
    }

    return countOutput;
}

int main() {
    int noOfPlayers;
    cin >> noOfPlayers;
    vector<int> players(noOfPlayers);
    for(int i = 0; i < noOfPlayers; i++) cin >> players[i];
    int noOfTrainers;
    cin >> noOfTrainers;
    vector<int> trainers(noOfTrainers);
    for(int i = 0; i < noOfTrainers; i++) cin >> trainers[i];
    int matchPlayerAndTrainersOutput = matchPlayersAndTrainers(players, trainers);
    cout << matchPlayerAndTrainersOutput << endl;
    return 0;
}