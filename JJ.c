int Put_JJ(int joker_active);
int checkjoker();

int Put_JJ(int joker_active){
    if(grade >= 10 && joker_active == 0) { 
        // joker_active = 1;

        for(int m = ROW - 2; m > 0; m--){
            for(int n = 1; n <= COL - 2; n++){
                if(face.data[n][m] == 0 && face.data[n][m - 1] == 1){
                    face.data[n][m] = 15;
                    face.color[n][m] = 8;
                    MoveCursor(2 * n, m);
                    color(8);
                    printf("JJ");
                    return 1;
                }
            }
        }
    }
}

int checkjoker(){
    for(int m = ROW - 2; m > 0; m--){
        for(int n = 1; n <= COL - 2; n++){
            if(face.data[n][m] == 15){
                if(face.data[n][m - 1] == 0){
                    face.data[n][m] = 0;
                    MoveCursor(2 * n, m);
                    printf("  ");
                    return 0;
                }
                return 1;
            }
        }
    }
    return 0;
}
