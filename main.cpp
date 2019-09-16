#include <iostream>
#include <vector>

using namespace std;

int main() {
    int sizeX, sizeY;
    cin >> sizeX >> sizeY;

    vector<vector<bool>>path(sizeY+1, vector<bool> (sizeX+1,false));

    int posX, posY;
    char direction;

    while (cin >> posX >> posY >> direction) {

        string instructions;
        bool isLost = false;
        cin >> instructions;

        for(auto i : instructions){
            switch(i){
                case 'R':
                    switch(direction){
                        case 'N':
                            direction = 'E';
                            break;
                        case 'E':
                            direction = 'S';
                            break;
                        case 'S':
                            direction = 'W';
                            break;
                        case 'W':
                            direction = 'N';
                            break;
                    }
                    break;
                case 'L':
                    switch (direction){
                        case 'N':
                            direction = 'W';
                            break;
                        case 'E':
                            direction = 'N';
                            break;
                        case 'S':
                            direction = 'E';
                            break;
                        case 'W':
                            direction = 'S';
                            break;
                    }
                    break;
                case 'F':
                    switch (direction){
                        case 'N':
                            ++posY;
                            break;
                        case 'E':
                            ++posX;
                            break;
                        case 'S':
                            --posY;
                            break;
                        case 'W':
                            --posX;
                            break;
                    }
                    break;
            }

            if(posX > sizeX || posY > sizeY || posX < 0 || posY < 0){
                switch (direction){
                    case 'N':
                        --posY;
                        break;
                    case 'E':
                        --posX;
                        break;
                    case 'S':
                        ++posY;
                        break;
                    case 'W':
                        ++posX;
                        break;
                }
                if(path[posX][posY]) continue;
                isLost = true;
                path[posX][posY] = true;
                break;
            }
        }
        cout<< posX << " " << posY <<" "<< direction << (isLost? " LOST":"")<< endl;
    }
    return 0;
}
/*
5 3
1 1 E
RFRFRFRF
3 2 N
FRRFLLFFRRFLL
0 3 W
LLFFFLFLFL
 */