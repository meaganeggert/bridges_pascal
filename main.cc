#include <vector>
#include <iostream>
#include "Bridges.h"
#include "Color.h"
#include "ColorGrid.h"
#include "/public/read.h"
#include <string>

using namespace std;
using namespace bridges;

long long int  pascal(int row, int col, int width,  vector<vector<long long int>> &cash) {

        if (cash.at(row).at(col) == 0) {
        //      if (row == 0) {
        //              cash.at(row).at(col) = 1;
        //      }
                if (col == width or col == width/2 - row or col == width/2 + row) {
                        cash.at(row).at(col) = 1;
                }
                else if (((col == row + 1) or (col == width - row + 1)) and (row != 0)) {
                        cash.at(row).at(col) = row;
                }
                else {
                        long long int temp_calc = (pascal(row-1, col-1, width, cash) + pascal(row - 1, col + 1, width, cash));
                        cash.at(row).at(col) = temp_calc;
                }
                return cash.at(row).at(col);
        }
        else {
                return cash.at(row).at(col);
        }

}

int main() {

    //Bridges
    Bridges *bridges =  new Bridges(3737, "meaganeggert", "1483739998773");
    bridges->setTitle("Pascal Art");
    bridges->setDescription("A visualization of Pascal's triangle");

        int rows = read("How many rows?\n");
        int choice = read("Press 1 for Sunset or 2 for Sunrise: \n");
        int width = rows * 2 - 1;
        int height = rows;
        long long int pascalVal;
        string colour, colour2, colour3, colour4, colour5, colour6, colour7, colour8, colour9;
        vector<vector<long long int>> cache(rows, vector<long long int>(width, 0));



        if (choice == 1) {
                colour = "#03071e"; //navy
        colour2 = "#370617"; // purple
        colour3 = "#6a040f"; //maroon
        colour4 = "#9d0208"; //dark red
        colour5 = "#d00000"; //red
        colour6 = "#dc2f02"; //orange
        colour7 = "#e85d04"; //lightorange
        colour8 = "#f48c06"; //yelloworange
        colour9 = "#ffba08"; //yellow
        }
        else if (choice == 2) {
        colour8 = "#edcba5"; //lightpink
        colour2 = "#81d6e3"; //lighter blue
        colour5 = "#9b4562"; //pink-purple
        colour3 = "#b281ae"; //light-purple
        colour = "#de9521"; //orange
        colour6 = "#f9dc5c"; //yellow
        }
        ColorGrid cg(height, width, Color(colour));

        for (int i = height - 1; i >= 0; i--) {
        for (int j = width/2 - i%2; j >= width/2 - i; j-=2) {
            pascalVal = pascal(i, j, width-1, cache);
//           cout << pascalVal << " ";
        }
                for (int j = width/2 + i; j >= width/2; j-=2) {
                        pascalVal = pascal(i, j, width-1,  cache);
//                      cout << pascalVal << " ";
                }
        }


        //Print out 2d vector
        for (int i = 0; i < height; i++){
                for (int j = 0; j < width; j++) {
                        pascalVal = cache.at(i).at(j);
                        if (pascalVal == 0) {
                                cg.set(i, j, Color(colour));
                        }
                        else {
                                pascalVal = pascalVal % 10;
                                if (pascalVal % 5 == 1) {
                                        cg.set(i, j, Color(colour2));
                                }
                                else if (pascalVal % 5 == 0) {
                                        cg.set(i, j, Color(colour8));
                                }
                                else if (pascalVal % 5 == 2) {
                                        cg.set(i, j, Color(colour5));
                                }
                                else if (pascalVal % 5 == 3) {
                                        cg.set(i, j, Color(colour6));
                                }
                                else {
                                        cg.set(i, j, Color(colour3));
                }
                        }
                //      cout << pascalVal << "  ";
                }
//                      cout << endl;
        }

    bridges->setDataStructure(&cg);

    bridges->visualize();

    delete bridges;

}
