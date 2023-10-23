/**
 * @author Adem Mavanacı 152120191040
 * @author Beytullah Orhan 152120181042
 * @author Berivan Korlaelçi 152120181019
 * 
 * @file Blobs.cpp
 * @brief This program finds blobs in a matrix and calculates their properties.
 * @details This program reads a matrix of blobs from a file, finds blobs in the matrix, and calculates their properties.
 * The program then displays the matrix of blobs and the results of blob analysis.
 * 
 * 
 * @version 1.0
 * @date 23.10.2023
 * 
 * @note This program was written as an assignment for the course Veri Yapıları Lab I at Eskişehir Osmangazi University in the 2023-2024 Fall semester.
 * 
 */


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>

#define MAX_SIZE 50

using namespace std;

/**
 * @brief A class for processing blobs in a matrix.
 */
class Blobs {
private:
    ifstream dataFile;    ///< Input file stream for reading data from a file.
    string filename;       ///< Name of the input file.
    char** blobs;          ///< 2D array to store the matrix of blobs.
    int* pixels;           ///< Array to store the number of pixels in each blob.
    int* blob_count;       ///< Array to store the count of each blob.
    int rows;              ///< Number of rows in the matrix.
    int cols;              ///< Number of columns in the matrix.
    int num_of_blobs;      ///< Total number of blobs found.
    double* comX;          ///< Array to store the X-coordinate of the center of mass for each blob.
    double* comY;          ///< Array to store the Y-coordinate of the center of mass for each blob.

public:
    Blobs();               ///< Constructor for initializing data members.
    ~Blobs();              ///< Destructor for releasing dynamically allocated memory.
    void readFile();       ///< Reads data from the input file and initializes the matrix.
    void displayMatrix();  ///< Displays the matrix of blobs.
    void findBlobs();      ///< Finds blobs in the matrix and calculates their properties.
    int countPixels(int, int);  ///< Recursively counts the pixels of a blob.
    void displayResults();  ///< Displays the results of blob analysis.
    void centerOfMass(int, double&, double&);  ///< Calculates the center of mass for a blob.
};

/**
 * @brief Constructor for the Blobs class.
 */
Blobs::Blobs() {
    blobs = new char*[MAX_SIZE]; 
    blob_count = new int[MAX_SIZE];
    pixels = new int[MAX_SIZE];
    comX = new double[MAX_SIZE];
    comY = new double[MAX_SIZE];

    for (int i = 0; i < MAX_SIZE; i++) {
        blobs[i] = new char[MAX_SIZE];
    }

    filename = "blobs1.txt";

    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            blobs[i][j] = ' ';
        }
    }
}

/**
 * @brief Destructor for the Blobs class.
 */
Blobs::~Blobs() {
    delete[] pixels;
    delete[] blob_count;
    delete[] comX;
    delete[] comY;
    delete[] blobs;
}

/**
 * @brief Reads data from the input file and initializes the matrix.
 */
void Blobs::readFile() {
    cout << "Please enter filename: ";
    cin >> filename;
    dataFile.open(filename, ios::in);
    cout << endl;

    if (!dataFile) {
        cout << "File failed to open" << endl;
        exit(-1);
    } else {
        cout << "File opened successfully" << endl;

        int i = 0, j, counter = 0;
        string buffer;
        dataFile >> rows >> cols;
        getline(dataFile, buffer);

        while (!dataFile.eof()) {
            getline(dataFile, buffer);
            istringstream iss(buffer);
            iss.seekg(0);

            for (j = 0; j < cols; j++) {
                iss >> noskipws >> blobs[i][j];
            }
            i++;
        }
    }

    dataFile.close();
}

/**
 * @brief Displays the matrix of blobs.
 */
void Blobs::displayMatrix() {
    cout << endl << "BLOBS:" << endl;
    cout << left << setw(2) << " ";
    int count = 0;

    for (int i = 0; i < cols; i++) {
        cout << count;
        count++;

        if (count > 9) {
            count = 0;
        }
    }

    cout << endl << " +";

    for (int i = 0; i < cols; i++) {
        cout << "-";
    }

    cout << "+" << endl;

    for (int i = 0; i < rows; i++) {
        cout << i << "|";

        for (int j = 0; j < cols; j++) {
            cout << blobs[i][j];
        }

        cout << "|" << i;
        cout << endl;
    }

    cout << " +";

    for (int i = 0; i < cols; i++) {
        cout << "-";
    }

    cout << "+" << endl;
    cout << left << setw(2) << " ";
    count = 0;

    for (int i = 0; i < cols; i++) {
        cout << count;
        count++;

        if (count > 9) {
            count = 0;
        }
    }

    cout << endl << endl;
}

/**
 * @brief Finds blobs in the matrix and calculates their properties.
 */
void Blobs::findBlobs() {
    int counter = 0, sum_of_pixels;
    double comx, comy;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum_of_pixels = countPixels(i, j);

            if (sum_of_pixels > 0) {
                centerOfMass(sum_of_pixels, comx, comy);
                pixels[counter] = sum_of_pixels;
                comX[counter] = comx;
                comY[counter] = comy;
                counter++;
            }
        }
    }

    num_of_blobs = counter;
}

/**
 * @brief Recursively counts the pixels of a blob.
 * @param r Row index.
 * @param c Column index.
 * @return The number of pixels in the blob.
 */
int Blobs::countPixels(int r, int c) {
    int sum = 0;

    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        return 0;
    } else if (blobs[r][c] != 'x') {
        return 0;
    } else {
        blobs[r][c] = '#';
        sum = 1 + countPixels(r, c + 1) + countPixels(r, c - 1) + countPixels(r - 1, c) + countPixels(r + 1, c);
        return sum;
    }
}

/**
 * @brief Calculates the center of mass for a blob.
 * @param sum Total number of pixels in the blob.
 * @param comx Reference to the X-coordinate of the center of mass.
 * @param comy Reference to the Y-coordinate of the center of mass.
 */
void Blobs::centerOfMass(int sum, double& comx, double& comy) {
    double countx = 0, county = 0;
    double sumx = 0, sumy = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (blobs[i][j] == '#') {
                countx++;
                blobs[i][j] = '0';
            }
        }

        sumx += countx * i;
        countx = 0;
    }

    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            if (blobs[j][i] == '0') {
                county++;
                blobs[j][i] = ' ';
            }
        }

        sumy += county * i;
        county = 0;
    }

    comx = sumx / sum;
    comy = sumy / sum;
}

/**
 * @brief Displays the results of blob analysis.
 */
void Blobs::displayResults() {
    string blob_number = "BLOB";
    string num_of_pixels = "NoOfPixels";
    string comRow = "comRow";
    string comCol = "comCol";

    for (int i = 0; i < num_of_blobs; i++) {
        blob_count[i] = i + 1;
    }

    cout << endl << "RESULTS:" << endl;
    cout << "+------------+------------+------------+------------+" << endl;
    cout << "| " << left << setw(10) << blob_number << " | ";
    cout << left << setw(13) << num_of_pixels << " | ";
    cout << left << setw(12) << comRow << " | ";
    cout << left << setw(12) << comCol << " |";
    cout << endl << "+------------+------------+------------+------------+" << endl;

    for (int i = 0; i < num_of_blobs; i++) {
        cout << "| " << left << setw(10) << blob_count[i] << " |";
        cout << " " << left << setw(13) << fixed << setprecision(2) << pixels[i] << " |";
        cout << " " << left << setw(12) << fixed << setprecision(2) << comX[i] << " |";
        cout << " " << left << setw(12) << fixed << setprecision(2) << comY[i] << " |";
        cout << endl;
    }

    cout << "+------------+------------+------------+------------+" << endl;
}

/**
 * @brief Main function.
 * @return 0 on successful execution.
 */
int main() {
    Blobs* blob = new Blobs();
    blob->readFile();
    blob->displayMatrix();
    blob->findBlobs();
    blob->displayResults();
    delete blob;
    return 0;
}
