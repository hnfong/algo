#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef bool glyphs[600][70];
typedef bool character[100][70];
const int W = 100;
const int WW = 600;
const int H = 70;

character alphabet[256];
int black[256];

string valids = "abcdegijklmnopqrstuvwyz";

void dump_glyphs(glyphs &ch, int xoff) {
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < 290; x++) {
            cout << (ch[x + xoff][y] ? "@" : " ");
        }
        cout << "." << endl;
    }

    cout << " _----------------" << endl;
}
void dump_character(character &ch) {
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            cout << (ch[x][y] ? "@" : " ");
        }
        cout << "." << endl;
    }

    cout << " _----------------" << endl;
}

void xor_overlay(glyphs &g, character &ch, int xoff, int yoff) {
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (x+xoff >= 0 && x+xoff < WW && y+yoff >= 0 && y+yoff < H) {
                if (ch[x][y]) {
                    g[x+xoff][y+yoff] = false;
                }
            }
        }
    }
}

int bitcount(glyphs &g, int offx) {
    int ret = 0;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (g[x + offx][y]) { ret ++; }
        }
    }
    return ret;
}

int main() {

    // Read alphabet
    for (int i = 0 ; i < valids.size(); i++) {
        ifstream myfile;
        string filename = "ipsc2016/l/alphabet/" + valids.substr(i,1) + ".in";
        // cout << filename << endl;
        // cout << valids[i] << endl;

        black[valids[i]] = 0;

        myfile.open (filename);
        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                int k;
                myfile >> k;
                // cout << k << " "; 
                alphabet[valids[i]][x][y] = k < 128;
                if (k < 128) black[valids[i]] ++;
            }
        }

        // cout << black[valids[i]] << endl;
        // dump_character(alphabet[valids[i]]);
    }

    // dump_character(alphabet['w']);

    for (int N = 1; N <= 800; N++) {
        char buf[100];
        snprintf(buf, sizeof(buf), "%03d", N);
        ifstream myfile;
        string filename = "ipsc2016/l/l2/" + string(buf) + ".in";
        // cout << filename << endl;
        myfile.open (filename);

        glyphs input;

        for (int y = 0; y < H; y++) {
            for (int x = 0; x < WW; x++) {
                int k;
                myfile >> k;
                // cout << k << " "; 
                input[x][y] = k < 128;
            }
        }

        // dump_glyphs(input, 0);
        cout << filename << " ";

        for (int pos = 0; pos < 6; pos ++) {
            int basex = W * pos;

            double mincount = WW * H;
            int bestx = -1;
            int besty = -1;
            char bestmatch = '*';
            bool found = false;

            for (int i = 0; i < valids.size(); i++) {  // for each character
                glyphs copy;
                memcpy(copy, input, sizeof(copy));

                char ch = valids[i];
                for (int offx = -5; offx < 5; offx++) {  // move around the offsets
                    for (int offy = -2; offy < 2; offy++) {
                        xor_overlay(copy, alphabet[ch], basex + offx, offy);
                    }
                }

                int newcount = bitcount(copy, basex);
                if (newcount < mincount) {
                    // cout << ch << endl;
                    mincount = newcount;
                    bestmatch = ch;
                }
            }
            // cout << "Best match at " << bestx << " " << besty << " as " << bestmatch << " mincount:" << mincount << endl;

hell:
            if (!found) {
                // cerr << "NOT FOUND:" << filename << " pos=" << pos << endl;
            }

            cout << bestmatch;
        }

        cout << endl;
    }

}
