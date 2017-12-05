/* gcd.c --  obtain greatest common divisor by Euclidean algorithm */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define USAGE "Usage: Euclid-gcd x y\n"

int gcd(int x, int y) {
	int r = x % y;
	if (r == 0)
		return y;
	else
		return gcd(y, r);
}

int main(int argc, char* argv[]) {
	int opt;
	while ((opt = getopt(argc, argv, "h")) != -1) {
		switch (opt) {
		case 'h':
			printf(USAGE);
			exit(EXIT_SUCCESS);
		}
	}

	if (optind + 1 < argc) {
		int x = atoi(argv[optind]);
		int y = atoi(argv[optind + 1]);
		int res = 0;
		if (x < y)
			res = gcd(y, x);
		else
			res = gcd(x, y);

		printf("gcd(%i,%i)=%i\n", x, y, res);
	} else {
		printf(USAGE);
	}

	return EXIT_SUCCESS;
}
