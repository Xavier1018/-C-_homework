#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    // Define variables
    int number;
    int userRating[6] = { 0 }; // Initialize userRating array with 0s
    int ratings[4][6] = {
        {3, 1, 5, 2, 1, 5},
        {4, 2, 1, 4, 2, 4},
        {3, 1, 2, 4, 4, 1},
        {5, 1, 4, 2, 4, 2}
    };

    // Prompt the user to enter ratings for any three movies
    cout << "Enter ratings for any three movies (100-105):" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Movie " << i + 1 << " number: ";
        cin >> number;
        cout << "Rating (1-5): ";
        cin >> userRating[number - 100];
    }

    // Calculate the closest reviewer based on the user's ratings
    int closestReviewer = -1;
    double minDistance = numeric_limits<double>::max(); // Initialize minDistance
    for (int i = 0; i < 4; i++) {
        double distance = 0.0;
        for (int j = 0; j < 6; j++) {
            distance += pow(userRating[j] - ratings[i][j], 2); // Calculate Cartesian distance
        }
        distance = sqrt(distance); // Take the square root to get the final distance
        if (distance < minDistance) { // Check if this reviewer is closer than the previous closest one
            minDistance = distance;
            closestReviewer = i;
        }
    }

    // Predict ratings for movies not rated by the user based on the closest reviewer
    cout << "Predicted ratings for movies not rated by the user:" << endl;
    for (int i = 0; i < 6; i++) {
        if (userRating[i] == 0) { // If the user hasn't rated this movie
            cout << "Movie " << i + 100 << ": " << ratings[closestReviewer][i] << endl; // Output the predicted rating
        }
    }
    return 0;
}





