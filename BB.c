int PutHigher(int difficult_layer); // Increase the difficulty by raising the layer
void Clean_BB(int line); // Clear the "BB" row
int check_block_now_put_on_BB(int shape, int form, int x, int y); // Check if the block is on "BB" after placing
int clear_topmost_BOMB_row(int); // New function to clear topmost BOMB row

int PutHigher(int difficult_layer) {
    for (int m = 0; m < (ROW - 2) - difficult_layer; m++) {
        for (int n = 1; n <= (COL - 2); n++) {
            face.data[n][m] = face.data[n][m + 1];
            face.color[n][m] = face.color[n][m + 1];
            
            if (face.data[n][m] == 1) {
                MoveCursor(2 * n, m);
                color(face.color[n][m]);
                printf("■");
               
            }
            if (face.data[n][m] == 2) {
                MoveCursor(2 * n, m);
                color(7);
                printf("■");
              
            }
            if (face.data[n][m] == 3) {
                MoveCursor(2 * n, m);
                color(0);
                printf("BB");
              
            }
			if (face.data[n][m] == 15) {
                MoveCursor(2 * n, m);
                color(8);
                printf("JJ");
              
            }
            if (face.data[n][m] == 0) {
                MoveCursor(2 * n, m);
                printf("  ");
            }
        }
    }
    for (int i = 1; i <= (COL - 2); i++) {
        MoveCursor(2 * i, (ROW - 2) - difficult_layer);
        printf("  ");
    }
    for (int i = 1; i <= (COL - 2); i++) {
        face.data[i][(ROW - 2) - difficult_layer] = 2;
        MoveCursor(2 * i, (ROW - 2) - difficult_layer);
        color(7);
        printf("■");
    }
    int B = rand() % (COL - 2) + 1;
    MoveCursor(2 * B, (ROW - 2) - difficult_layer);
    color(0);
    printf("BB");
    face.data[(ROW - 2) - difficult_layer][B] = 3;
    return difficult_layer++;
}

void Clean_BB(int line) {
    for (int i = 1; i <=(COL - 2); i++) {
        face.data[i][line] = 0;
        MoveCursor(2 * i, line);
        printf("  ");
        usleep(10000);
    }
    for (int m = line; m > 1; m--) {
        for (int n = 1; n <= (COL - 2); n++) {
            face.data[n][m] = face.data[n][m - 1];
            face.color[n][m] = face.color[n][m - 1];
            if (face.data[n][m] == 1) {
                MoveCursor(2 * n, m);
                color(face.color[n][m]);
                printf("■");
            } else if(face.data[n][m] == 15){
				MoveCursor(2 * n, m);
                color(face.color[n][m]);
                printf("JJ");
			} else {
                MoveCursor(2 * n, m);
                printf("  ");
            }
        }
    }
}

int check_block_now_put_on_BB(int shape, int form, int x, int y) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if ((block[shape][form].space[i][j] == 1) && (face.data[x + j][y + i + 1] == 3)) {
                Clean_BB(y + i + 1);
                return 1;
            }
        }
    }
    return 0;
}

int clear_topmost_BOMB_row(int score_threshold) {
    if (grade >= score_threshold) {
        for (int i = 0; i < ROW; i++) {
            int bomb_found = 0;
            for (int j = 1; j < COL - 1; j++) {
                if (face.data[j][i] == 3) {
                    Clean_BB(i);
                    bomb_found = 1;
                    break;
                }
            }
            if (bomb_found) break;
        }
        return score_threshold += 150;
    }
    return score_threshold;
}
