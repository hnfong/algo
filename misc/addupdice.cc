#include <set>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main() {
    set <int> a[32];
    map<int, string> b[32];
    int n[5];
	int target;
	printf("Input 5 dice numbers:\n");
    scanf("%d %d %d %d %d", n, n+1, n+2, n+3, n+4);
	printf("Target number:\n");
	scanf("%d", &target);
    a[1].insert(n[0]);
    int power = 1;
    char buf[10];
    for (int i = 0; i < 5; i++ )
	{
        sprintf(buf, "%d", n[i]);
        b[power][n[i]]=string(buf);
        a[power].insert(n[i]);
        power <<= 1;
    }
    for (int i = 0; i<5; i++)
	{
        for (int j = 1; j<32; j++)
		{
            for (int k = 1; k<32; k++)
			{
                if (0 == (j & k))
				{
                    for (set<int>::iterator it1 = a[j].begin(); it1 != a[j].end(); it1++)
					{
                        for (set<int>::iterator it2 = a[k].begin(); it2 != a[k].end(); it2++)
						{
                            int x = *it1;
                            int y = *it2;
                            a[j|k].insert(x + y);
                            b[j|k][x+y] = "("+ b[j][x] + " + " + b[k][y] + ")";
                            a[j|k].insert(x - y);
                            b[j|k][x-y] = "("+ b[j][x] + " - " + b[k][y] + ")";
                            a[j|k].insert(x * y);
                            b[j|k][x*y] = "("+ b[j][x] + " * " + b[k][y] + ")";
                            if (0 != y && 0 == x % y)
							{
                                a[j|k].insert(x / y);
                                b[j|k][x/y] = "("+ b[j][x] + " / " + b[k][y] + ")";
                            }
                        }
                    }
                }
            }
        }
    }
    for (set<int>::iterator it = a[31].begin(); it != a[31].end(); it++)
	{
		if (*it == target) {
			printf("%d\n", *it);
			printf("%s\n", b[31][*it].c_str());
		}
    }
    printf("\n");
    return 0;
}

