# include <iostream>
# include <cstdlib>

int main (int argc, char* argv[]) {
	if (argc < 2) {
		std::cerr << "Uso: ./hello  <numero>" << std::endl;
		return 1;
	}

	int numero = std::atoi(argv[1]);

	std::cout << "Hello world " << numero << std::endl;

	return 0;
}

